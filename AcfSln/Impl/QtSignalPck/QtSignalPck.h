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


#ifndef QtSignalPck_included
#define QtSignalPck_included


// ACF includes
#include "icomp/TModelCompWrap.h"
#include "icomp/TMakeComponentWrap.h"

#include "iqtsig/CSamplingParamsGuiComp.h"
#include "iqtsig/CPulseParamsGuiComp.h"
#include "iqtsig/CTriggerParamsGuiComp.h"
#include "iqtsig/CSampleAcquisitionGuiComp.h"
#include "iqtsig/CScriptDataProcessorComp.h"


/**
	Standard Qt package.
*/
namespace QtSignalPck
{


typedef iqtsig::CSamplingParamsGuiComp SamplingParamsGui;
typedef iqtsig::CPulseParamsGuiComp PulseParamsGui;
typedef iqtsig::CTriggerParamsGuiComp TriggerParamsGui;
typedef iqtsig::CSampleAcquisitionGuiComp SampleAcquisitionGui;
typedef iqtsig::CScriptDataProcessorComp ScriptDataProcessor;


} // namespace QtSignalPck


#endif // !QtSignalPck_included


