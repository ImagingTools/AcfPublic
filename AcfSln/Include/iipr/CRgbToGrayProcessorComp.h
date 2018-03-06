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


#ifndef iipr_CRgbToGrayProcessorComp_included
#define iipr_CRgbToGrayProcessorComp_included


// ACF includes
#include <iimg/IBitmap.h>
#include <iipr/CImageProcessorCompBase.h>


namespace iipr
{


/**
	Implementation of a processor for the RGB to Grayscale image conversion.
*/
class CRgbToGrayProcessorComp: public iipr::CImageProcessorCompBase
{
public:
	typedef iipr::CImageProcessorCompBase BaseClass;
	
	I_BEGIN_COMPONENT(CRgbToGrayProcessorComp);
		I_ASSIGN(m_channelWeightsParamsIdAttrPtr, "ChannelWeightsParamId", "ID of the color channel weight parameter in the parameter set", true, "ChannelWeights");
	I_END_COMPONENT;

protected:
	// reimplemented (iipr::CImageProcessorCompBase)
	virtual bool ProcessImage(
				const iprm::IParamsSet* paramsPtr, 
				const iimg::IBitmap& inputImage,
				iimg::IBitmap& outputImage) const override;

private:
	I_ATTR(QByteArray, m_channelWeightsParamsIdAttrPtr);
};


} // namespace iipr


#endif // !iipr_CRgbToGrayProcessorComp_included

