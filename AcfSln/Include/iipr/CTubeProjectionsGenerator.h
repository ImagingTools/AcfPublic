/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef i2d_CTubeProjectionsGenerator_included
#define i2d_CTubeProjectionsGenerator_included


#include "i2d/CTubePolyline.h"


namespace iipr
{


/**
	Helper class for generation of list of projection lines in the given tube region.
*/
class CTubeProjectionsGenerator
{
public:
	typedef QVector<i2d::CLine2d> ProjectionLines;

	/**
		Create list of projections for the given tube region.
		\param tube	Input tube region
		\param projectionsCount Number of projections to be generated
		\param projections	List of generated projection lines.
	*/
	static bool GenerateProjections(const i2d::CTubePolyline& tube, int projectionsCount, ProjectionLines& projections);
};


} // namespace iipr


#endif // !i2d_CTubeProjectionsGenerator_included


