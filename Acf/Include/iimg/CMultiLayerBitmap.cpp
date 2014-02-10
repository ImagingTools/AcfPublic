/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#include "iimg/CMultiLayerBitmap.h"


namespace iimg
{


// public methods

// reimplemented (iimg::IMultiLayerBitmap)

void CMultiLayerBitmap::Reset()
{
	BaseClass::ResetPages();
}


iimg::IBitmap* CMultiLayerBitmap::InsertBitmap(
			iimg::IBitmap::PixelFormat pixelFormat, 
			const istd::CIndex2d& size)
{
	iimg::IBitmap* pagePtr = dynamic_cast<iimg::IBitmap*>(BaseClass::InsertPage());
	if (!pagePtr->CreateBitmap(pixelFormat, size)){
		RemovePage(GetPagesCount() - 1);

		return NULL;
	}

	return pagePtr;
}


iimg::IBitmap* CMultiLayerBitmap::InsertBitmap(
			iimg::IBitmap::PixelFormat pixelFormat, 
			const istd::CIndex2d& size, 
			void* dataPtr, 
			bool releaseFlag, 
			int linesDifference /*= 0*/)
{
	iimg::IBitmap* pagePtr = dynamic_cast<iimg::IBitmap*>(BaseClass::InsertPage());
	if (!pagePtr->CreateBitmap(pixelFormat, size, dataPtr, releaseFlag, linesDifference)){
		RemovePage(GetPagesCount() - 1);

		return NULL;
	}

	return pagePtr;
}


void CMultiLayerBitmap::RemoveBitmap(int index)
{
	BaseClass::RemovePage(index);
}


} // namespace iimg


