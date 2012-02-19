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


#ifndef iprm_TParamsPtr_included
#define iprm_TParamsPtr_included


#include "iprm/IParamsSet.h"


namespace iprm
{


/**
	Help pointer wrapper for management of a parameter from the parameter set.
*/
template <class ParameterInterace>
class TParamsPtr: public istd::TPointerBase<ParameterInterace>
{
public:
	typedef istd::TPointerBase<ParameterInterace> BaseClass;

	TParamsPtr();

	TParamsPtr(const IParamsSet* parameterSetPtr, const std::string& parameterId);

	/**
		Initialize the pointer with the given parameter set and parameter ID.
	*/
	void Init(const IParamsSet* parameterSetPtr, const std::string& parameterId);
};


// public methods

template <class ParameterInterace>
TParamsPtr<ParameterInterace>::TParamsPtr()
	:BaseClass()
{
}


template <class ParameterInterace>
TParamsPtr<ParameterInterace>::TParamsPtr(const IParamsSet* parameterSetPtr, const std::string& parameterId)
{
	Init(parameterSetPtr, parameterId);
}


template <class ParameterInterace>
void TParamsPtr<ParameterInterace>::Init(const IParamsSet* parameterSetPtr, const std::string& parameterId)
{
	BaseClass::Reset();

	if (parameterSetPtr != NULL && !parameterId.empty()){
		const ParameterInterace* parameterPtr = dynamic_cast<const ParameterInterace*>(parameterSetPtr->GetParameter(parameterId));
		if (parameterPtr != NULL){
			BaseClass::SetPtr(const_cast<ParameterInterace*>(parameterPtr));
		}
	}
}


} // namespace iprm


#endif // !iprm_TParamsPtr_included


