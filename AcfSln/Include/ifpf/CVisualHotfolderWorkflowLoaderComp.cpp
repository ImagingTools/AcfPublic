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


#include "ifpf/CVisualHotfolderWorkflowComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"
#include "istd/CStaticServicesProvider.h"

#include "isys/CSectionBlocker.h"

#include "iser/IArchive.h"
#include "iser/CArchivetag.h"

#include "iproc/IProcessor.h"


namespace ifpf
{


// public methods

// reimplemented (iser::ISerializable)

bool CVisualHotfolderWorkflowComp::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	return retVal;
}


} // namespace ifpf


