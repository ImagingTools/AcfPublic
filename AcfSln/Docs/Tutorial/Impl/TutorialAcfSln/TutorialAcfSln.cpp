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


#include "TutorialAcfSln.h" 


#include "icomp/export.h" 


namespace TutorialAcfSln
{


I_EXPORT_PACKAGE(
			"TutorialAcfSln",
			"Tutorial of ACF-Solutions project",
			IM_COMPANY("ImagingTools") IM_PROJECT("ACF-Solutions") IM_CATEGORY("Tutorial") IM_TAG("Tutorial"));

I_EXPORT_COMPONENT(
			EdgeLinesTestGui,
			"Component used to test visualization of edge lines",
			"Contour Border Edge Lines Gui Visualization View Show Display" IM_AUTHOR("\"Sebastian Olter\" \"Ryszard Mroczka\" \"Witold Gantzke\""));


} // namespace TutorialAcfSln


