/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include <iprm/CSelectableParamsSetComp.h>


// ACF includes
#include <istd/CChangeNotifier.h>

#include <imod/IModel.h>


namespace iprm
{


// static constants
static const istd::IChangeable::ChangeSet s_selectionChangeSet(ISelectionParam::CF_SELECTION_CHANGED);
static const iser::CArchiveTag s_selectedIndexTag("Selected", "Selected index", iser::CArchiveTag::TT_LEAF);
static const iser::CArchiveTag s_paramsManagerTag("Parameters", "All parameters", iser::CArchiveTag::TT_GROUP);


CSelectableParamsSetComp::CSelectableParamsSetComp()
:	m_updateBridge(this)
{
}


// reimplemented (iprm::IParamsSet)

IParamsSet::Ids CSelectableParamsSetComp::GetParamIds(bool editableOnly) const
{
	Ids retVal;

	if (!editableOnly){
		if (m_selectionParamIdAttrPtr.IsValid()){
			const QByteArray& selectionId = *m_selectionParamIdAttrPtr;
			retVal += selectionId;
		}

		if (m_paramsManagerCompPtr.IsValid()){
			int selectedIndex = -1;
			if (m_currentSelectionCompPtr.IsValid()){
				selectedIndex = m_currentSelectionCompPtr->GetSelectedOptionIndex();
			}
			else{
				selectedIndex = m_paramsManagerCompPtr->GetSelectedOptionIndex();
			}

			if ((selectedIndex >= 0) && (selectedIndex < m_paramsManagerCompPtr->GetParamsSetsCount())){
				const iprm::IParamsSet* paramsPtr = m_paramsManagerCompPtr->GetParamsSet(selectedIndex);
				if (paramsPtr != NULL){
					retVal += paramsPtr->GetParamIds(false);
				}
			}
		}
	}

	return retVal;
}


const iser::ISerializable* CSelectableParamsSetComp::GetParameter(const QByteArray& id) const
{
	if (m_selectionParamIdAttrPtr.IsValid()){
		const QByteArray& selectionId = *m_selectionParamIdAttrPtr;
		if (id == selectionId){
			if (m_currentSelectionCompPtr.IsValid()){
				return m_currentSelectionCompPtr.GetPtr();
			}

			return m_paramsManagerCompPtr.GetPtr();
		}
	}

	if (m_paramsManagerCompPtr.IsValid()){
		int selectedIndex = -1;
		if (m_currentSelectionCompPtr.IsValid()){
			selectedIndex = m_currentSelectionCompPtr->GetSelectedOptionIndex();
		}
		else{
			selectedIndex = m_paramsManagerCompPtr->GetSelectedOptionIndex();
		}

		if ((selectedIndex >= 0) && (selectedIndex < m_paramsManagerCompPtr->GetParamsSetsCount())){
			const iprm::IParamsSet* paramsPtr = m_paramsManagerCompPtr->GetParamsSet(selectedIndex);
			if (paramsPtr != NULL){
				return paramsPtr->GetParameter(id);
			}
		}
	}

	return NULL;
}


iser::ISerializable* CSelectableParamsSetComp::GetEditableParameter(const QByteArray& /*id*/)
{
	return NULL;
}


// reimplemented (iser::ISerializable)

bool CSelectableParamsSetComp::Serialize(iser::IArchive& /*archive*/)
{
	return false;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CSelectableParamsSetComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_currentSelectionModelCompPtr.IsValid()){
		m_currentSelectionModelCompPtr->AttachObserver(&m_updateBridge);
	}

	if (m_paramsManagerModelCompPtr.IsValid() && (m_paramsManagerModelCompPtr.GetPtr() != m_currentSelectionModelCompPtr.GetPtr())){
		m_paramsManagerModelCompPtr->AttachObserver(&m_updateBridge);
	}
}


void CSelectableParamsSetComp::OnComponentDestroyed()
{
	m_updateBridge.EnsureModelsDetached();

	BaseClass::OnComponentDestroyed();
}


} // namespace iprm


