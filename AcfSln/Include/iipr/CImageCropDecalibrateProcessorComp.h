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


#ifndef iipr_CImageCropDecalibrateProcessorComp_included
#define iipr_CImageCropDecalibrateProcessorComp_included


// Qt includes
#include <QtCore/QByteArray>

// ACF includes
#include <iimg/IBitmap.h>
#include <i2d/CRectangle.h>

// ACF-Solutions includes
#include <icalib/CAffineCalibration2d.h>
#include <iproc/TSyncProcessorCompBase.h>


namespace iipr
{


/**
	Crop the image region and rectificate (de-calibrate) it.
*/
class CImageCropDecalibrateProcessorComp: public iproc::CSyncProcessorCompBase
{
public:
	typedef iproc::CSyncProcessorCompBase BaseClass;

	I_BEGIN_COMPONENT(CImageCropDecalibrateProcessorComp);
		I_REGISTER_INTERFACE(iproc::IProcessor);
		I_ASSIGN(m_aoiParamIdAttrPtr, "AoiParamId", "ID of area of interest in parameter set (i2d::CRectangle)", false, "AoiParams");
		I_ASSIGN(m_defaultAoiCompPtr, "DefaultAoi", "Area of interest used if not specified in parameters", false, "DefaultAoi");
		I_ASSIGN(m_cellSizeAttrPtr, "CellSize", "Size of single cell (inside of cell linear interpolation will be used)", true, 8);
	I_END_COMPONENT;

	static bool CropImage(
				const i2d::CRectangle& sourceAoi,
				int cellSize,
				const iimg::IBitmap& inputBitmap,
				iimg::IBitmap& outputBitmap);

	static bool CalcCalibration(
				const i2d::CRectangle& sourceAoi,
				icalib::CAffineCalibration2d& outputCalib);

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);

protected:
	static bool CalcOutputImageSize(
				const i2d::CRectangle& sourceAoi,
				istd::CIndex2d& result);

private:
	I_ATTR(QByteArray, m_aoiParamIdAttrPtr);
	I_REF(i2d::CRectangle, m_defaultAoiCompPtr);
	I_ATTR(int, m_cellSizeAttrPtr);
};


} // namespace iipr


#endif // !iipr_CImageCropDecalibrateProcessorComp_included


