/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**  by Skype to ACF_infoline for further information about the ACF.
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


