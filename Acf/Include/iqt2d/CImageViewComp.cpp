/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#include <iqt2d/CImageViewComp.h>


// ACF includes
#include <iimg/IRasterImage.h>


namespace iqt2d
{


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CImageViewComp::UpdateGui(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	iview::CConsoleGui* consolePtr = GetQtWidget();
	Q_ASSERT(consolePtr != NULL);

	const iimg::IRasterImage* imagePtr = dynamic_cast<const iimg::IRasterImage*>(GetObservedModel());
	if (imagePtr != NULL){
		i2d::CRectangle areaRect(imagePtr->GetImageSize());

		consolePtr->GetViewRef().SetFitArea(areaRect);
	}

	SetTransformMode(STM_VIEW);

	iview::CCalibratedViewBase* calibratableViewPtr = dynamic_cast<iview::CCalibratedViewBase*>(GetView());
	if (calibratableViewPtr != nullptr){
		const i2d::ICalibration2d* imageCalibrationPtr = imagePtr ? imagePtr->GetCalibration() : nullptr;
		istd::TUniqueInterfacePtr<i2d::ICalibration2d> displayCalibrationPtr;
		if (imageCalibrationPtr != nullptr) {
			displayCalibrationPtr.MoveCastedPtr<istd::IChangeable>(imageCalibrationPtr->CloneMe());
		}

		calibratableViewPtr->SetDisplayCalibration(displayCalibrationPtr.GetPtr());

		// this is supposed to die after the next clone
		m_oldCalibrationPtr = std::move(displayCalibrationPtr);
	}

	consolePtr->UpdateView();
}


// reimplemented (iqtui::CComponentBase)

void CImageViewComp::OnGuiModelAttached()
{
	iview::CConsoleGui* consolePtr = GetQtWidget();
	Q_ASSERT(consolePtr != NULL);

	iview::CViewport& view = consolePtr->GetViewRef();
	view.SetViewDraggable();

	AssignToLayer(iview::IViewLayer::LT_BACKGROUND);

	view.ConnectShape(this);

	BaseClass::OnGuiModelAttached();
}


void CImageViewComp::OnGuiModelDetached()
{
	iview::CConsoleGui* consolePtr = GetQtWidget();
	Q_ASSERT(consolePtr != NULL);

	iview::CViewport& view = consolePtr->GetViewRef();

	view.DisconnectShape(this);

	BaseClass::OnGuiModelDetached();
}


} // namespace iview


