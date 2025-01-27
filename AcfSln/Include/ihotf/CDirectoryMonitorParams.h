/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef ihotf_CDirectoryMonitorParams_included
#define ihotf_CDirectoryMonitorParams_included


// Qt includes
#include <QtCore/QStringList>


// AcfSln includes
#include <ihotf/IDirectoryMonitorParams.h>


namespace ihotf
{


/**
	Implementation of the IDirectoryMonitorParams interface.
*/
class CDirectoryMonitorParams: virtual public ihotf::IDirectoryMonitorParams
{
public:
	CDirectoryMonitorParams();

	// reim�plemented (ihotf::IDirectoryMonitorParams)
	virtual WorkingMode GetWorkingMode() const;
	virtual void SetWorkingMode(WorkingMode workginMode);
	virtual double GetPollingInterval() const;
	virtual void SetPollingInterval(double pollingInterval);
	virtual int GetMinLastModificationTimeDifference() const;
	virtual void SetMinLastModificationTimeDifference(int minLastModificationTimeDifference);
	virtual int GetObservedItemTypes() const;
	virtual void SetObservedItemTypes(int observedItemTypes);
	virtual int GetObservedChanges() const;
	virtual void SetObservedChanges(int observedChanges);
	virtual QStringList GetAcceptPatterns() const;
	virtual void SetAcceptPatterns(const QStringList& acceptPatterns);
	virtual QStringList GetIgnorePatterns() const;
	virtual void SetIgnorePatterns(const QStringList& acceptPatterns);
	virtual int GetFolderDepth() const;
	virtual void SetFolderDepth(int folderDepth);
	virtual int GetFileTimeStampMode() const;
	virtual void SetFileTimeStampMode(int fileTimeStampMode);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	WorkingMode m_workingMode;
	double m_pollingInterval;
	int m_observedItemTypes;
	int m_observedChanges;
	int m_minLastModificationTimeDifference;
	int m_folderDepth;
	int m_fileTimeStampMode;

	QStringList m_acceptPatterns;
	QStringList m_ignorePatterns;
};


} // namespace ihotf


#endif // !ihotf_CDirectoryMonitorParams_included


