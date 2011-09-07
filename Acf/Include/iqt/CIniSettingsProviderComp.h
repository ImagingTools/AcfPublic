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


#ifndef iqt_CIniSettingsProviderComp_included
#define iqt_CIniSettingsProviderComp_included


#include "istd/CString.h"

#include "icomp/CComponentBase.h"

#include "iqt/ISettingsProvider.h"


namespace iqt
{


/**
	Provides settings from INI file.
*/
class CIniSettingsProviderComp: 
			public icomp::CComponentBase,
			public iqt::ISettingsProvider
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CIniSettingsProviderComp);
		I_REGISTER_INTERFACE(iqt::ISettingsProvider);
		I_ASSIGN(m_iniFilePathAttrPtr, "IniFilePath", "Path to INI file", true, "Default.ini");
	I_END_COMPONENT;

	// reimplemented (iqt::ISettingsProvider)
	virtual QSettings& GetSettings() const;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	
private:
	I_ATTR(istd::CString, m_iniFilePathAttrPtr);

	istd::TDelPtr<QSettings> m_settingsPtr;
};


} // namespace iqt


#endif // !iqt_CIniSettingsProviderComp_included


