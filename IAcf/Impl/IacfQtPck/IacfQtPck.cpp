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


#include <QDir>

#include "icomp/export.h"

#include "iqt/CDefaultServicesProvider.h"

#include "IacfQtPck.h"


static struct StaticInit
{
	StaticInit()
	{
		Q_INIT_RESOURCE(iqtgui);
	}

} instance;


namespace IacfQtPck
{


I_EXPORT_SERVICES_PROVIDER(iqt::CDefaultServicesProvider);


I_EXPORT_PACKAGE(
			"IacfQt",
			"Imaging tools Qt-based general package",
			"Imaging Tools Qt Standard" IM_PROJECT("IACF") IM_TAG("\"Image Processing\"") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));


I_EXPORT_COMPONENT(
			SamplingParamsGui,
			"Sampling parameters",
			"Interval Sample Sampling Model Parameters GUI Qt");

I_EXPORT_COMPONENT(
			SampleAcquisitionGui,
			"Sample acquisition GUI",
			"Sample Sampling Acquisition GUI");

I_EXPORT_COMPONENT(
			ScriptDataProcessor,
			"Test sample acquisition based on QtScript",
			"Test Sample Sampling Acquisition Script QtScript");

I_EXPORT_COMPONENT(
			InspectionTaskGui,
			"GUI for general inspection task",
			"Task Supplier Composite Observer" IM_TAG("Inspection GUI Editor"));

I_EXPORT_COMPONENT(
			GeneralSupplierGui,
			"General GUI for supplier (usable as subtask GUI)",
			"Task Supplier Observer Subtask" IM_TAG("Inspection GUI Editor"));


} // namespace IacfQtPck


