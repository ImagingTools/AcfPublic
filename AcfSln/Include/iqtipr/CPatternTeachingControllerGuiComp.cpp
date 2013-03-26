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


#include "iqtipr/CPatternTeachingControllerGuiComp.h"


// Qt includes
#include <QtGui/QMessageBox>


namespace iqtipr
{


// protected slots

void CPatternTeachingControllerGuiComp::on_LearnButton_clicked()
{
	iipr::IPatternController* objectPtr = GetObjectPtr();
	Q_ASSERT(objectPtr != NULL);

	if (objectPtr->IsPatternValid()){
		int result = QMessageBox::question(
					GetQtWidget(), 
					tr("Replace pattern"),
					tr("The pattern data exists already. Do you want to replace them?"),
					QMessageBox::Ok | QMessageBox::Cancel);

		if (result != QMessageBox::Ok){
			return;
		}
	}

	if (!objectPtr->TeachPattern()){
		QMessageBox::critical(
					GetQtWidget(),
					tr("Error"), 
					tr("Cannot learn pattern"));

		return;
	}
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CPatternTeachingControllerGuiComp::UpdateGui(int /*updateFlags*/)
{
	iipr::IPatternController* objectPtr = GetObjectPtr();
	if (objectPtr == NULL){
		return;
	}

	if (!objectPtr->IsPatternValid()){
		PatternInfoLabel->setText(tr("Reference pattern not defined"));
		PatternInfoLabel->setStyleSheet("color: red;");
	}
	else{
		PatternInfoLabel->setText(tr("Reference pattern defined"));		
		PatternInfoLabel->setStyleSheet("color: darkgreen;");
	}
}


// reimplemented (iqt::CGuiObjectBase)

void CPatternTeachingControllerGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	if (GetObjectPtr() == NULL){
		LearnButton->setVisible(false);
	}
}


} // namespace iqtipr


