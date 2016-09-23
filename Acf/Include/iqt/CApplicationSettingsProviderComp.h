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


#ifndef iqt_CApplicationSettingsProviderComp_included
#define iqt_CApplicationSettingsProviderComp_included


// ACF includes
#include <icomp/CComponentBase.h>
#include <ibase/IApplicationInfo.h>
#include <iqt/ISettingsProvider.h>


namespace iqt
{

	
/**
	An application settings provider component.

	This component provides access to the application's specific settings object.
*/
class CApplicationSettingsProviderComp: 
			public icomp::CComponentBase,
			virtual public iqt::ISettingsProvider
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CApplicationSettingsProviderComp);
		I_REGISTER_INTERFACE(iqt::ISettingsProvider);
		I_ASSIGN(m_applicationInfoCompPtr, "ApplicationInfo", "Application info", true, "ApplicationInfo");
	I_END_COMPONENT;

	// reimplemented (iqt::ISettingsProvider)
	virtual QSettings& GetSettings() const;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	
private:
	I_REF(ibase::IApplicationInfo, m_applicationInfoCompPtr);

	istd::TDelPtr<QSettings> m_settingsPtr;
};


} // namespace iqt


#endif // !iqt_CApplicationSettingsProviderComp_included


