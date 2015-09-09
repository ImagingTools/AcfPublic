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


#include "iqtprm/CCheckableOptionsEditorComp.h"


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QBoxLayout>
#else
#include <QtGui/QCheckBox>
#include <QtGui/QBoxLayout>
#endif

// ACF includes
#include "iprm/IOptionsList.h"


namespace iqtprm
{


// public methods

// reimplemented (imod::IModelEditor)

void CCheckableOptionsEditorComp::UpdateModel() const
{
	Q_ASSERT(IsGuiCreated());

	iprm::IOptionsManager* managerPtr = GetObservedObject();
	if (managerPtr == NULL){
		return;
	}

	istd::CChangeNotifier notifier(managerPtr);

	int optionsCount = managerPtr->GetOptionsCount();
	QWidget* widget = GetQtWidget();
	if (widget != NULL){
		for (int optionsIndex = 0; optionsIndex < optionsCount; optionsIndex++){
			QCheckBox* box = widget->findChild<QCheckBox *>(managerPtr->GetOptionName(optionsIndex));
			if (box != NULL){
				managerPtr->SetOptionEnabled(optionsIndex, box->isChecked());
			}
		}
	}
}


// protected slots

void CCheckableOptionsEditorComp::OnParameterChanged()
{
	DoUpdateModel();
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CCheckableOptionsEditorComp::UpdateGui(const istd::IChangeable::ChangeSet& changeSet)
{
	Q_ASSERT(IsGuiCreated());

	iprm::IOptionsManager* managerPtr = GetObservedObject();
	if (managerPtr == NULL){
		return;
	}

	QWidget* widgetPtr = GetQtWidget();

	if (widgetPtr == NULL){
		return;
	}

	if (		changeSet.Contains(iprm::IOptionsManager::CF_OPTION_ADDED) ||
				changeSet.Contains(iprm::IOptionsManager::CF_OPTION_REMOVED) ||
				changeSet.Contains(iprm::IOptionsManager::CF_OPTIONS_CHANGED) ||
				changeSet.Contains(iprm::IOptionsManager::CF_OPTION_RENAMED) ||
				changeSet.Contains(imod::IModelEditor::CF_INIT_EDITOR)){
		delete widgetPtr->layout();

		int optionCount = managerPtr->GetOptionsCount();

		QBoxLayout* layoutPtr = NULL;

		if (*m_useHorizontalLayoutAttrPtr){
			layoutPtr = new QHBoxLayout(widgetPtr);
		}
		else{
			layoutPtr = new QVBoxLayout(widgetPtr);
		}

		for (int optionIndex = 0; optionIndex < optionCount; optionIndex++){
			QCheckBox* checkBoxPtr = new QCheckBox(widgetPtr);
			checkBoxPtr->setObjectName(managerPtr->GetOptionName(optionIndex));

			checkBoxPtr->setText(managerPtr->GetOptionName(optionIndex));
			bool checkedState = managerPtr->IsOptionEnabled(optionIndex);
			checkBoxPtr->setChecked(checkedState);
			connect(checkBoxPtr, SIGNAL(stateChanged(int)), this, SLOT(OnParameterChanged()));

			layoutPtr->addWidget(checkBoxPtr);
		}
	}
	else{
		int optionsCount = managerPtr->GetOptionsCount();
		if (widgetPtr != NULL){
			for (int optionsIndex = 0; optionsIndex < optionsCount; optionsIndex++){
				QCheckBox* box = widgetPtr->findChild<QCheckBox *>(managerPtr->GetOptionName(optionsIndex));
				if (box != NULL){
					bool checkedState = managerPtr->IsOptionEnabled(optionsIndex);
					box->setChecked(checkedState);
				}
			}
		}
	}
}


} // namespace iqtprm


