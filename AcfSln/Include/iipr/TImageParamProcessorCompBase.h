/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iipr_TImageParamProcessorCompBase_included
#define iipr_TImageParamProcessorCompBase_included


// ACF includes
#include "iipr/CImageProcessorCompBase.h"


namespace iipr
{


/**
	Basic implementation for a simple bitmap processor.
*/
template <class ParameterType>
class TImageParamProcessorCompBase: public CImageProcessorCompBase
{
public:
	typedef CImageProcessorCompBase BaseClass;

	I_BEGIN_BASE_COMPONENT(TImageParamProcessorCompBase);
		I_ASSIGN(m_paramsIdAttrPtr, "ParamsId", "ID of processor parameters in the parameter set", false, "ParamsId");
	I_END_COMPONENT;

protected:
	// reimplemented (iipr::CImageProcessorCompBase)
	virtual bool ProcessImage(
				const iprm::IParamsSet* paramsPtr, 
				const iimg::IBitmap& inputImage,
				iimg::IBitmap& outputImage);

	// abstract methods
	/**
		Do image processing with some (optional) parameter set.
		\param	parameterPtr	extracted parameter set, it can be NULL.
		\param	inputImage		input image should be processed.
		\param	outputImage		output image, where processing results will be stored.
	*/
	virtual bool ParamProcessImage(
				const ParameterType* parameterPtr, 
				const iimg::IBitmap& inputImage,
				iimg::IBitmap& outputImage) = 0;

private:
	I_ATTR(std::string, m_paramsIdAttrPtr);
};


// public methods

// reimplemented (iipr::CImageProcessorCompBase)

template <class ParameterType>
bool TImageParamProcessorCompBase<ParameterType>::ProcessImage(
			const iprm::IParamsSet* paramsPtr, 
			const iimg::IBitmap& inputImage,
			iimg::IBitmap& outputImage)
{
	const ParameterType* processorParamsPtr = NULL;	
	if ((paramsPtr != NULL) && m_paramsIdAttrPtr.IsValid()){
		processorParamsPtr = dynamic_cast<const ParameterType*>(paramsPtr->GetParameter(*m_paramsIdAttrPtr));
	}
	
	// do image processing:
	return ParamProcessImage(processorParamsPtr, inputImage, outputImage);
}


} // namespace iipr


#endif // !iipr_TImageParamProcessorCompBase_included

