/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#include "iqtcntl/CAutomaticControllerGuiComp.h"


namespace iqtcntl
{


// reimplemented (imod::IModelEditor)

void CAutomaticControllerGuiComp::UpdateModel() const
{
	I_ASSERT(IsGuiCreated());

	icntl::IAutomaticController* modelPtr = GetObjectPtr();
	I_ASSERT(modelPtr != NULL);

	modelPtr->SetWorkMode(AutomaticButton->isChecked()? icntl::IAutomaticController::WM_AUTOMATIC: icntl::IAutomaticController::WM_MANUAL);
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CAutomaticControllerGuiComp::UpdateGui(int /*updateFlags*/)
{
	I_ASSERT(IsGuiCreated());

	const icntl::IAutomaticController* modelPtr = GetObjectPtr();
	if (IsGuiCreated() && (modelPtr != NULL)){
		AutomaticButton->setChecked(modelPtr->GetWorkMode() == icntl::IAutomaticController::WM_AUTOMATIC);
	}
}


// protected slots

void CAutomaticControllerGuiComp::on_AutomaticButton_toggled(bool /*checked*/)
{
	if (!IsUpdateBlocked()){
		UpdateBlocker blockUpdate(this);

		UpdateModel();
	}
}


} // namespace iqtcntl


