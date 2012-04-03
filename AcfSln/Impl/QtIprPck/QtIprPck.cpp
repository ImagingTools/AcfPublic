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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "QtIprPck.h"


// Qt includes
#include <QtCore/QDir>


// ACF includes
#include "icomp/export.h"

#include "iqt/CDefaultServicesProvider.h"


namespace QtIprPck
{


I_EXPORT_SERVICES_PROVIDER(iqt::CDefaultServicesProvider);

I_EXPORT_PACKAGE(
			"QtIpr",
			"Standard Qt image processing package",
			"Qt \"Image Processing\"" IM_PROJECT("ACF-Solutions") IM_TAG("\"Image Processing\"") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));


I_EXPORT_COMPONENT(
			ValueSupplierGui,
			"GUI for supplier implementation returning position found using caliper tool",
			"GUI Observer Caliper Position Qt Processing Supplier");

I_EXPORT_COMPONENT(
			CaliperParamsGui,
			"GUI to parametrize caliper",
			"GUI Observer Caliper Parameters Direction Edge Mode Threshold Qt");

I_EXPORT_COMPONENT(
			LineProjectionSupplierGui,
			"GUI for line projection supplier",
			"GUI Observer Supplier Line Projection Image Processing Qt");

I_EXPORT_COMPONENT(
			CircleFinderParamsGui,
			"GUI to parametrize the circle finder",
			"GUI Observer Caliper Circle Parameters Qt");

I_EXPORT_COMPONENT(
			SearchBasedFeaturesSupplierGui,
			"GUI for search based position supplier",
			"GUI Observer Supplier Search Image Processing Qt");

I_EXPORT_COMPONENT(
			GeneralSearchParamsGui,
			"GUI for general search parameters",
			"GUI Observer Search Parameters Qt");


} // namespace QtIprPck


