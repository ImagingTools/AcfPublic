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


#ifndef iipr_IMultiBitmapSupplier_included
#define iipr_IMultiBitmapSupplier_included


// ACF includes
#include "iimg/IBitmap.h"
#include "iproc/ISupplier.h"
#include "i2d/ITransformation2d.h"


namespace iipr
{


/**
	Supplier allowing to access of multiple produced bitmap.
*/
class IMultiBitmapSupplier: virtual public iproc::ISupplier
{
public:
	/**
		Get number of produced bitmaps.
	*/
	virtual int GetBitmapsCount() const = 0;
	/**
		Get access to produced bitmap object.
		\return	pointer to bitmap instance if this bitmap is accessible, or NULL.
	*/
	virtual const iimg::IBitmap* GetBitmap(int bitmapIndex) const = 0;

	/**
		Get access to transformation from bitmap to logical positions.
		Please note, not all implementations must support this information.
		\return	pointer to transformation if it is accessible, or NULL.
	*/
	virtual const i2d::ITransformation2d* GetLogTransform(int bitmapIndex) const = 0;
};


} // namespace iipr


#endif // !iipr_IMultiBitmapSupplier_included


