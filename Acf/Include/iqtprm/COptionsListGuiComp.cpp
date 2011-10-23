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


#include "iqtprm/COptionsListGuiComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"

#include "iprm/ISelectionConstraints.h"


namespace iqtprm
{


// reimplemented (imod::IModelEditor)

void COptionsListGuiComp::UpdateModel() const
{
	I_ASSERT(IsGuiCreated());

	QList<QTreeWidgetItem*> selectedItems = OptionsList->selectedItems();
	if (selectedItems.isEmpty()){
		iprm::ISelectionParam* objectPtr = GetObjectPtr();
		I_ASSERT(objectPtr != NULL);

		objectPtr->SetSelectedOptionIndex(iprm::ISelectionParam::NO_SELECTION);
	}
	else{
		QTreeWidgetItem* selectedItemPtr = selectedItems[0];

		int selectedIndex = selectedItemPtr->data(0, DR_SELECTION_INDEX).toInt();
		iprm::ISelectionParam* selectionParamPtr = reinterpret_cast<iprm::ISelectionParam*>(selectedItemPtr->data(0, DR_SELECTION_PARAM).toUInt());

		I_ASSERT(selectionParamPtr != NULL);

		selectionParamPtr->SetSelectedOptionIndex(selectedIndex);
	}
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void COptionsListGuiComp::UpdateGui(int /*updateFlags*/)
{
	I_ASSERT(IsGuiCreated());

	OptionsList->clear();
	
	iprm::ISelectionParam* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		CreateOptionsTree(objectPtr);
	}
}


// reimplemented (iqtgui::CGuiComponentBase)

void COptionsListGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	connect(OptionsList, SIGNAL(itemSelectionChanged()), this, SLOT(OnSelectionChanged()));
}


void COptionsListGuiComp::OnGuiDestroyed()
{
	BaseClass::OnGuiDestroyed();
}


// protected slots

void COptionsListGuiComp::OnSelectionChanged()
{
	if (!IsUpdateBlocked() && IsModelAttached()){
		UpdateBlocker updateBlocker(this);

		UpdateModel();
	}
}


// private methods

void COptionsListGuiComp::CreateOptionsTree(const iprm::ISelectionParam* selectionParamPtr, QTreeWidgetItem* parentItemPtr)
{
	const iprm::ISelectionConstraints* selectionContraints = selectionParamPtr->GetSelectionConstraints();
	if (selectionParamPtr != NULL){
		int selectedOptionIndex = selectionParamPtr->GetSelectedOptionIndex();

		for (int optionIndex = 0; optionIndex < selectionContraints->GetOptionsCount(); optionIndex++){
			QString optionName = iqt::GetQString(selectionContraints->GetOptionName(optionIndex));

			QTreeWidgetItem* itemPtr = new QTreeWidgetItem(OptionsList);
			itemPtr->setText(0, optionName);
			itemPtr->setData(0, DR_SELECTION_INDEX, optionIndex);
			itemPtr->setData(0, DR_SELECTION_PARAM, quintptr(selectionParamPtr));

			if (parentItemPtr != NULL){
				parentItemPtr->addChild(itemPtr);
			}
			else{
				OptionsList->addTopLevelItem(itemPtr);
			}

			if (selectedOptionIndex == optionIndex){
				itemPtr->setSelected(true);
			}
		}

		iprm::ISelectionParam* subSelectionPtr = selectionParamPtr->GetActiveSubselection();
		if (subSelectionPtr != NULL){
			CreateOptionsTree(subSelectionPtr, parentItemPtr);
		}
	}
}


} // namespace iqtprm


