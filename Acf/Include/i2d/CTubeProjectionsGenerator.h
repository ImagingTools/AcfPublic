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


#ifndef i2d_CTubeProjectionsGenerator_included
#define i2d_CTubeProjectionsGenerator_included


#include "i2d/CTubePolyline.h"


namespace i2d
{


/**
	Helper class for generation of list of projection lines in the given tube region.
*/
class CTubeProjectionsGenerator
{
public:
	typedef QVector<CLine2d> ProjectionLines;

	/**
		Create list of projections for the given tube region.
		\param tube	Input tube region
		\param projectionsCount Number of projections to be generated
		\param projections	List of generated projection lines.
	*/
	static bool GeneratorProjections(const i2d::CTubePolyline& tube, int projectionsCount, ProjectionLines& projections);
};


} // namespace i2d


#endif // !i2d_CTubeProjectionsGenerator_included


