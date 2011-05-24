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


#ifndef iproc_IValueSupplier_included
#define iproc_IValueSupplier_included


#include "imath/CVarVector.h"

#include "iproc/ISupplier.h"


namespace iproc
{


/**
	2D vector or position supplier.
*/
class IValueSupplier: virtual public ISupplier
{
public:
	/**
		Define standard value types.
	*/
	enum ValueTypeId
	{
		/**
			Automatic value, implementation specific.
		*/
		VTI_AUTO = 0,
		/**
			Value of position (2D or 3D).
		*/
		VTI_POSITION,
		/**
			Value of radius.
		*/
		VTI_RADIUS,
		/**
			Quality factor.
			This value should be normalized to range [0, 1].
		*/
		VTI_QUALITY,
		/**
			Angle in radian.
		*/
		VTI_ANGLE,
		/**
			Length or distance.
		*/
		VTI_LENGTH,
	};

	/**
		Get access to produced vector object.
		\return				if vector is accessible pointer to its instance, or NULL.
	*/
	virtual imath::CVarVector GetValue(int index = -1, int valueTypeId = VTI_AUTO) const = 0;
};


} // namespace iproc


#endif // !iproc_IValueSupplier_included


