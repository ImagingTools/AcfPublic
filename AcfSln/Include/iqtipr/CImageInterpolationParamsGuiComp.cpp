/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include <iqtipr/CImageInterpolationParamsGuiComp.h>


// ACF includes
#include <istd/CChangeGroup.h>


namespace iqtipr
{


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CImageInterpolationParamsGuiComp::UpdateModel() const
{
	Q_ASSERT(IsGuiCreated());

	iipr::IImageInterpolationParams* objectPtr = GetObservedObject();
	if (objectPtr != NULL){
		istd::CChangeGroup changeGroup(objectPtr);
		Q_UNUSED(changeGroup);

		int currentIndex = InterpolationModeCombo->currentIndex();

		objectPtr->SetInterpolationMode(InterpolationModeCombo->itemData(currentIndex).toInt());
	}
}


void CImageInterpolationParamsGuiComp::UpdateGui(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	Q_ASSERT(IsGuiCreated());

	iipr::IImageInterpolationParams* objectPtr = GetObservedObject();
	if (objectPtr != NULL){
		int mode = objectPtr->GetInterpolationMode();
		switch (mode)
		{
		case iipr::IImageInterpolationParams::IM_NO_INTERPOLATION:
			InterpolationModeCombo->setCurrentIndex(0);
			break;

		case iipr::IImageInterpolationParams::IM_BILINEAR:
			InterpolationModeCombo->setCurrentIndex(1);
			break;

		case iipr::IImageInterpolationParams::IM_BICUBIC:
			InterpolationModeCombo->setCurrentIndex(2);
			break;
		}
	}
}


// reimplemented (iqtgui::CGuiComponentBase)

void CImageInterpolationParamsGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();
}


void CImageInterpolationParamsGuiComp::OnGuiRetranslate()
{
	BaseClass::OnGuiRetranslate();

	InterpolationModeCombo->setItemData(0, iipr::IImageInterpolationParams::IM_NO_INTERPOLATION);
	InterpolationModeCombo->setItemData(1, iipr::IImageInterpolationParams::IM_BILINEAR);
	InterpolationModeCombo->setItemData(2, iipr::IImageInterpolationParams::IM_BICUBIC);
}


// protected slots

void CImageInterpolationParamsGuiComp::on_InterpolationModeCombo_currentIndexChanged(int /*index*/)
{
	DoUpdateModel();
}


} // namespace iqtipr


