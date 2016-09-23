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


#include <CAbGuiComp.h>


// ACF includes
#include <istd/CChangeGroup.h>


// Tutorial includes
#include <IAconstraints.h>


// reimplemented (imod::IModelEditor)

void CAbGuiComp::UpdateModel() const
{
	IAb* objectPtr = GetObservedObject();
	Q_ASSERT(objectPtr != NULL);

	istd::CChangeGroup changeGroup(objectPtr);
	Q_UNUSED(changeGroup);

	objectPtr->SetA(AValueSpinBox->value());
	objectPtr->SetB(BValueEdit->text().toLocal8Bit());
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CAbGuiComp::UpdateGui(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	Q_ASSERT(IsGuiCreated());

	IAb* objectPtr = GetObservedObject();
	if (objectPtr != NULL){
		AValueSpinBox->setValue(objectPtr->GetA());

		BValueEdit->setText(objectPtr->GetB());
	}
}

void CAbGuiComp::OnGuiModelAttached()
{
	// Set data model constraints to the editor of A:
	IAb* objectPtr = GetObservedObject();
	Q_ASSERT(objectPtr != NULL);

	const IAConstraints& constraints = objectPtr->GetAConstraints();
	AValueSpinBox->setMinimum(constraints.GetARange().GetMinValue());
	AValueSpinBox->setMaximum(constraints.GetARange().GetMaxValue());

	// Call basic functionality:
	BaseClass::OnGuiModelAttached();
}


// reimplemented (CGuiComponentBase)

void CAbGuiComp::OnGuiCreated()
{
	// Connect signal from A editor:
	connect(AValueSpinBox, SIGNAL(valueChanged(int)), this, SLOT(OnAValueChanged(int)));

	// Connect signal from B editor:
	connect(BValueEdit, SIGNAL(textEdited(const QString&)), this, SLOT(OnBValueChanged(const QString&)));

	BaseClass::OnGuiCreated();
}


// private slots

void CAbGuiComp::OnAValueChanged(int /*value*/)
{
	DoUpdateModel();
}


void CAbGuiComp::OnBValueChanged(const QString& /*value*/)
{
	DoUpdateModel();
}


