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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef ibase_CApplicationInfoComp_included
#define ibase_CApplicationInfoComp_included


#include "iser/IVersionInfo.h"

#include "icomp/CComponentBase.h"

#include "ibase/IApplicationInfo.h"


namespace ibase
{


/**
	Component for providing of application info such as program name, type, copyright text etc.
*/
class CApplicationInfoComp:
			public icomp::CComponentBase,
			virtual public ibase::IApplicationInfo,
			virtual protected iser::IVersionInfo
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CApplicationInfoComp);
		I_REGISTER_INTERFACE(ibase::IApplicationInfo);
		I_ASSIGN(m_companyNameAttrPtr, "CompanyName", "Company name", false, "<my company>");
		I_ASSIGN(m_productNameAttrPtr, "ProductName", "Product name, the same for all applications in one product", false, "<my product>");
		I_ASSIGN(m_applicationNameAttrPtr, "ApplicationName", "Application name", false, "ACF Application");
		I_ASSIGN(m_applicationSubnameAttrPtr, "ApplicationSubname", "Sub-name of application", false, "");
		I_ASSIGN(m_applicationTypeAttrPtr, "ApplicationType", "Application type", false, "Server");
		I_ASSIGN(m_legalCopyrightAttrPtr, "LegalCopyright", "Legal copyright of this application", false, "\x00A9 xxxx <my company>");
		I_ASSIGN(m_mainVersionIdAttrPtr, "MainVersionId", "ID of main module version as defined in version info", false, 0);
		I_ASSIGN(m_versionInfoCompPtr, "VersionInfo", "Provide information about global application version and version of related packages", true, "VersionInfo");
	I_END_COMPONENT;

	// reimplemented (ibase::IApplicationInfo)
	virtual QString GetApplicationAttribute(int attributeId, bool allowTranslation = true) const;
	virtual int GetMainVersionId() const;
	virtual const iser::IVersionInfo& GetVersionInfo() const;

protected:
	// reimplemented (iser::IVersionInfo)
	virtual bool GetVersionNumber(int versionId, quint32& result) const;
	virtual QString GetVersionIdDescription(int versionId) const;
	virtual VersionIds GetVersionIds() const;
	virtual QString GetEncodedVersionName(int versionId, quint32 versionNumber) const;

private:
	I_ATTR(QString, m_companyNameAttrPtr);
	I_ATTR(QString, m_productNameAttrPtr);
	I_ATTR(QString, m_applicationNameAttrPtr);
	I_ATTR(QString, m_applicationSubnameAttrPtr);
	I_ATTR(QString, m_applicationTypeAttrPtr);
	I_ATTR(QString, m_legalCopyrightAttrPtr);
	I_ATTR(int, m_mainVersionIdAttrPtr);
	I_REF(iser::IVersionInfo, m_versionInfoCompPtr);
};


} // namespace ibase


#endif // !ibase_CApplicationInfoComp_included


