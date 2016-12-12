/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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


#pragma once


// ACF includes
#include <iproc/TSyncProcessorCompBase.h>

// ACF-Solutions includes
#include <iipr/IFeaturesConsumer.h>
#include <iipr/IImageToFeatureProcessor.h>
#include <iblob/IBlobFilterParams.h>


namespace iocv
{


class COcvBlobProcessorComp: public iproc::TSyncProcessorCompBase<iipr::IImageToFeatureProcessor>
{
public:
	typedef iproc::TSyncProcessorCompBase<iipr::IImageToFeatureProcessor> BaseClass;

	I_BEGIN_COMPONENT(COcvBlobProcessorComp);
		I_ASSIGN(m_filterParamsIdAttrPtr, "FilterParamsId", "ID of blob filter parameters in the parameter set (iblob::IBlobFilterParams)", true, "FilterParams");
	I_END_COMPONENT;

	// reimplemented (iipr::IImageToFeatureProcessor)
	virtual int DoExtractFeatures(
				const iprm::IParamsSet* paramsPtr,
				const iimg::IBitmap& image,
				iipr::IFeaturesConsumer& results,
				ibase::IProgressManager* progressManagerPtr = NULL);

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);

protected:
	bool CalculateBlobs(
				const iimg::IBitmap& bitmap,
				const iblob::IBlobFilterParams* filterParamsPtr,
				iipr::IFeaturesConsumer& result);
	static bool IsValueAcceptedByFilter(const iblob::IBlobFilterParams::Filter& filter, double value);

private:
	I_ATTR(QByteArray, m_filterParamsIdAttrPtr);
};


} // namespace iocv


