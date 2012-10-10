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


#ifndef iprm_CEnableableParamComp_included
#define iprm_CEnableableParamComp_included


// ACF includes
#include "icomp/CComponentBase.h"

#include "iprm/CEnableableParam.h"


namespace iprm
{


class CEnableableParamComp:
			public icomp::CComponentBase,
			public iprm::CEnableableParam
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CEnableableParamComp);
		I_REGISTER_INTERFACE(iprm::IEnableableParam);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(istd::IChangeable);
		I_ASSIGN(m_defaultIsEnabledAttrPtr, "DefaultEnabled", "Default value", true, false);
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(bool, m_defaultIsEnabledAttrPtr);
};


} // namespace iprm


#endif // !iprm_CEnableableParamComp_included


