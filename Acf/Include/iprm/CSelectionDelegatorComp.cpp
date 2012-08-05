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


#include "iprm/CSelectionDelegatorComp.h"


// ACF inlcudes
#include "imod/IModel.h"


namespace iprm
{


// protected methods

// reimplemented (imod::CSingleModelObserverBase)

void CSelectionDelegatorComp::OnUpdate(int /*updateFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
	int slaveCounts = m_slaveSelectionsCompPtr.GetCount();

	for (int slaveIndex = 0; slaveIndex < slaveCounts; slaveIndex++){
		iprm::ISelectionParam* selectionPtr = m_slaveSelectionsCompPtr[slaveIndex];
		if (selectionPtr != NULL){
			selectionPtr->SetSelectedOptionIndex(m_sourceSelectionCompPtr->GetSelectedOptionIndex());
		}
	}
}


// reimplemented (icomp::CComponentBase)

void CSelectionDelegatorComp::OnComponentCreated()
{
	if (m_sourceSelectionModelCompPtr.IsValid()){
		m_sourceSelectionModelCompPtr->AttachObserver(this);
	}
	
	BaseClass::OnComponentCreated();
}


void CSelectionDelegatorComp::OnComponentDestroyed()
{
	EnsureModelDetached();

	BaseClass::OnComponentDestroyed();
}


} // namespace iprm


