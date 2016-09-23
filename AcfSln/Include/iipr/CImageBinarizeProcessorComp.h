/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
	I_END_COMPONENT;

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);

private:
	bool ConvertImage(
				const iimg::IBitmap& inputBitmap,
				const imeas::INumericValue& thresholdParams,
				iimg::IBitmap& outputBitmap) const;

private:
	I_ATTR(QByteArray, m_binarizationParamsIdAttrPtr);
};


} // namespace iipr


#endif // !iipr_CImageBinarizeProcessorComp_included

