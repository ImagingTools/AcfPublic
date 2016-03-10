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


#include "ifile/CFileNameParamComp.h"


#if QT_VERSION >= 0x050000
#include <QtCore/QStandardPaths>
#else
#include <QtGui/QDesktopServices>
#endif

// ACF includes
#include "istd/CChangeNotifier.h"
#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace ifile
{


// reimplemented (ifile::IFileNameParam)

int CFileNameParamComp::GetPathType() const
{
	Q_ASSERT(m_pathTypeAttrPtr.IsValid());

	return *m_pathTypeAttrPtr;
}


const QString& CFileNameParamComp::GetPath() const
{
	return m_path;
}


void CFileNameParamComp::SetPath(const QString& path)
{
	if (path != m_path){
		istd::CChangeNotifier notifier(this);

		m_path = path;
	}
}


// reimplemented (iser::ISerializable)

bool CFileNameParamComp::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	QString filePath = m_path;

	static iser::CArchiveTag pathTag("Path", "File path", iser::CArchiveTag::TT_LEAF);
	retVal = retVal && archive.BeginTag(pathTag);
	retVal = retVal && archive.Process(filePath);
	retVal = retVal && archive.EndTag(pathTag);

	if (!archive.IsStoring() && (filePath != m_path)){
		istd::CChangeNotifier notifier(this, &GetAllChanges());
		Q_UNUSED(notifier);

		m_path = filePath;
	}

	return retVal;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CFileNameParamComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_defaultDirAttrPtr.IsValid()){
		m_path = *m_defaultDirAttrPtr;
	}

	if (m_path.contains(s_tempPathVariable)){
		QString tempPath;

#if QT_VERSION < 0x050000
		tempPath = QDesktopServices::storageLocation(QDesktopServices::TempLocation);
#else
		tempPath = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
#endif
		m_path.replace(s_tempPathVariable, tempPath);
	}

	if (m_path.contains(s_appNameVariable)){
		QString applicationName = QCoreApplication::applicationName();
	
		m_path.replace(s_appNameVariable, applicationName);
	}

	if (m_path.contains(s_companyNameVariable)){
		QString organizationName = QCoreApplication::organizationName();
	
		m_path.replace(s_companyNameVariable, organizationName);
	}

	if (m_path.contains(s_publicSharedPathVariable)){
#ifdef Q_OS_WIN
		QString publicSharedFolder("C:/Users/Public");
#else
		QString publicSharedFolder("/Users/Shared");
#endif

		m_path.replace(s_publicSharedPathVariable, publicSharedFolder);
	}
}


// private static members

QString CFileNameParamComp::s_tempPathVariable = "$(TempPath)";
QString CFileNameParamComp::s_appNameVariable = "$(AppName)";
QString CFileNameParamComp::s_companyNameVariable = "$(CompanyName)";
QString CFileNameParamComp::s_publicSharedPathVariable = "$(PublicSharedPath)";


} // namespace ifile


