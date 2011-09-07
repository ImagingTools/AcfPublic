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


#include "iprm/CEnableableParamComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"

#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace iprm
{


// reimplemented (istd::IEnableable)

bool CEnableableParamComp::IsEnabled() const
{
	return m_isEnabled;
}


bool CEnableableParamComp::IsEnablingAllowed() const
{
	return true;
}


void CEnableableParamComp::SetEnabled(bool isEnabled)
{
	if (isEnabled != m_isEnabled){
		istd::CChangeNotifier notifier(this);

		m_isEnabled = isEnabled;
	}
}


// reimplemented (iser::ISerializable)

bool CEnableableParamComp::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	static iser::CArchiveTag isEnabledTag("IsEnabled", "Flag if element is enabled");
	retVal = retVal && archive.BeginTag(isEnabledTag);
	retVal = retVal && archive.Process(m_isEnabled);
	retVal = retVal && archive.EndTag(isEnabledTag);

	return retVal;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CEnableableParamComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_defaultIsEnabledAttrPtr.IsValid()){
		m_isEnabled = *m_defaultIsEnabledAttrPtr;
	}
}


} // namespace iprm


