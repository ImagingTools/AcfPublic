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


#ifndef QtProdPck_included
#define QtProdPck_included


#include "iqtcntl/CDriverControllerComp.h"
#include "iqtcntl/CAutomaticControllerGuiComp.h"
#include "iqtcntl/CSimulatedMultiTracerGuiComp.h"


/**
	Production controll package based on Qt.
*/
namespace QtProdPck
{


typedef iqtcntl::CDriverControllerComp DriverController;

// GUI components
typedef iqtcntl::CAutomaticControllerGuiComp AutomaticControllerGui;
typedef iqtcntl::CSimulatedMultiTracerGuiComp SimulatedMultiTracerGui;


} // namespace QtProdPck


#endif // !QtProdPck_included


