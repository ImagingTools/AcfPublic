/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
**
**	This file may be used under the terms of the GNU Lesser
**	General Public License version 2.1 as published by the Free Software
**	Foundation and appearing in the file LicenseLGPL.txt included in the
**	packaging of this file.  Please review the following information to
**	ensure the GNU Lesser General Public License version 2.1 requirements
**	will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iqtfpf_CDirectoryMonitorComp_included
#define iqtfpf_CDirectoryMonitorComp_included


// Qt includes
#include <QtCore/QFileSystemWatcher>
#include <QtCore/QFileInfo>
#include <QtCore/QTimer>
#include <QtCore/QThread>
#include <QtCore/QDir>
#include <QtCore/QDateTime>

// ACF includes
#include "imod/TSingleModelObserverBase.h"
#include "icomp/CComponentBase.h"
#include "ibase/TLoggerCompWrap.h"
#include "iqt/CCriticalSection.h"
#include "iprm/IParamsSet.h"
#include "iprm/IFileNameParam.h"

// AcfSln includes
#include "ifpf/IFileSystemChangeStorage.h"
#include "ifpf/IDirectoryMonitor.h"
#include "ifpf/IDirectoryMonitorParams.h"
#include "ifpf/IMonitoringSessionManager.h"


namespace iqtfpf
{


/**
	Component for monitoring of the file folder.
*/
class CDirectoryMonitorComp:
			public QThread,
			public ibase::CLoggerComponentBase,
			virtual public ifpf::IDirectoryMonitor
{
	Q_OBJECT

public:
	typedef ibase::CLoggerComponentBase BaseClass;
	typedef QThread BaseClass2;

	I_BEGIN_COMPONENT(CDirectoryMonitorComp);
		I_REGISTER_INTERFACE(ifpf::IDirectoryMonitor);
		I_ASSIGN(m_paramsSetCompPtr, "ParamsSet", "Default parameter set for the directory monitoring", false, "ParamsSet");
		I_ASSIGN_TO(m_paramsSetModelCompPtr, m_paramsSetCompPtr, false);
		I_ASSIGN(m_monitoringSessionManagerCompPtr, "SessionManager", "Provider of previous monitoring sessions", false, "SessionManager");
		I_ASSIGN(m_fileSystemChangeStorageCompPtr, "FileSystemChangeStorage", "File storage", true, "FileSystemChangeStorage");
		I_ASSIGN(m_directoryPathIdAttrPtr, "DirectoryPathParamsId", "Parameter ID of the path to be observed in the parameter set", true, "DirectoryPathParamsId");
		I_ASSIGN(m_directoryMonitorParamsIdAttrPtr, "DirectoryMonitorParamsId", "ID of the directory observing parameters in the parameter set", true, "DirectoryMonitorParamsId");
		I_ASSIGN(m_autoStartAttrPtr, "AutoStart", "If enabled, start the directory monitoring after initialization", false, false);
	I_END_COMPONENT;

	CDirectoryMonitorComp();

	// reimplemented (ifpf::IDirectoryMonitor)
	virtual bool StartObserving(const iprm::IParamsSet* paramsSetPtr = NULL);
	virtual void StopObserving();

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

	// reimplemented (QThread)
	virtual void run();

private Q_SLOTS:
	/**
		Delegate folder change event via istd::CChangeNotifier from main thread.
	*/
	void OnFolderChanged(int changeFlags);

	/**
		Notification about changes in a given directory.
	*/
	void OnDirectoryChangeNotification(const QString& directory);

Q_SIGNALS:
	/**
		Signal is emitted from observing thread to notifiy the main thread about changes in a directory.
	*/
	void FolderChanged(int changeFlags);

private:
	void SetFolderPath(const QString& folderPath);
	void StartObserverThread();
	void StopObserverThread();
	void ResetFiles();
	bool ConnectToParameterModel(const iprm::IParamsSet& paramsSet);
	void DisconnectFromParameterModel();
	void UpdateMonitoringSession() const;

private:
	struct FileSystemChanges
	{
		QStringList addedFiles;
		QStringList removedFiles;
		QStringList modifiedFiles;
		QStringList attributeChangedFiles;
	};

	class MonitoringParamsObserver: public imod::TSingleModelObserverBase<ifpf::IDirectoryMonitorParams>
	{
	public:
		typedef imod::TSingleModelObserverBase<ifpf::IDirectoryMonitorParams> BaseClass;

		MonitoringParamsObserver(CDirectoryMonitorComp& parent);

		// reimplemented (imod::IObserver)
		virtual void AfterUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);

	private:
		CDirectoryMonitorComp& m_parent;
	};

	class DirectoryParamsObserver: public imod::TSingleModelObserverBase<iprm::IFileNameParam>
	{
	public:
		typedef imod::TSingleModelObserverBase<iprm::IFileNameParam> BaseClass;

		DirectoryParamsObserver(CDirectoryMonitorComp& parent);

		// reimplemented (imod::IObserver)
		virtual void AfterUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);

	private:
		CDirectoryMonitorComp& m_parent;
	};


	typedef std::vector<isys::CFileInfo> FileItems;
	typedef std::set<QString> FilesSet;

	FileItems m_directoryFiles;
	FilesSet m_nonAccessedFiles;

	mutable iqt::CCriticalSection m_lock;

	bool m_finishThread;

	FileSystemChanges m_folderChanges;

	QDir m_currentDirectory;

	int m_directoryPendingChangesCounter;

	QFileSystemWatcher m_directoryWatcher;

	// Model shadows:
	double m_poolingFrequency;
	QStringList m_fileFilterExpressions;
	int m_observingItemTypes;
	int m_observingChanges;

	MonitoringParamsObserver m_monitoringParamsObserver;
	DirectoryParamsObserver m_directoryParamsObserver;

	// Component attributes
	I_REF(iprm::IParamsSet, m_paramsSetCompPtr);
	I_REF(imod::IModel, m_paramsSetModelCompPtr);
	I_REF(ifpf::IMonitoringSessionManager, m_monitoringSessionManagerCompPtr);
	I_REF(ifpf::IFileSystemChangeStorage, m_fileSystemChangeStorageCompPtr);
	I_ATTR(QString, m_directoryPathIdAttrPtr);
	I_ATTR(QString, m_directoryMonitorParamsIdAttrPtr);
	I_ATTR(bool, m_autoStartAttrPtr);

	bool m_lockChanges;
};


} // namespace iqtfpf


#endif // !iqtfpf_CDirectoryMonitorComp_included


