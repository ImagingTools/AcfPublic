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


#ifndef iipr_CImageBinarizeProcessorComp_included
#define iipr_CImageBinarizeProcessorComp_included


// ACF includes
#include <iimg/IBitmap.h>
#include <iproc/TSyncProcessorCompBase.h>

// ACF-Solutions includes
#include <imeas/INumericValue.h>


namespace iipr
{


/**	
	Processor for image binarization using static threshold.
*/
class CImageBinarizeProcessorComp: public iproc::CSyncProcessorCompBase
{
public:
	typedef iproc::CSyncProcessorCompBase BaseClass;
	
	I_BEGIN_COMPONENT(CImageBinarizeProcessorComp);
		I_ASSIGN(m_binarizationParamsIdAttrPtr, "BinarizationParameterId", "ID of binarization parameters in the parameter set", false, "BinarizationParameterId");
		I_ASSIGN(m_defaultBinarizationThresholdCompPtr, "DefaultThreshold", "Default value of the binarization threshold", false, "DefaultThreshold");
		I_ASSIGN(m_isInverseModeEnabledAttrPtr, "InverseMode", "If enabled, object color will be set to 0", true, false);
	I_END_COMPONENT;

	// reimplemented (iproc::IProcessor)
	virtual iproc::IProcessor::TaskState DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL) override;

private:
	bool ConvertImage(
				const iimg::IBitmap& inputBitmap,
				const imeas::INumericValue& thresholdParams,
				iimg::IBitmap& outputBitmap) const;

private:
	I_ATTR(QByteArray, m_binarizationParamsIdAttrPtr);
	I_REF(imeas::INumericValue, m_defaultBinarizationThresholdCompPtr);
	I_ATTR(bool, m_isInverseModeEnabledAttrPtr);
};


} // namespace iipr


#endif // !iipr_CImageBinarizeProcessorComp_included

