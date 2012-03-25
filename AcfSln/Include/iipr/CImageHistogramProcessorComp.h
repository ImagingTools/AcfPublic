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


#ifndef iipr_CImageHistogramProcessorComp_included
#define iipr_CImageHistogramProcessorComp_included


// ACF includes
#include "i2d/CRectangle.h"
#include "iimg/IBitmap.h"
#include "iproc/TSyncProcessorCompBase.h"

// ACF-Solutions includes
#include "imeas/IDiscreteDataSequence.h"


namespace iipr
{


/**	
	Implementation of a processor for the image histogram calculation.
*/
class CImageHistogramProcessorComp: public iproc::CSyncProcessorCompBase
{
public:
	typedef iproc::CSyncProcessorCompBase BaseClass;
	
	I_BEGIN_COMPONENT(CImageHistogramProcessorComp);
		I_ASSIGN(m_aoiParamIdAttrPtr, "AoiParamId", "ID of the AOI parameter in the parameter set", false, "AoiParams");
	I_END_COMPONENT;

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				iproc::IProgressManager* progressManagerPtr = NULL);

private:
	bool CalculateHistogramFromBitmap(
					const iimg::IBitmap& input,
					const i2d::IObject2d* aoiPtr,
					imeas::IDiscreteDataSequence& histogram) const;

private:
	I_ATTR(std::string, m_aoiParamIdAttrPtr);
};


} // namespace iipr


#endif // !iipr_CImageHistogramProcessorComp_included

