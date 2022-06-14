/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#include <iprm/CParamsSetProxyComp.h>


// ACF includes
#include <istd/CChangeGroup.h>


namespace iprm
{


CParamsSetProxyComp::CParamsSetProxyComp()
	:m_selectionUpdateBridge(this),
	m_paramsSetUpdateBridge(this)
{
}


// reimplemented (iprm::IParamsSet)

IParamsSet::Ids CParamsSetProxyComp::GetParamIds(bool editableOnly) const
{

	IParamsSet* paramsSetPtr = GetSelectedParamsSet();
	if (paramsSetPtr != nullptr){
		return paramsSetPtr->GetParamIds(editableOnly);
	}

	return Ids();
}


const iser::ISerializable* CParamsSetProxyComp::GetParameter(const QByteArray& id) const
{
	IParamsSet* paramsSetPtr = GetSelectedParamsSet();
	if (paramsSetPtr != nullptr){
		return paramsSetPtr->GetParameter(id);
	}

	return nullptr;
}


iser::ISerializable* CParamsSetProxyComp::GetEditableParameter(const QByteArray& id)
{
	IParamsSet* paramsSetPtr = GetSelectedParamsSet();
	if (paramsSetPtr != nullptr){
		return paramsSetPtr->GetEditableParameter(id);
	}

	return nullptr;
}


// reimplemented (iprm::IParamsSet)

const IOptionsList* CParamsSetProxyComp::GetSelectionConstraints() const
{
	return &m_paramsSetList;
}


int CParamsSetProxyComp::GetSelectedOptionIndex() const
{
	return m_paramsSetList.GetSelectedOptionIndex();
}


bool CParamsSetProxyComp::SetSelectedOptionIndex(int index)
{
	bool retVal = m_paramsSetList.SetSelectedOptionIndex(index);

	if (retVal){
		istd::CChangeGroup changeGroup(this);

		m_paramsSetUpdateBridge.EnsureModelsDetached();

		IParamsSet* paramsSetPtr = GetSelectedParamsSet();
		if (paramsSetPtr != nullptr){
			imod::IModel* modelPtr = dynamic_cast<imod::IModel*>(paramsSetPtr);
			if (modelPtr != nullptr){
				modelPtr->AttachObserver(&m_paramsSetUpdateBridge);
			}
		}
	}

	return retVal;
}


ISelectionParam* CParamsSetProxyComp::GetSubselection(int index) const
{
	return m_paramsSetList.GetSubselection(index);
}


// reimplemented (iser::ISerializable)

bool CParamsSetProxyComp::Serialize(iser::IArchive& /*archive*/)
{
	return false;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CParamsSetProxyComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	int count = qMin(m_optionNamesAttrPtr.GetCount(), m_optionDescriptionsAttrPtr.GetCount());
	count = qMin(count, m_optionIdsAttrPtr.GetCount());
	count = qMin(count, m_paramsSetCompPtr.GetCount());

	for (int i = 0; i < count; i++){
		m_paramsSetList.InsertOption(
					m_optionNamesAttrPtr[i],
					m_optionIdsAttrPtr[i],
					m_optionDescriptionsAttrPtr[i]);
	}

	int defaultIndex = *m_defaultOptionIndexAttrPtr;
	if (defaultIndex >= 0 && defaultIndex < m_paramsSetList.GetOptionsCount()){
		m_paramsSetList.SetSelectedOptionIndex(defaultIndex);
		IParamsSet* paramsSetPtr = GetSelectedParamsSet();
		Q_ASSERT(paramsSetPtr != nullptr);

		if (paramsSetPtr != nullptr){
			imod::IModel* modelPtr = dynamic_cast<imod::IModel*>(paramsSetPtr);
			if (modelPtr != nullptr){
				modelPtr->AttachObserver(&m_paramsSetUpdateBridge);
			}
		}
	}
	else{
		m_paramsSetList.SetSelectedOptionIndex(-1);
	}

	m_paramsSetList.AttachObserver(&m_selectionUpdateBridge);
}


void CParamsSetProxyComp::OnComponentDestroyed()
{
	m_selectionUpdateBridge.EnsureModelsDetached();
	m_paramsSetUpdateBridge.EnsureModelsDetached();

	BaseClass::OnComponentDestroyed();
}


// private

IParamsSet* CParamsSetProxyComp::GetSelectedParamsSet() const
{
	int selectedIndex = m_paramsSetList.GetSelectedOptionIndex();
	if (selectedIndex >= 0 && selectedIndex < m_paramsSetList.GetOptionsCount()){
		return m_paramsSetCompPtr[selectedIndex];
	}

	return nullptr;
}


} // namespace iprm


