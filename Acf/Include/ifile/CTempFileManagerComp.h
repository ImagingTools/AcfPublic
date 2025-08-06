/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#pragma once


// Qt includes
#include <QtCore/QMutex>

// ACF includes
#include <icomp/CComponentBase.h>
#include <ifile/IFileNameParam.h>
#include <ifile/ITempFileManager.h>


namespace ifile
{


/**
	Component implementation of ITempFileManager interface.
*/
class CTempFileManagerComp: public icomp::CComponentBase, virtual public ITempFileManager
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CTempFileManagerComp);
		I_REGISTER_INTERFACE(ITempFileManager);
		I_ASSIGN(m_rootFolderCompPtr, "RootFolder", "Root folder used as a storage for temporary files", false, "RootFolder");
	I_END_COMPONENT;

	// reimplemented (ifile::ITempFileManager)
	virtual QByteArray BeginSession(const QString& subPath = QString(), const QByteArray& proposedSessionId = QByteArray()) override;
	virtual QByteArray AddFileItem(const QByteArray& sessionId, const QString& filePath, const QByteArray& proposedSessionId = QByteArray()) override;
	virtual QString GetPath(const QByteArray& sessionId, const QByteArray& id) const override;
	virtual bool RemoveFileItem(const QByteArray& sessionId, const QByteArray& id) override;
	virtual void FinishSession(const QByteArray& sessionId) override;
	virtual void ResetAllSessions() override;

private:
	I_REF(ifile::IFileNameParam, m_rootFolderCompPtr);

	struct Item
	{
		QByteArray uuid;
		QString path;
	};
	typedef QVector<Item> Items;

	struct Session
	{
		QByteArray id;
		QString basePath;

		Items items;
	};

	typedef QMap<QByteArray, Session> SessionMap;
	SessionMap m_sessionsMap;

	mutable QMutex m_mutex;
};


} // namespace ifile


