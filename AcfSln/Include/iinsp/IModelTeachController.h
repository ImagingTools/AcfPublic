/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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


#ifndef iinsp_IModelTeachController_included
#define iinsp_IModelTeachController_included


// ACF includes
#include <istd/IChangeable.h>
#include <iprm/IParamsSet.h>


namespace iinsp
{


/**
	Interface for someone controlling teaching of model data.
*/
class IModelTeachController: virtual public istd::IChangeable
{
public:
	/**
		Check of it is possible to teach the model using some parameters.
		\param	modelParams				input model parameters.
		\param	modelDataPtr			optional model data, it can be the same object as \c modelParams.
		\param	beQuiet					indicate that this request is only for model teach without user interactions.
		\param	needUserInteractionPtr	optional placeholder for output flag indicating that user interaction will be requested during teach.
	*/
	virtual bool IsModelTeachable(
				const iprm::IParamsSet& modelParams,
				const iprm::IParamsSet* modelDataPtr = NULL,
				bool beQuiet = false,
				bool* needUserInteractionPtr = NULL) const = 0;
	/**
		Teach the model using some input parameters.
		\param	modelParams	input model parameters.
		\param	result		output model data, it can be the same object as \c modelParams.
		\param	beQuiet		if true, no user interaction is allowed.
		\return	true, if it was possible to teach the model.
	*/
	virtual bool DoModelTeach(
				const iprm::IParamsSet& modelParams,
				iprm::IParamsSet& result,
				bool beQuiet = false) const = 0;

	/**
		Clear all data of the model.
	*/
	virtual void ResetModelData(iprm::IParamsSet& result) const = 0;

	/**
		Check if the model data are valid.
	*/
	virtual bool IsModelDataValid(const iprm::IParamsSet& modelData) const = 0;
};


} // namespace iinsp


#endif // !iinsp_IModelTeachController_included


