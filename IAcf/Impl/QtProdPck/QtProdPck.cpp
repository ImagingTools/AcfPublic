/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#include "icomp/export.h"

#include "QtProdPck.h"


namespace QtProdPck
{


I_EXPORT_DEFAULT_SERVICES

I_EXPORT_PACKAGE(
			"QtProd",
			"Qt-based production and control package",
			"Qt Production Automatic Controller" IM_PROJECT("IACF") IM_TAG("\"Image Processing\"") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			DriverController,
			"Synchronize driver with production line parameter and control working mode",
			"Production Line Automatic Driver Controller");

I_EXPORT_COMPONENT(
			AutomaticControllerGui,
			"GUI for automatic controller implemented as observer",
			"Production Line Automatic Driver Controller Observer");

I_EXPORT_COMPONENT(
			SimulatedMultiTracerGui,
			"Simulated multi line object tracer delegating controlled using GUI",
			"Sumulation Multi Line Object Tracer Qt GUI");


} // namespace QtProdPck


