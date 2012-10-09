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


#ifndef ihotf_CVisualHotfolderWorkflowItem_included
#define ihotf_CVisualHotfolderWorkflowItem_included


// ACF includes
#include "i2d/CPosition2d.h"


// AcfSln includes
#include "ihotf/CHotfolderWorkflowItem.h"


namespace ihotf
{


/**
	Implementation of the dynamic data model of the hotfolder.
*/
class CVisualHotfolderWorkflowItem:
			public ihotf::CHotfolderWorkflowItem,
			public i2d::CPosition2d
{
public:
	typedef ihotf::CHotfolderWorkflowItem BaseClass;
	typedef i2d::CPosition2d BaseClass2;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);
};


} // namespace ihotf


#endif // !ihotf_CVisualHotfolderWorkflowItem_included

