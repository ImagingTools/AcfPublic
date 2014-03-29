/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#include "iqt/CApplicationSettingsProviderComp.h"



namespace iqt
{


// public methods

// reimplemented (iqt::ISettingsProvider)

QSettings& CApplicationSettingsProviderComp::GetSettings() const
{
	Q_ASSERT(m_settingsPtr.IsValid());

	return *m_settingsPtr.GetPtr();
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CApplicationSettingsProviderComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	QString companyName("UnknownCompany");
	QString applicationName("ACF Application");

	if (m_applicationInfoCompPtr.IsValid()){
		companyName = m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_COMPANY_NAME, false);
		applicationName = m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_APPLICATION_NAME, false);
	}

	m_settingsPtr.SetPtr(new QSettings(QSettings::UserScope, companyName, applicationName));
}


} // namespace iqt


