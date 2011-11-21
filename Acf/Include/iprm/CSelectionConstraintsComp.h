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


#ifndef iprm_CSelectionConstraintsComp_included
#define iprm_CSelectionConstraintsComp_included


#include "iser/ISerializable.h"

#include "icomp/CComponentBase.h"

#include "iprm/ISelectionConstraints.h"


namespace iprm
{


/**
	Implementation of selection constraints.
*/
class CSelectionConstraintsComp:
			public icomp::CComponentBase,
			virtual public iprm::ISelectionConstraints
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CSelectionConstraintsComp);
		I_REGISTER_INTERFACE(istd::IChangeable);
		I_REGISTER_INTERFACE(iprm::ISelectionConstraints);
		I_ASSIGN_MULTI_0(m_optionNamesAttrPtr, "OptionNames", "Names of selectable options", true);
		I_ASSIGN_MULTI_0(m_optionDescriptionsAttrPtr, "OptionDescriptions", "Descriptions of selectable options", true);
	I_END_COMPONENT;

	// reimplemented (iprm::ISelectionConstraints)
	virtual int GetConstraintsFlags() const;
	virtual int GetOptionsCount() const;
	virtual istd::CString GetOptionName(int index) const;
	virtual istd::CString GetOptionDescription(int index) const;
	virtual std::string GetOptionId(int index) const;

private:
	I_MULTIATTR(istd::CString, m_optionNamesAttrPtr);
	I_MULTIATTR(istd::CString, m_optionDescriptionsAttrPtr);
};


} // namespace iprm


#endif // !iprm_CSelectionConstraintsComp_included


