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


#include "i2d/CPolygonExtractor.h"


namespace i2d
{


i2d::CPolygon CPolygonExtractor::CreatePolygon(const i2d::CAnnulus& annulus, int innerNodesCount, int outerNodesCount)
{
	Q_ASSERT(innerNodesCount > 0);
	Q_ASSERT(outerNodesCount > 0);

	i2d::CPolygon result;
	result.Clear();

	double smallRadius = annulus.GetInnerRadius();
	double bigRadius = annulus.GetOuterRadius();
	const i2d::CVector2d& center = annulus.GetPosition();

	double step = I_2PI / innerNodesCount;

	double angle = 0.0;
	int index;
	for (index = 0; index <= innerNodesCount; ++index){
		i2d::CVector2d point;
		point.Init(angle, smallRadius);
		result.InsertNode(point + center);
		angle += step;
	}

	step = I_2PI / outerNodesCount;

	angle = 0.0;
	for (index = 0; index <= outerNodesCount; ++index){
		i2d::CVector2d point;
		point.Init(angle, bigRadius);
		result.InsertNode(point + center);
		angle -= step;
	}

	return result;
}


}// namespace i2d


