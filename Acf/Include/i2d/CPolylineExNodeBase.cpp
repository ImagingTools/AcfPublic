/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "i2d/CPolylineExNodeBase.h"


// ACF includes
#include "iser/IArchive.h"


namespace i2d
{


// reimplemented (iser::ISerializable)

bool CPolylineExNodeBase::Serialize(iser::IArchive& archive)
{
	bool retVal = BaseClass::Serialize(archive);

	// static attributes
	if (retVal){
		int nodesCount = GetNodesCount();
		static iser::CArchiveTag nodesDataTag("NodesExtraData", "Nodes Extra Data");
		retVal = retVal && archive.BeginTag(nodesDataTag);
		for (int nodeIndex = 0; nodeIndex < nodesCount; ++nodeIndex){
			iser::ISerializable& nodeData = GetNodeDataRef(nodeIndex);

			static iser::CArchiveTag nodeDataTag("Node", "Node Data");
			retVal = retVal && archive.BeginTag(nodeDataTag);
			retVal = retVal && nodeData.Serialize(archive);
			retVal = retVal && archive.EndTag(nodeDataTag);
		}
		retVal = retVal && archive.EndTag(nodesDataTag);
	}

	return retVal;
}


} // namespace i2d

