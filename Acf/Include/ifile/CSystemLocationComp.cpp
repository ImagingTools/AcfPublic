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


#include "ifile/CSystemLocationComp.h"


// Qt includes
#include <QtCore/QDir>
#if QT_VERSION < 0x050000
	#include <QtGui/QDesktopServices>
#else
	#include <QtCore/QStandardPaths>
#endif


namespace ifile
{


// public methods

// reimplemented (ifile::IFileNameParam)

int CSystemLocationComp::GetPathType() const
{
	return PT_DIRECTORY;
}


const QString& CSystemLocationComp::GetPath() const
{
	return m_storagePath;
}


void CSystemLocationComp::SetPath(const QString& /*path*/)
{
	I_CRITICAL();
}


// reimplemented (iser::ISerializable)

bool CSystemLocationComp::Serialize(iser::IArchive& /*archive*/)
{
	return true;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CSystemLocationComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	Q_ASSERT(m_locationTypeAttrPtr.IsValid());

	QString organizationName = QCoreApplication::organizationName();
	if (m_applicationInfoCompPtr.IsValid()){
		organizationName = m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_COMPANY_NAME);
		QString applicationName = m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_APPLICATION_NAME);

		QCoreApplication::setOrganizationName(organizationName);
		QCoreApplication::setApplicationName(applicationName);
	}

	QString organizationNameSubPath;
	if (!organizationName.isEmpty()){
		organizationNameSubPath = QString("/") + organizationName;
	}

#if QT_VERSION < 0x050000
	m_storagePath = QDesktopServices::storageLocation(QDesktopServices::StandardLocation(*m_locationTypeAttrPtr));
#else
	m_storagePath = QStandardPaths::writableLocation(QStandardPaths::StandardLocation(*m_locationTypeAttrPtr));
#endif

	switch (*m_locationTypeAttrPtr){
		case SL_WORKING_DIRECTORY:
			m_storagePath = QDir().absolutePath(); 
			break;

		case SL_EXECUTABLE_DIRECTORY:
			m_storagePath = QCoreApplication::applicationDirPath(); 
			break;

		case SL_EXECUTABLE_FILE:
			m_storagePath = QCoreApplication::applicationFilePath(); 
			break;

		case SL_EXECUTABLE_CONTENT:
			m_storagePath = QCoreApplication::applicationDirPath();
			if (m_storagePath.contains(".app/Contents/MacOS")){
				m_storagePath += "../../";
			}
			break;

		case SL_SHARED_APPDATA_DIRECTORY:
#ifdef Q_OS_WIN
			m_storagePath = QDir::toNativeSeparators(QString("C:/Users/Public") + organizationNameSubPath);
#else
			m_storagePath = QDir::toNativeSeparators(QString("/Users/Shared")  + organizationNameSubPath);
#endif
			break;

		default:
			break;
	}
}


} // namespace ifile


