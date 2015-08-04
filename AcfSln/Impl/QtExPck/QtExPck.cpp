/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include "QtExPck.h"


#include "icomp/export.h"


I_REGISTER_QT_RESOURCE(iqtgui);


namespace QtExPck
{


I_EXPORT_PACKAGE(
			"AcfSln/QtExtension",
			"Acf-Solutions extended package based on Qt",
			"Extensions" IM_TAG("Qt") IM_PROJECT("ACF-Solutions") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			TcpTerminalGui,
			"Tcp client terminal",
			"TCP Client Terminal Input Output Test" IM_TAG("GUI"));

I_EXPORT_COMPONENT(
			XslFileSerializer,
			"File loader serializing objects using simplified XML format using Qt, provides XSLT",
			"Save Serializer Archive Format XSLT" IM_CATEGORY(I_DATA_PERSISTENCE) IM_TAG("XML Loader File"));

I_EXPORT_COMPONENT(
			ServiceApplication,
			"An application as service/daemon",
			"Service Daemon" IM_TAG("Application"));


} // namespace QtExPck


