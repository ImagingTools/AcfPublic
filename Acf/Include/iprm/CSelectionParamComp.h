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


#ifndef iprm_CSelectionParamComp_included
#define iprm_CSelectionParamComp_included


// ACF includes
#include "icomp/CComponentBase.h"

#include "iprm/ISelectionConstraints.h"
#include "iprm/CSelectionParam.h"


namespace iprm
{


/**
	Component level implementation of selection parameter.
*/
class CSelectionParamComp:
			public icomp::CComponentBase,
			public CSelectionParam
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CSelectionParamComp);
		I_REGISTER_INTERFACE(istd::IChangeable);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(ISelectionParam);
		I_ASSIGN(m_constraintsCompPtr, "Constraints", "Constraints describing allowed value ranges", false, "Constraints");
		I_ASSIGN(m_subselectionCompPtr, "Subselection", "Subselection object", false, "Subselection");
		I_ASSIGN(m_defaultIndexAttrPtr, "DefaultIndex", "Default value of selected index", true, 0);
	I_END_COMPONENT;

	// reimplemented (iprm::ISelectionParam)
	virtual ISelectionParam* GetActiveSubselection() const;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_REF(ISelectionConstraints, m_constraintsCompPtr);
	I_REF(ISelectionParam, m_subselectionCompPtr);
	I_ATTR(int, m_defaultIndexAttrPtr);
};


} // namespace iprm


#endif // !iprm_CSelectionParamComp_included

