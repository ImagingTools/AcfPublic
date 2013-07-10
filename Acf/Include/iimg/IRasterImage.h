/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iimg_IRasterImage_included
#define iimg_IRasterImage_included


// ACF includes
#include "istd/CIndex2d.h"
#include "i2d/IObject2d.h"
#include "icmm/CVarColor.h"


namespace iimg
{


/**
	General definition of image contains pixels in regular grid.
	All pixels are using the same number of color components.
*/
class IRasterImage: virtual public i2d::IObject2d
{
public:
	/**
		Return true if this image is empty.
	*/
	virtual bool IsEmpty() const = 0;

	/**
		Reset this image.
		After this operation image is set to initial state.
	*/
	virtual void ResetImage() = 0;

	/**
		Cleat this image.
		After this operation all the image pixels will be set to the default value (black by default).
	*/
	virtual void ClearImage() = 0;

	/**
		Get size of this raster image.
	*/
	virtual istd::CIndex2d GetImageSize() const = 0;

	/**
		Get number of color components.
	*/
	virtual int GetComponentsCount() const = 0;

	/**
		Get color at specified pixel.
		\param	position	pixel position, must be inside of returned size.
	*/
	virtual icmm::CVarColor GetColorAt(const istd::CIndex2d& position) const = 0;

	/**
		Set color at specified pixel.
		\param	position	pixel position, must be inside of returned size.
		\param	color		color of pixel will be set.
		\return				true, if pixel color was changed.
	*/
	virtual bool SetColorAt(const istd::CIndex2d& position, const icmm::CVarColor& color) = 0;
};


} // namespace iimg


#endif // !iimg_IRasterImage_included


