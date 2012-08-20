/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "ibase/CQtVersionInfoComp.h"


namespace ibase
{


// reimplemented (iser::IVersionInfo)

iser::IVersionInfo::VersionIds CQtVersionInfoComp::GetVersionIds() const
{
	static IVersionInfo::VersionIds ids;
	if (ids.isEmpty()){
		ids << QVI_COMPILED << QVI_RUNTIME;
	}

	return ids;
}


bool CQtVersionInfoComp::GetVersionNumber(int versionId, quint32& result) const
{
	switch (versionId){
		case QVI_COMPILED:
			result = QT_VERSION;
			return true;

		case QVI_RUNTIME:
			QString qtVersionString = qVersion();
			int major = qtVersionString.mid(0, 1).toInt();
			int minor = qtVersionString.mid(2, 1).toInt();
			int fix = qtVersionString.mid(4, 1).toInt();
			
			result = (major << 16) | (minor << 8) | fix;

			return true;
	}

	return false;
}


QString CQtVersionInfoComp::GetVersionIdDescription(int versionId) const
{
	switch (versionId){
		case QVI_COMPILED:
			return "Created with Qt version";

		case QVI_RUNTIME:
			return "Qt Runtime Version";
	}

	return QString("Wrong Version ID %1").arg(versionId);
}


QString CQtVersionInfoComp::GetEncodedVersionName(int versionId, quint32 /*versionNumber*/) const
{
	switch (versionId){
		case QVI_COMPILED:
			return QT_VERSION_STR;

		case QVI_RUNTIME:
			return qVersion();
	}

	return "Unknown";
}


// reimplemented (ibase::CComponentBase)

void CQtVersionInfoComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (IsVerboseEnabled()){
		SendInfoMessage(QVI_COMPILED, GetVersionIdDescription(QVI_COMPILED) + ": " + GetEncodedVersionName(QVI_COMPILED, 0), "");
		SendInfoMessage(QVI_RUNTIME, GetVersionIdDescription(QVI_RUNTIME) + ": " + GetEncodedVersionName(QVI_RUNTIME, 0), "");
	}
}


} // namespace ibase
