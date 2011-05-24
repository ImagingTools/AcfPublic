/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "ibase/CApplicationInfoComp.h"


#include "istd/Generated/AcfVersion.h"


namespace ibase
{


// public methods

// reimplemented (ibase::IApplicationInfo)

istd::CString CApplicationInfoComp::GetApplicationAttribute(int attributeId) const
{
	switch (attributeId){
	case AA_COMPANY_NAME:
		if (m_companyNameAttrPtr.IsValid()){
			return *m_companyNameAttrPtr;
		}
		break;

	case AA_PRODUCT_NAME:
		if (m_productNameAttrPtr.IsValid()){
			return *m_productNameAttrPtr;
		}
		break;

	case AA_APPLICATION_NAME:
		if (m_applicationNameAttrPtr.IsValid()){
			return *m_applicationNameAttrPtr;
		}
		break;

	case AA_APPLICATION_SUBNAME:
		if (m_applicationSubnameAttrPtr.IsValid()){
			return *m_applicationSubnameAttrPtr;
		}
		break;

	case AA_APPLICATION_TYPE:
		if (m_applicationTypeAttrPtr.IsValid()){
			return *m_applicationTypeAttrPtr;
		}
		break;

	case AA_APPLICATION_PATH:
		return istd::CString(".");
		break;

	case AA_LEGAL_COPYRIGHT:
		if (m_legalCopyrightAttrPtr.IsValid()){
			return *m_legalCopyrightAttrPtr;
		}
		break;
	}

	return "";
}


const iser::IVersionInfo& CApplicationInfoComp::GetVersionInfo() const
{
	if (m_versionInfoCompPtr.IsValid()){
		return *m_versionInfoCompPtr;
	}

	return *this;	// empty version info
}


// public methods

// reimplemented (iser::IVersionInfo)

bool CApplicationInfoComp::GetVersionNumber(int /*versionId*/, I_DWORD& result) const
{
	result = 0xffffffff;

	return false;
}


istd::CString CApplicationInfoComp::GetVersionIdDescription(int /*versionId*/) const
{
	return "";
}


iser::IVersionInfo::VersionIds CApplicationInfoComp::GetVersionIds() const
{
	return iser::IVersionInfo::VersionIds();
}


istd::CString CApplicationInfoComp::GetEncodedVersionName(int /*versionId*/, I_DWORD /*versionNumber*/) const
{
	return "";
}


} // namespace ibase


