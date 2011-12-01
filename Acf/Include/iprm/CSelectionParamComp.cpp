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
	std::string selectedOptionId;

	static iser::CArchiveTag selectedOptionIndexTag("Index", "Selected option index");
	bool retVal = archive.BeginTag(selectedOptionIndexTag);
	retVal = retVal && archive.Process(selectionOptionIndex);
	retVal = retVal && archive.EndTag(selectedOptionIndexTag);

	if (m_constraintsCompPtr.IsValid()){
		int optionsCount = m_constraintsCompPtr->GetOptionsCount();

		if ((selectionOptionIndex >= 0) && (selectionOptionIndex < optionsCount)){
			selectedOptionId = m_constraintsCompPtr->GetOptionId(selectionOptionIndex);
		}
	}

	static iser::CArchiveTag selectedOptionIdTag("OptionId", "Selected option identifier");
	retVal = retVal && archive.BeginTag(selectedOptionIdTag);
	retVal = retVal && archive.Process(selectedOptionId);
	retVal = retVal && archive.EndTag(selectedOptionIdTag);

	if (retVal && !archive.IsStoring()){
		if (		m_constraintsCompPtr.IsValid() &&
					((m_constraintsCompPtr->GetConstraintsFlags() & iprm::ISelectionConstraints::SCF_SUPPORT_UNIQUE_ID) != 0) &&
					!selectedOptionId.empty()){
			if (!SetSelectedOptionIndexById(selectedOptionId) && !SetSelectedOptionIndex(selectionOptionIndex)){
				SetSelectedOptionIndex(-1);
			}
		}
		else{
			SetSelectedOptionIndex(selectionOptionIndex);
		}
	}

	return retVal;
}


// protected methods

bool CSelectionParamComp::SetSelectedOptionIndexById(const std::string& selectedOptionId)
{
	I_ASSERT(!selectedOptionId.empty());
	I_ASSERT(m_constraintsCompPtr.IsValid());

	if (m_constraintsCompPtr.IsValid()){
		int optionsCount = m_constraintsCompPtr->GetOptionsCount();

		for (int optionIndex = 0; optionIndex < optionsCount; optionIndex++){
			std::string optionId = m_constraintsCompPtr->GetOptionId(optionIndex);

			if (optionId == selectedOptionId){
				return SetSelectedOptionIndex(optionIndex);
			}
		}
	}

	return false;
}


// reimplemented (icomp::CComponentBase)

void CSelectionParamComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	m_selectedOptionIndex = *m_defaultIndexAttrPtr;
}


} // namespace iprm


