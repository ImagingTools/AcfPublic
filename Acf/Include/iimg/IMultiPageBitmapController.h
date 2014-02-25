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


#ifndef iimg_IMultiPageBitmapController_included
#define iimg_IMultiPageBitmapController_included


// ACF includes
#include "istd/IPolymorphic.h"


namespace iimg
{


class IMultiPageBitmapController: virtual public istd::IPolymorphic
{
public:
	virtual void Reset() = 0;
	virtual iimg::IBitmap* InsertBitmap(
				iimg::IBitmap::PixelFormat pixelFormat,
				const istd::CIndex2d& size) = 0;
	virtual iimg::IBitmap* InsertBitmap(
				iimg::IBitmap::PixelFormat pixelFormat,
				const istd::CIndex2d& size,
				void* dataPtr,
				bool releaseFlag,
				int linesDifference = 0) = 0;
	virtual void RemoveBitmap(int index) = 0;
};


} // namespace iimg


#endif // iimg_IMultiPageBitmapController_included


