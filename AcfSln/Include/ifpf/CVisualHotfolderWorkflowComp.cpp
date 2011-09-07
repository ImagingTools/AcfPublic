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


// public methods


namespace ifpf
{


bool CVisualHotfolderWorkflowComp::SerializeLayout(iser::IArchive& archive)
{
	static iser::CArchiveTag positionMapTag("PositionMap", "Map of component name to its positions");
	static iser::CArchiveTag elementTag("Element", "Map element");

	bool retVal = true;

	istd::CStringList ids = this->GetHotfolderIds();
	int positionsCount = ids.size();

	retVal = retVal && archive.BeginMultiTag(positionMapTag, elementTag, positionsCount);

	if (!retVal){
		return false;
	}

	if (archive.IsStoring()){
		for (istd::CStringList::const_iterator iter = ids.begin(); iter != ids.end(); ++iter){
			istd::CString elementId = *iter;

			i2d::CVector2d position(0, 0);
			const CVisualHotfolderWorkflowItem* elementPtr = dynamic_cast<const CVisualHotfolderWorkflowItem*>(GetHotfolder(elementId));
			if (elementPtr != NULL){
				position = elementPtr->GetCenter();
			}

			retVal = retVal && archive.BeginTag(elementTag);

			retVal = retVal && SerializeItemPosition(archive, elementId, position);
				
			retVal = retVal && archive.EndTag(elementTag);
		}
	}
	else{
		istd::CChangeNotifier notifier(this);

		for (int i = 0; i < positionsCount; ++i){
			retVal = retVal && archive.BeginTag(elementTag);
			
			istd::CString elementId;
			i2d::CVector2d position;

			retVal = retVal && SerializeItemPosition(archive, elementId, position);
			if (!retVal){
				return false;
			}

			CVisualHotfolderWorkflowItem* elementPtr = dynamic_cast<CVisualHotfolderWorkflowItem*>(GetHotfolder(elementId));
			if (elementPtr != NULL){
				elementPtr->MoveCenterTo(position);
			}

			retVal = retVal && archive.EndTag(elementTag);
		}
	
	}

	retVal = retVal && archive.EndTag(positionMapTag);

	return retVal;
}


bool CVisualHotfolderWorkflowComp::SerializeWorkflow(iser::IArchive& archive)
{
	return BaseClass::Serialize(archive);
}


// reimplemented (iser::ISerializable)

bool CVisualHotfolderWorkflowComp::Serialize(iser::IArchive& archive)
{
	return SerializeWorkflow(archive) && SerializeLayout(archive);
}


// protected methods

bool CVisualHotfolderWorkflowComp::SerializeItemPosition(iser::IArchive& archive, istd::CString& hotfolderName, i2d::CVector2d& position)
{
	static iser::CArchiveTag nameTag("HotfolderName", "Name of the hotfolder");
	static iser::CArchiveTag positionXTag("X", "X position of component");
	static iser::CArchiveTag positionYTag("Y", "Y position of component");
	
	bool retVal = archive.BeginTag(nameTag);
	retVal = retVal && archive.Process(hotfolderName);
	retVal = retVal && archive.EndTag(nameTag);

	retVal = retVal && archive.BeginTag(positionXTag);
	retVal = retVal && archive.Process(position[0]);
	retVal = retVal && archive.EndTag(positionXTag);

	retVal = retVal && archive.BeginTag(positionXTag);
	retVal = retVal && archive.Process(position[1]);
	retVal = retVal && archive.EndTag(positionXTag);

	return retVal;
}


// reimplemented (ifpf::CHotfolderWorkflowComp)

ifpf::IHotfolderWorkflowItem* CVisualHotfolderWorkflowComp::CreateWorkflowItem(const istd::CString& hotfolderId) const
{
	Element* elementPtr = new Element();

	elementPtr->Initialize(hotfolderId, this);

	return elementPtr;
}

	
} // namespace ifpf


