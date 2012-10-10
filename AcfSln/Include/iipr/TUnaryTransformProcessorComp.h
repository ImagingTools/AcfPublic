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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iipr_TUnaryTransformProcessorComp_included
#define iipr_TUnaryTransformProcessorComp_included


#include <functional>


#include "iipr/CImageProcessorCompBase.h"


namespace iipr
{
	

template <typename ArgumentType>
class InvertFunction: public std::unary_function<ArgumentType, ArgumentType>
{
public:
	InvertFunction()
	{
		m_maxValue = std::numeric_limits<ArgumentType>::max();
	}

	inline ArgumentType operator()(const ArgumentType& value)
	{
		return (m_maxValue - value);
	}

private:
	ArgumentType m_maxValue;
};


/**
	Implementation of general morphological operator.
*/
template <typename PixelType, class Predicate> 
class TUnaryTransformProcessorComp: public iipr::CImageProcessorCompBase
{
public:
	typedef iipr::CImageProcessorCompBase BaseClass;

	I_BEGIN_COMPONENT(TUnaryTransformProcessorComp);
	I_END_COMPONENT;

protected:		
	// reimplemented (iipr::CImageProcessorCompBase)
	virtual bool ProcessImage(
				const iprm::IParamsSet* paramsPtr,
				const iimg::IBitmap& inputImage,
				iimg::IBitmap& outputImage);

private:
	Predicate m_predicate;
};


// reimplemented (iipr::CImageProcessorCompBase)

template <typename PixelType, class Predicate> 
bool TUnaryTransformProcessorComp<PixelType, Predicate>::ProcessImage(
			const iprm::IParamsSet* /*paramsPtr*/,
			const iimg::IBitmap& inputImage,
			iimg::IBitmap& outputImage)
{
	if (!outputImage.CreateBitmap(inputImage.GetPixelFormat(), inputImage.GetImageSize())){
		SendErrorMessage(0, "Output bitmap could not be created");

		return false;	// cannot create output image
	}

	int imageWidth = inputImage.GetImageSize().GetX();
	int imageHeight = inputImage.GetImageSize().GetY();
	int componentsCount = inputImage.GetComponentsCount();

	for (int y = 0; y < imageHeight; y++){
		PixelType* inputImageLinePtr = (PixelType*)inputImage.GetLinePtr(y);
		PixelType* outputImageLinePtr = (PixelType*)outputImage.GetLinePtr(y);

		for (int x = 0; x < imageWidth; x++){
			for (int colorComponentIndex = 0; colorComponentIndex < componentsCount; colorComponentIndex++){
				int pixelOffset = x * componentsCount + colorComponentIndex;

				outputImageLinePtr[pixelOffset] = m_predicate(inputImageLinePtr[pixelOffset]);
			}
		}
	}

	return true;
}


typedef TUnaryTransformProcessorComp<quint8, InvertFunction<quint8> > CInvertOperatorComp;


} // namespace iipr


#endif // !iipr_TUnaryTransformProcessorComp_included


