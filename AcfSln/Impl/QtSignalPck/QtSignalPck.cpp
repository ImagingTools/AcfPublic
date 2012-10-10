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


#include "QtSignalPck.h"


// ACF includes
#include "icomp/export.h"


I_REGISTER_QT_RESOURCE(iqtgui);


namespace QtSignalPck
{


I_EXPORT_PACKAGE(
			"AcfSln/Signal/Gui",
			"Imaging tools Qt-based general package",
			"Imaging Tools Qt Standard" IM_PROJECT("ACF-Solutions") IM_TAG("\"Image Processing\"") IM_COMPANY("ImagingTools"));


I_EXPORT_COMPONENT(
			SamplingParamsGui,
			"GUI editor for sampling parameters",
			"Interval Sample Sampling Interval Observer Editor Parameters GUI Qt" IM_AUTHOR("\"Witold Gantzke\""));

I_EXPORT_COMPONENT(
			PulseParamsGui,
			"GUI editor for pulse parameters",
			"Pulse Delay Relaxing Interval Observer Editor Parameters GUI Qt" IM_AUTHOR("\"Witold Gantzke\""));

I_EXPORT_COMPONENT(
			TriggerParamsGui,
			"GUI editor for trigger parameters",
			"Trigger Mode Edge Observer Editor Parameters GUI Qt" IM_AUTHOR("\"Witold Gantzke\""));

I_EXPORT_COMPONENT(
			SampleAcquisitionGui,
			"Sample acquisition GUI",
			"Sample Sampling Acquisition GUI" IM_AUTHOR("\"Witold Gantzke\""));

I_EXPORT_COMPONENT(
			ScriptDataProcessor,
			"Test sample acquisition based on QtScript",
			"Test Sample Sampling Acquisition Script QtScript" IM_AUTHOR("\"Witold Gantzke\""));


} // namespace QtSignalPck


