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


#include "iprm/CSelectionParamComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"

#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace iprm
{


CSelectionParamComp::CSelectionParamComp()
:	m_selectedOptionIndex(-1)
{
}


// reimplemented (iprm::ISelectionParam)

const ISelectionConstraints* CSelectionParamComp::GetSelectionConstraints() const
{
	return m_constraintsCompPtr.GetPtr();
}


int CSelectionParamComp::GetSelectedOptionIndex() const
{
	return m_selectedOptionIndex;
}


bool CSelectionParamComp::SetSelectedOptionIndex(int index)
{
	if (m_constraintsCompPtr.IsValid() && (index >= m_constraintsCompPtr->GetOptionsCount())){
		return false;
	}

	if (m_selectedOptionIndex != index){
		istd::CChangeNotifier changeNotifier(this, CF_SELECTION_CHANGED);

		m_selectedOptionIndex = index;
	}

	return true;
}


ISelectionParam* CSelectionParamComp::GetActiveSubselection() const
{
	return m_subselectionCompPtr.GetPtr();
}


// reimplemented (iser::ISerializable)

bool CSelectionParamComp::Serialize(iser::IArchive& archive)
{
	int selectionOptionIndex = m_selectedOptionIndex;

	static iser::CArchiveTag selectedOptionIndexTag("Index", "Selected option index");
	bool retVal = archive.BeginTag(selectedOptionIndexTag);
	retVal = retVal && archive.Process(selectionOptionIndex);
	retVal = retVal && archive.EndTag(selectedOptionIndexTag);

	if (retVal && !archive.IsStoring()){
		if (selectionOptionIndex != m_selectedOptionIndex){
			istd::CChangeNotifier changeNotifier(this, CF_SELECTION_CHANGED);

			m_selectedOptionIndex = selectionOptionIndex;
		}
	}

	return retVal;
}


// protected methods

// reimplemented (imod::CMultiModelDispatcherBase)

void CSelectionParamComp::OnModelChanged(int /*modelId*/, int /*changeFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
	// adjust selection to the new constraints:
	SetSelectedOptionIndex(0);
}


// reimplemented (icomp::CComponentBase)

void CSelectionParamComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	m_selectedOptionIndex = *m_defaultIndexAttrPtr;
/*
	if (m_constraintsCompPtr.IsValid()){
		imod::IModel* constraintsModelPtr = dynamic_cast<imod::IModel*>(m_constraintsCompPtr.GetPtr());
		if (constraintsModelPtr != NULL){
			RegisterModel(constraintsModelPtr);
		}
	}
	*/
}


void CSelectionParamComp::OnComponentDestroyed()
{
	UnregisterAllModels();

	BaseClass::OnComponentDestroyed();
}


} // namespace iprm


