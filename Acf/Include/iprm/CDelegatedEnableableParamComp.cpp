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


#include <iprm/CDelegatedEnableableParamComp.h>


namespace iprm
{



// public methods

CDelegatedEnableableParamComp::CDelegatedEnableableParamComp()
	:m_updateBridge(this, imod::CModelUpdateBridge::UF_SOURCE)
{
}


// protected methods

// reimplemented (iprm::IEnableableParam)

bool CDelegatedEnableableParamComp::IsEnabled() const
{
	if (m_baseEnableableParamCompPtr.IsValid()){
		return m_baseEnableableParamCompPtr->IsEnabled();
	}

	return false;
}


bool CDelegatedEnableableParamComp::IsEnablingAllowed() const
{
	if (m_baseEnableableParamCompPtr.IsValid()){
		return m_baseEnableableParamCompPtr->IsEnablingAllowed();
	}

	return false;
}


bool CDelegatedEnableableParamComp::SetEnabled(bool isEnabled)
{
	if (m_baseEnableableParamCompPtr.IsValid()){
		return m_baseEnableableParamCompPtr->SetEnabled(isEnabled);
	}

	return false;
}


// reimplemented (iser::ISerializable)

bool CDelegatedEnableableParamComp::Serialize(iser::IArchive& archive)
{
	if (m_baseEnableableParamCompPtr.IsValid()){
		return m_baseEnableableParamCompPtr->Serialize(archive);
	}

	// Serialization in this case is optional:
	return true;
}


// reimplemented (istd::IChangeable)

bool CDelegatedEnableableParamComp::CopyFrom(const IChangeable& object, CompatibilityMode mode)
{
	if (m_baseEnableableParamCompPtr.IsValid()){
		return m_baseEnableableParamCompPtr->CopyFrom(object, mode);
	}

	// Copying to a non-existing object is OK:
	return true;
}


// reimplemented (icomp::CComponentBase)

void CDelegatedEnableableParamComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_baseEnableableParamModelCompPtr.IsValid()){
		m_baseEnableableParamModelCompPtr->AttachObserver(&m_updateBridge);
	}
}


void CDelegatedEnableableParamComp::OnComponentDestroyed()
{
	if (m_baseEnableableParamModelCompPtr.IsValid() && m_baseEnableableParamModelCompPtr->IsAttached(&m_updateBridge)){
		m_baseEnableableParamModelCompPtr->DetachObserver(&m_updateBridge);
	}

	BaseClass::OnComponentDestroyed();
}


} // namespace iprm


