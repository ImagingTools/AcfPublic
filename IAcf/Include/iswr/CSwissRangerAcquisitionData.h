/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
**
********************************************************************************/


#ifndef iswr_CSwissRangerAcquisitionData_included
#define iswr_CSwissRangerAcquisitionData_included


// ACF includes
#include "istd/CIndex2d.h"
#include "imod/TModelWrap.h"
#include "imath/TISampledFunction.h"
#include "iimg/CGeneralBitmap.h"

#include "iswr/ISwissRangerAcquisitionData.h"


namespace iswr
{


/**
	Parameters od SwissRanger sensor
*/
class CSwissRangerAcquisitionData: virtual public iswr::ISwissRangerAcquisitionData
{
public:
	CSwissRangerAcquisitionData();

	// reimplemented (iswr::ISwissRangerAcquisitionData)
	virtual bool CreateData(
				int maximalDepth,
				const iimg::IBitmap& depthImage,
				const iimg::IBitmap& confidenceMap,
				const iimg::IBitmap& intensityImage,
				const iimg::IBitmap& amplitudeImage,
				const I_SWORD* xBufferPtr,
				const I_SWORD* yBufferPtr);
	virtual double GetMaxDistance() const;
	virtual const iimg::IBitmap& GetDistanceImage() const;
	virtual const iimg::IBitmap& GetDepthImage() const;
	virtual const iimg::IBitmap& GetConfidenceMap() const;
	virtual const iimg::IBitmap& GetIntensityImage() const;
	virtual const iimg::IBitmap& GetAmplitudeImage() const;
	virtual const I_SWORD* GetXCoordinatesBuffer() const;
	virtual const I_SWORD* GetYCoordinatesBuffer() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	mutable imod::TModelWrap<iimg::CGeneralBitmap> m_distanceImage;
	imod::TModelWrap<iimg::CGeneralBitmap> m_depthImage;
	imod::TModelWrap<iimg::CGeneralBitmap> m_confidenceMap;
	imod::TModelWrap<iimg::CGeneralBitmap> m_intensityImage;
	imod::TModelWrap<iimg::CGeneralBitmap> m_amplitudeImage;

	std::vector<I_SWORD> m_xBuffer;
	std::vector<I_SWORD> m_yBuffer;

	int m_maxDepth;
};


} // namespace iswr


#endif // !iswr_CSwissRangerAcquisitionData_included


