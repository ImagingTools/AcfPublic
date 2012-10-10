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


#ifndef imath_IDoubleManip_included
#define imath_IDoubleManip_included


// Qt includes
#include <QtCore/QByteArray>

// ACF includes
#include "istd/IPolymorphic.h"

#include "imath/TIValueManip.h"


namespace imath
{


/**
	Interface for all manipulation using values represent as \c double.
*/
class IDoubleManip: virtual public TIValueManip<double>
{
public:
	/**
		Get number of digits after point.
	*/
	virtual int GetPrecision() const = 0;
};


} // namespace imath


#endif // !imath_IDoubleManip_included


