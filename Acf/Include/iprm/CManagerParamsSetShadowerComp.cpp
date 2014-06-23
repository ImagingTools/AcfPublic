/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#include "iprm/CManagerParamsSetShadowerComp.h"


// ACF includes
#include "istd/CChangeNotifier.h"

#include "imod/IModel.h"


namespace iprm
{


CManagerParamsSetShadowerComp::CManagerParamsSetShadowerComp()
:	m_currentParamsSetObserver(this),
	m_currentParamsModelPtr(NULL)
{
}


// protected methods

bool CManagerParamsSetShadowerComp::CopyParamsSetToShadow()
{
	if (m_shadowParamsSetCompPtr.IsValid() && m_paramsManagerCompPtr.IsValid() && m_selectionParamCompPtr.IsValid()){
		int index = m_selectionParamCompPtr->GetSelectedOptionIndex();
		if ((index >= 0) && (index < m_paramsManagerCompPtr->GetParamsSetsCount())){
			const IParamsSet* selectedSetPtr = m_paramsManagerCompPtr->GetParamsSet(index);
			if (selectedSetPtr != NULL){
				m_shadowParamsSetCompPtr->CopyFrom(*selectedSetPtr);

				return true;
			}
		}
	}

	return false;
}


// reimplemented (icomp::CComponentBase)

void CManagerParamsSetShadowerComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (		m_paramsManagerCompPtr.IsValid() &&
				m_paramsManagerModelCompPtr.IsValid() &&
				m_selectionParamCompPtr.IsValid() &&
				m_shadowParamsSetCompPtr.IsValid()){
		m_paramsManagerModelCompPtr->AttachObserver(this);
	}
}


void CManagerParamsSetShadowerComp::OnComponentDestroyed()
{
	imod::CSingleModelObserverBase::EnsureModelDetached();
	m_currentParamsSetObserver.EnsureModelDetached();
	m_currentParamsModelPtr = NULL;

	BaseClass::OnComponentDestroyed();
}


// reimplemented (imod::CSingleModelObserverBase)

void CManagerParamsSetShadowerComp::OnUpdate(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	Q_ASSERT(m_paramsManagerCompPtr.IsValid());
	Q_ASSERT(m_selectionParamCompPtr.IsValid());

	int index = m_selectionParamCompPtr->GetSelectedOptionIndex();
	if ((index >= 0) && (index < m_paramsManagerCompPtr->GetParamsSetsCount())){
		imod::IModel* paramsModelPtr = const_cast<imod::IModel*>(dynamic_cast<const imod::IModel*>((
					m_paramsManagerCompPtr->GetParamsSet(index))));
		if (paramsModelPtr != m_currentParamsModelPtr){
			m_currentParamsSetObserver.EnsureModelDetached();
			m_currentParamsModelPtr = NULL;

			if ((paramsModelPtr != NULL) && paramsModelPtr->AttachObserver(&m_currentParamsSetObserver)){
				m_currentParamsModelPtr  = paramsModelPtr;
			}
		}
	}

	CopyParamsSetToShadow();
}


// public methods of the embedded class CurrentParamsSetObserver

CManagerParamsSetShadowerComp::CurrentParamsSetObserver::CurrentParamsSetObserver(CManagerParamsSetShadowerComp* parentPtr)
:	m_parent(*parentPtr)
{
	Q_ASSERT(parentPtr != NULL);
}


// reimplemented (imod::CSingleModelObserverBase)

void CManagerParamsSetShadowerComp::CurrentParamsSetObserver::OnUpdate(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	m_parent.CopyParamsSetToShadow();
}


} // namespace iprm


