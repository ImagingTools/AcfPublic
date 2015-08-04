/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#include "ibase/CQtVersionInfoComp.h"


namespace ibase
{


// reimplemented (iser::IVersionInfo)

iser::IVersionInfo::VersionIds CQtVersionInfoComp::GetVersionIds() const
{
	IVersionInfo::VersionIds ids = BaseClass::GetVersionIds();

	ids << VI_QT_VERSION;

	return ids;
}


bool CQtVersionInfoComp::GetVersionNumber(int versionId, quint32& result) const
{
	switch (versionId){
		case VI_QT_VERSION:
			result = QT_VERSION;
			return true;
	}

	return BaseClass::GetVersionNumber(versionId, result);
}


QString CQtVersionInfoComp::GetVersionIdDescription(int versionId) const
{
	switch (versionId){
		case VI_QT_VERSION:
			return "Qt Framework";
	}

	return BaseClass::GetVersionIdDescription(versionId);
}


QString CQtVersionInfoComp::GetEncodedVersionName(int versionId, quint32 versionNumber) const
{
	switch (versionId){
		case VI_QT_VERSION:
			return QT_VERSION_STR;
	}

	return BaseClass::GetEncodedVersionName(versionId, versionNumber);
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CQtVersionInfoComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (QT_VERSION != GetRuntimeVersion()){
		SendWarningMessage(0, QObject::tr("The runtime version of Qt framework doesn't match the version used by creation of ACF"));
	}
}



// private static methods

quint32 CQtVersionInfoComp::GetRuntimeVersion()
{
	QString qtVersionString = qVersion();
	int major = qtVersionString.mid(0, 1).toInt();
	int minor = qtVersionString.mid(2, 1).toInt();
	int fix = qtVersionString.mid(4, 1).toInt();
			
	return (major << 16) | (minor << 8) | fix;
}


} // namespace ibase
