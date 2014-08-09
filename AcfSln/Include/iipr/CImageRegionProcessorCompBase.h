/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#ifndef iipr_CImageRegionProcessorCompBase_included
#define iipr_CImageRegionProcessorCompBase_included


// ACF includes
#include "i2d/ICalibrationProvider.h"
#include "iproc/TSyncProcessorCompBase.h"


namespace i2d
{
	class IObject2d;
}


namespace iimg
{
	class IBitmap;
}


namespace iipr
{


/**
	Basic implementation for a image region processor.
*/
class CImageRegionProcessorCompBase: public iproc::CSyncProcessorCompBase
{
public:
	typedef iproc::CSyncProcessorCompBase BaseClass;

	I_BEGIN_BASE_COMPONENT(CImageRegionProcessorCompBase);
		I_ASSIGN(m_aoiParamIdAttrPtr, "AoiParamId", "ID of the AOI region in the parameter set", true, "AoiParams");
		I_ASSIGN(m_allowEmptyRegionAttrPtr, "AllowEmptyAoi", "If enabled the full image area is used of no AOI was set", true, false);
	I_END_COMPONENT;

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);

protected:
	// abstract methods

	/**
		Process the defined image region.
	*/
	virtual bool ProcessImageRegion(
				const iimg::IBitmap& inputBitmap,
				const iprm::IParamsSet* paramsPtr,
				const i2d::IObject2d* aoiPtr,
				istd::IChangeable* outputPtr) const = 0;

protected:
	I_ATTR(QByteArray, m_aoiParamIdAttrPtr);

private:
	I_ATTR(bool, m_allowEmptyRegionAttrPtr);
};


} // namespace iipr


#endif // !iipr_CImageRegionProcessorCompBase_included


