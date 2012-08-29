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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef i2d_CPolygonExtractor_included
#define i2d_CPolygonExtractor_included

// ACF includes
#include "i2d/CPolygon.h"
#include "i2d/CVector2d.h"
#include "i2d/CAnnulus.h"


namespace i2d
{


class CPolygonExtractor
{
public:
	static i2d::CPolygon CreatePolygon(const i2d::CAnnulus& annulus, int innerNodesCount, int outerNodesCount);
};


} // namespace i2d


#endif // !i2d_CPolygonExtractor_included

