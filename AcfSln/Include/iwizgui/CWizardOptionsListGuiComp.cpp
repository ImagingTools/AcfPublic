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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iwizgui/CWizardOptionsListGuiComp.h"


// Qt includes
#include <QtGui/QHeaderView>

// ACF includes
#include "istd/TChangeNotifier.h"

#include "iqt/CSignalBlocker.h"


namespace iwizgui
{


// reimplemented (imod::IModelEditor)

void CWizardOptionsListGuiComp::UpdateModel() const
{
	I_ASSERT(IsGuiCreated());

	iprm::ISelectionParam* objectPtr = GetObjectPtr();
	I_ASSERT(objectPtr != NULL);

	QList<QTreeWidgetItem*> selectedItems = OptionsList->selectedItems();
	if (selectedItems.isEmpty()){
		objectPtr->SetSelectedOptionIndex(iprm::ISelectionParam::NO_SELECTION);
	}
	else{
		QTreeWidgetItem* selectedItemPtr = selectedItems.first();

		int selectedIndex = selectedItemPtr->data(0, DR_PAGE_INDEX).toInt();

		if (!objectPtr->SetSelectedOptionIndex(selectedIndex)){
			iqt::CSignalBlocker blocker(OptionsList);

			OptionsList->clearSelection();

			int currentSelected = objectPtr->GetSelectedOptionIndex();
			if ((currentSelected >= 0) && (currentSelected < OptionsList->topLevelItemCount())){
				QTreeWidgetItem* itemPtr = OptionsList->topLevelItem(currentSelected);
				itemPtr->setSelected(true);
			}
		}
	}
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CWizardOptionsListGuiComp::UpdateGui(int /*updateFlags*/)
{
	I_ASSERT(IsGuiCreated());

	OptionsList->clear();
	
	iwiz::IParamsManagerWizard* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		CreateOptionsTree(objectPtr);
	}
}


// reimplemented (CGuiComponentBase)

void CWizardOptionsListGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	QHeaderView* headerPtr = OptionsList->header();
	if (headerPtr != NULL){
		headerPtr->setStretchLastSection(true);
	}
}


// protected slots

void CWizardOptionsListGuiComp::on_OptionsList_itemSelectionChanged()
{
	DoUpdateModel();
}


// private methods

void CWizardOptionsListGuiComp::CreateOptionsTree(const iwiz::IParamsManagerWizard* paramsManagerPtr, QTreeWidgetItem* parentItemPtr)
{
	if (paramsManagerPtr != NULL){
		int selectedOptionIndex = paramsManagerPtr->GetSelectedOptionIndex();

		int pagesCount = paramsManagerPtr->GetParamsSetsCount();
		for (int pageIndex = 0; pageIndex < pagesCount; pageIndex++){
			QString optionName = paramsManagerPtr->GetParamsSetName(pageIndex);

			QTreeWidgetItem* itemPtr = new QTreeWidgetItem(OptionsList);
			itemPtr->setText(0, optionName);
			itemPtr->setData(0, DR_PAGE_INDEX, pageIndex);

			itemPtr->setDisabled(!paramsManagerPtr->IsPageSelectionAllowed(pageIndex));

			if (parentItemPtr != NULL){
				parentItemPtr->addChild(itemPtr);
			}
			else{
				OptionsList->addTopLevelItem(itemPtr);
			}

			if (selectedOptionIndex == pageIndex){
				itemPtr->setSelected(true);
			}
		}
	}
}


} // namespace iwizgui


