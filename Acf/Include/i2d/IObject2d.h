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


#ifndef i2d_IObject2d_included
#define i2d_IObject2d_included


#include "iser/ISerializable.h"

#include "imath/imath.h"


namespace i2d
{


class CVector2d;
class CRectangle;


/**
	Common interface for describing the 2D-objects.
*/
class IObject2d: virtual public iser::ISerializable
{
public:
	enum ChangeFlags
	{
		CF_OBJECT_POSITION = 0x800
	};

	/**
		Returns center of this 2D-object.
	*/
	virtual CVector2d GetCenter() const = 0;

	/**
		Move object to position \c position.
	*/
	virtual void MoveCenterTo(const CVector2d& position) = 0;
};


} // namespace i2d


#endif // !i2d_IObject2d_included

