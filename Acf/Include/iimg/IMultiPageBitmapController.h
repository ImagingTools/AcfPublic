/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef iimg_IMultiPageBitmapController_included
#define iimg_IMultiPageBitmapController_included


// ACF includes
#include "iimg/IBitmap.h"


namespace iimg
{


/**
	Interface of a controller for handling multi-page bitmaps.
*/
class IMultiPageBitmapController: virtual public istd::IPolymorphic
{
public:
	/**
		Remove all bitmap pages.
	*/
	virtual void Reset() = 0;


	/**
		Inserts a new bitmap.
		\param	pixelFormat	The pixel format.
		\param	size	Size of the page bitmap.
		\return	null if it fails, else a pointer to the inserted bitmap.
	*/
	virtual iimg::IBitmap* InsertBitmap(
				iimg::IBitmap::PixelFormat pixelFormat,
				const istd::CIndex2d& size) = 0;

	/**
		Inserts a new bitmap.
		
		\param	pixelFormat	   	The pixel format.
		\param	size		   	The size of the page bitmap.
		\param [in,out]	dataPtr	If non-null, the bitmap data pointer.
		\param	releaseFlag	   	Memory controlling flag.
		\param	linesDifference	(Optional) The distance between adjacent lines in bytes.
		
		\return	null if it fails, else a pointer to the inserted bitmap.
	*/
	virtual iimg::IBitmap* InsertBitmap(
				iimg::IBitmap::PixelFormat pixelFormat,
				const istd::CIndex2d& size,
				void* dataPtr,
				bool releaseFlag,
				int linesDifference = 0) = 0;

	/**
		Removes the bitmap at the given index.
		\param	index Index of the bitmap page.
	*/
	virtual void RemoveBitmap(int index) = 0;
};


} // namespace iimg


#endif // iimg_IMultiPageBitmapController_included


