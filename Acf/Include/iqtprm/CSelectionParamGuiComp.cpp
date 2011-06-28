/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqtprm/CSelectionParamGuiComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"

#include "iprm/ISelectionConstraints.h"

#include "iqt/CSignalBlocker.h"


namespace iqtprm
{


// reimplemented (imod::IModelEditor)

void CSelectionParamGuiComp::UpdateModel() const
{
	I_ASSERT(IsGuiCreated());

	iprm::ISelectionParam* selectionPtr = GetObjectPtr();
	I_ASSERT(selectionPtr != NULL);

	int switchesCount = m_comboBoxes.GetCount();

	for (		int switchIndex = 0;
				(selectionPtr != NULL) && switchIndex < switchesCount;
				++switchIndex){
		const QComboBox* switchBoxPtr = m_comboBoxes.GetAt(switchIndex);
		selectionPtr->SetSelectedOptionIndex(switchBoxPtr->currentIndex());

		selectionPtr = selectionPtr->GetActiveSubselection();
	}
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CSelectionParamGuiComp::UpdateGui(int /*updateFlags*/)
{
	I_ASSERT(IsGuiCreated());

	m_comboBoxes.Reset();

	for (		iprm::ISelectionParam* selectionPtr = GetObjectPtr();
				selectionPtr != NULL;
				selectionPtr = selectionPtr->GetActiveSubselection()){
		QComboBox* switchBoxPtr = new QComboBox(SelectionFrame);
		m_comboBoxes.PushBack(switchBoxPtr);
		QLayout* layoutPtr = SelectionFrame->layout();
		if (layoutPtr != NULL){
			layoutPtr->addWidget(switchBoxPtr);
		}

		QObject::connect(switchBoxPtr, SIGNAL(currentIndexChanged(int)), this, SLOT(OnSelectionChanged(int)));

		const iprm::ISelectionConstraints* constraintsPtr = selectionPtr->GetConstraints();
		if (constraintsPtr != NULL){
			int optionsCont = constraintsPtr->GetOptionsCount();

			for (int i = 0; i < optionsCont; ++i){
				istd::CString name = constraintsPtr->GetOptionName(i);

				switchBoxPtr->addItem(iqt::GetQString(name));
			}

			int selectedIndex = selectionPtr->GetSelectedOptionIndex();

			if (selectedIndex >= 0){
				switchBoxPtr->setCurrentIndex(selectedIndex);
			}
		}
	}
}


// reimplemented (iqtgui::CGuiComponentBase)

void CSelectionParamGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	if (m_optionsLabelAttrPtr.IsValid()){
		SelectionLabel->setText(iqt::GetQString(*m_optionsLabelAttrPtr));
	}
}


void CSelectionParamGuiComp::OnGuiDestroyed()
{
	m_comboBoxes.Reset();

	BaseClass::OnGuiDestroyed();
}


// protected slots

void CSelectionParamGuiComp::OnSelectionChanged(int /*index*/)
{
	if (!IsUpdateBlocked()){
		UpdateBlocker updateBlocker(const_cast<CSelectionParamGuiComp*>(this));

		UpdateModel();
	}
}


} // namespace iqtprm


