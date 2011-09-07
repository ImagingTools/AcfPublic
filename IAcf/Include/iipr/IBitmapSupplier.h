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


#ifndef iipr_IBitmapSupplier_included
#define iipr_IBitmapSupplier_included


// ACF includes
#include "i2d/ITransformation2d.h"
#include "iimg/IBitmap.h"
#include "iproc/ISupplier.h"


namespace iipr
{


/**
	Bitmap supplier allowing to access of produced bitmap.
*/
class IBitmapSupplier: virtual public iproc::ISupplier
{
public:
	/**
		Get access to produced bitmap object.
		\return	pointer to bitmap instance if this bitmap is accessible, or NULL.
	*/
	virtual const iimg::IBitmap* GetBitmap() const = 0;

	/**
		Get access to transformation from bitmap to logical positions.
		Please note, not all implementations must support this information.
		\return	pointer to transformation if it is accessible, or NULL.
	*/
	virtual const i2d::ITransformation2d* GetLogTransform() const = 0;
};


} // namespace iipr


#endif // !iipr_IBitmapSupplier_included


