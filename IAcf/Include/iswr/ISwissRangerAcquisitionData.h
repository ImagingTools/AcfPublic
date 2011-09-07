/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#ifndef iswr_ISwissRangerAcquisitionData_included
#define iswr_ISwissRangerAcquisitionData_included


#include "iimg/IBitmap.h"


namespace iswr
{


/**
	Definition of SwissRanger camera output.
*/
class ISwissRangerAcquisitionData: virtual public iser::ISerializable
{
public:
	/**
		Create image.
	*/
	virtual bool CreateData(
				int maximalDepth,
				const iimg::IBitmap& depthImage,
				const iimg::IBitmap& confidenceMap,
				const iimg::IBitmap& intensityImage,
				const iimg::IBitmap& amplitudeImage,
				const I_SWORD* xBufferPtr,
				const I_SWORD* yBufferPtr) = 0;

	virtual double GetMaxDistance() const = 0;

	/**
		Get depth image.
	*/
	virtual const iimg::IBitmap& GetDepthImage() const = 0;

	/**
		Get 8-bit distance image.
	*/
	virtual const iimg::IBitmap& GetDistanceImage() const = 0;

	/**
		Get confidence map.
	*/
	virtual const iimg::IBitmap& GetConfidenceMap() const = 0;

	/**
		Get intensity image.
	*/
	virtual const iimg::IBitmap& GetIntensityImage() const = 0;

	/**
		Get amplitude image
	*/
	virtual const iimg::IBitmap& GetAmplitudeImage() const = 0;

	/**
		Get X-coordinates buffer. Coordinates are in mm.
	*/
	virtual const I_SWORD* GetXCoordinatesBuffer() const = 0;

	/**
		Get Y-coordinates buffer. Coordinates are in mm.
	*/
	virtual const I_SWORD* GetYCoordinatesBuffer() const = 0;
};


} // namespace iswr


#endif // !iswr_ISwissRangerAcquisitionData_included


