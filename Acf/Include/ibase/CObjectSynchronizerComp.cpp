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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "ibase/CObjectSynchronizerComp.h"


// ACF inlcudes
#include "imod/IModel.h"


namespace ibase
{


// protected methods

// reimplemented (imod::CSingleModelObserverBase)

void CObjectSynchronizerComp::OnUpdate(int /*updateFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
	int slaveCounts = m_slaveObjectsCompPtr.GetCount();

	for (int slaveIndex = 0; slaveIndex < slaveCounts; slaveIndex++){
		istd::IChangeable* slaveObjectPtr = m_slaveObjectsCompPtr[slaveIndex];
		
		if ((slaveObjectPtr != NULL) && m_referenceObjectCompPtr.IsValid()){
			if (!slaveObjectPtr->IsEqual(*m_referenceObjectCompPtr.GetPtr())){
				slaveObjectPtr->CopyFrom(*m_referenceObjectCompPtr.GetPtr());
			}
		}
	}
}


// reimplemented (icomp::CComponentBase)

void CObjectSynchronizerComp::OnComponentCreated()
{
	if (m_referenceObjectModelCompPtr.IsValid()){
		m_referenceObjectModelCompPtr->AttachObserver(this);
	}
	
	BaseClass::OnComponentCreated();
}


void CObjectSynchronizerComp::OnComponentDestroyed()
{
	EnsureModelDetached();

	BaseClass::OnComponentDestroyed();
}


} // namespace ibase


