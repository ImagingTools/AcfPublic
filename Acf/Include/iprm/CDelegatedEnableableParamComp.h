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


#pragma once


// ACF includes
#include <imod/CModelUpdateBridge.h>
#include <icomp/CComponentBase.h>
#include <iprm/IEnableableParam.h>


namespace iprm
{


class CDelegatedEnableableParamComp:
			public icomp::CComponentBase,
			public iprm::IEnableableParam
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CDelegatedEnableableParamComp);
		I_REGISTER_INTERFACE(iprm::IEnableableParam);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(istd::IChangeable);
		I_ASSIGN(m_baseEnableableParamCompPtr, "BaseEnabler", "Base enableable parameter", false, "BaseEnabler");
		I_ASSIGN_TO(m_baseEnableableParamModelCompPtr, m_baseEnableableParamCompPtr, false);
	I_END_COMPONENT;

	CDelegatedEnableableParamComp();

protected:
	// reimplemented (iprm::IEnableableParam)
	virtual bool IsEnabled() const override;
	virtual bool IsEnablingAllowed() const override;
	virtual bool SetEnabled(bool isEnabled = true) override;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive) override;

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS) override;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated() override;
	virtual void OnComponentDestroyed() override;

private:
	I_REF(iprm::IEnableableParam, m_baseEnableableParamCompPtr);
	I_REF(imod::IModel, m_baseEnableableParamModelCompPtr);

	imod::CModelUpdateBridge m_updateBridge;
};


} // namespace iprm


