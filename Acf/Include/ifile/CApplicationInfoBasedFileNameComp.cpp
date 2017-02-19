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


#include <ifile/CApplicationInfoBasedFileNameComp.h>


namespace ifile
{


// public methods

// reimplemented (ifile::IFileNameParam)

const QString& CApplicationInfoBasedFileNameComp::GetPath() const
{
	QString relativePath = BaseClass::GetPath();

	if (relativePath.contains(s_processIdVariable, Qt::CaseInsensitive)){
		relativePath = relativePath.replace(
					s_processIdVariable,
					QString::number(QCoreApplication::applicationPid()), Qt::CaseInsensitive);
	}

	if (m_applicationInfoCompPtr.IsValid()){
		if (relativePath.contains(s_companyNameVariable, Qt::CaseInsensitive)){
			relativePath = relativePath.replace(
						s_companyNameVariable, 
						m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_COMPANY_NAME), 
						Qt::CaseInsensitive);
		}

		if (relativePath.contains(s_productNameVariable, Qt::CaseInsensitive)){
			relativePath = relativePath.replace(
						s_productNameVariable,
						m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_PRODUCT_NAME),
						Qt::CaseInsensitive);
		}

		if (relativePath.contains(s_applicationNameVariable, Qt::CaseInsensitive)){
			relativePath = relativePath.replace(
						s_applicationNameVariable,
						m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_APPLICATION_NAME),
						Qt::CaseInsensitive);
		}

		if (relativePath.contains(s_applicationSubnameVariable, Qt::CaseInsensitive)){
			relativePath = relativePath.replace(
						s_applicationSubnameVariable,
						m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_APPLICATION_SUBNAME),
						Qt::CaseInsensitive);
		}

		if (relativePath.contains(s_applicationTypeVariable, Qt::CaseInsensitive)){
			relativePath = relativePath.replace(
						s_applicationTypeVariable,
						m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_APPLICATION_TYPE),
						Qt::CaseInsensitive);
		}

		if (relativePath.contains(s_mainVersionVariable, Qt::CaseInsensitive)){
			relativePath = relativePath.replace(
						s_mainVersionVariable,
						m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_MAIN_VERSION),
						Qt::CaseInsensitive);
		}

		if (relativePath.contains(s_userVariable, Qt::CaseInsensitive)){
			relativePath = relativePath.replace(
						s_userVariable,
						m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_USER),
						Qt::CaseInsensitive);
		}
	}

	m_calculatedPath = relativePath;

	return m_calculatedPath;
}


QString CApplicationInfoBasedFileNameComp::s_processIdVariable = "$(PROCESS_ID)";
QString CApplicationInfoBasedFileNameComp::s_companyNameVariable = "$(COMPANY_NAME)";
QString CApplicationInfoBasedFileNameComp::s_productNameVariable = "$(PRODUCT_NAME)";
QString CApplicationInfoBasedFileNameComp::s_applicationNameVariable = "$(APPLICATION_NAME)";
QString CApplicationInfoBasedFileNameComp::s_applicationSubnameVariable = "$(APPLICATION_SUBNAME)";
QString CApplicationInfoBasedFileNameComp::s_applicationTypeVariable = "$(APPLICATION_TYPE)";
QString CApplicationInfoBasedFileNameComp::s_mainVersionVariable = "$(MAIN_VERSION)";
QString CApplicationInfoBasedFileNameComp::s_userVariable = "$(USER)";


} // namespace ifile


