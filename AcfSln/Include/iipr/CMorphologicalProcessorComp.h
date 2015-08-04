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


#ifndef iipr_CMorphologicalProcessorComp_included
#define iipr_CMorphologicalProcessorComp_included


// ACF-Solutions includes
#include "iipr/CImageRegionProcessorCompBase.h"


namespace iipr
{


/**	
	Processor for image cropping.
*/
class CMorphologicalProcessorComp: public CImageRegionProcessorCompBase
{
public:
	typedef CImageRegionProcessorCompBase BaseClass;

	enum ProcessingMode
	{
		PM_EROSION,
		PM_DILATATION,
		PM_OPENING,
		PM_CLOSING
	};
	
	I_BEGIN_COMPONENT(CMorphologicalProcessorComp);
		I_ASSIGN(m_filterSizeParamsIdAttrPtr, "FilterSizeParamsId", "ID of the filter dimension parameter set", true, "FilterSizeParamsId");
		I_ASSIGN(m_processingModeAttrPtr, "ProcessingMode", "Filter processing mode\n0 - Erosion\n1 - Dilatation\n2 - Opening\n3 - Closing", true, 0);
	I_END_COMPONENT;

protected:
	// reimplemented (CImageRegionProcessorCompBase)
	virtual bool ProcessImageRegion(
				const iimg::IBitmap& inputBitmap,
				const iprm::IParamsSet* paramsPtr,
				const i2d::IObject2d* aoiPtr,
				istd::IChangeable* outputPtr) const;
private:
	I_ATTR(QByteArray, m_filterSizeParamsIdAttrPtr);
	I_ATTR(int, m_processingModeAttrPtr);
};


} // namespace iipr


#endif // !iipr_CMorphologicalProcessorComp_included

