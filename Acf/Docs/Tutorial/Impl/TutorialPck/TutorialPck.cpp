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


#include "icomp/export.h"

#include "TutorialPck.h"


namespace TutorialPck
{


I_EXPORT_PACKAGE(
			"Tutorial",
			"ACF Tutorial package",
			IM_TAG("Qt Tutorial") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			TextEditor,
			"Text editor being observer of text model",
			"Text Tutorial Document Observer Qt GUI");

I_EXPORT_COMPONENT(
			AB,
			"Data model of AB",
			"Data Model AB");

I_EXPORT_COMPONENT(
			AbGui,
			"Editor for AB data model",
			"Data Model AB Editor GUI");


} // namespace TutorialPck


