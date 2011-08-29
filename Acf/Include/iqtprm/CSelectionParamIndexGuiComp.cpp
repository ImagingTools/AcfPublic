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


#include "iqtprm/CSelectionParamIndexGuiComp.h"


// Qt includes
#include <QFileDialog>


// ACF includes
#include "istd/TChangeNotifier.h"

#include "iprm/ISelectionConstraints.h"


namespace iqtprm
{


// reimplemented (imod::IModelEditor)

void CSelectionParamIndexGuiComp::UpdateModel() const
{
	I_ASSERT(IsGuiCreated());
	iprm::ISelectionParam* objectPtr = GetObjectPtr();
	I_ASSERT(objectPtr != NULL);

	int iterationCount = OptionIndexSpin->value();

	if (iterationCount != objectPtr->GetSelectedOptionIndex()){
		istd::CChangeNotifier notifier(objectPtr);

		objectPtr->SetSelectedOptionIndex(iterationCount);
	}
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CSelectionParamIndexGuiComp::UpdateGui(int /*updateFlags*/)
{
	I_ASSERT(IsGuiCreated());

	const iprm::ISelectionParam* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		int maxCount = 10;
		const iprm::ISelectionConstraints* constraintsPtr = objectPtr->GetSelectionConstraints();
		if (constraintsPtr != NULL){
			maxCount = constraintsPtr->GetOptionsCount() - 1;
		}

		OptionIndexSpin->setMaximum(maxCount);
		OptionIndexSlider->setMaximum(maxCount);

		OptionIndexSpin->setValue(objectPtr->GetSelectedOptionIndex());
	}
}


// protected slots

void CSelectionParamIndexGuiComp::on_OptionIndexSlider_valueChanged(int /*value*/)
{
	if (!IsUpdateBlocked()){
		UpdateBlocker updateBlocker(this);

		UpdateModel();
	}
}


} // namespace iqtprm

