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


#include "QwtPck.h"


#include "icomp/export.h"


I_REGISTER_QT_RESOURCE(iqtgui);
I_REGISTER_QT_RESOURCE(Qwt3d);


namespace QwtPck
{


I_EXPORT_PACKAGE(
			"Iacf/Gui/Qwt",
			"QWT and QWT3D based package",
			"Qwt Qt 2D 3D View" IM_TAG("Qt") IM_PROJECT("IACF") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			ProgressHistoryGui,
			"Progress history shown as 2D diagram",
			"Progress History Diagram Activity Curve Line Statistics" IM_TAG("2D"));

I_EXPORT_COMPONENT(
			HistogramView,
			"Histogram view",
			"Histogram Statistics" IM_TAG("GUI"));

I_EXPORT_COMPONENT(
			SurfaceView,
			"3D-View component",
			"Model Observer Parameter GUI Qt 3D Surface" IM_TAG("Image 3D"));


} // namespace QwtPck


