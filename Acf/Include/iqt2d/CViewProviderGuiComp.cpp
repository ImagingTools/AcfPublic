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


#include "iqt2d/CViewProviderGuiComp.h"


namespace iqt2d
{


// public methods

// reimplemented (ibase::ICommandsProvider)

const ibase::IHierarchicalCommand* CViewProviderGuiComp::GetCommands() const
{
	if (IsGuiCreated()){
		iview::CConsoleGui* consolePtr = GetQtWidget();
	
		return consolePtr->GetCommands();
	}

	return NULL;
}


// reimplemented (iqt2d::IViewProvider)

int CViewProviderGuiComp::GetViewId() const
{
	I_ASSERT(m_viewIdAttrPtr.IsValid());

	return *m_viewIdAttrPtr;
}


iview::IShapeView* CViewProviderGuiComp::GetView() const
{
	iview::CConsoleGui* consolePtr = GetQtWidget();
	if (consolePtr != NULL){
		return &consolePtr->GetViewRef();
	}

	return NULL;
}


// protected methods

void CViewProviderGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	iview::CConsoleGui* consolePtr = GetQtWidget();
	I_ASSERT(consolePtr != NULL);

	// Setup view and its calibration:
	iview::CViewport& view = consolePtr->GetViewRef();
	view.SetViewDraggable();

	if (m_fitModeAttrPtr.IsValid()){
		iview::CConsoleBase::FitMode fitMode = iview::CConsoleBase::FitMode(*m_fitModeAttrPtr);

		consolePtr->SetFitMode(fitMode);
	}

	if (m_zoomToFitEnabledAttrPtr.IsValid()){
		consolePtr->SetZoomToFit(*m_zoomToFitEnabledAttrPtr);
	}

	// shape edit commands
	bool useShapeEditCommands = false;
	if (m_useShapeEditCommandsAttrPtr.IsValid()){
		useShapeEditCommands = *m_useShapeEditCommandsAttrPtr;
	}
	consolePtr->SetPolylineButtonsVisible(useShapeEditCommands);

	// grid commands
	bool useGridCommands = false;
	if (m_useGridCommandsAttrPtr.IsValid()){
		useGridCommands = *m_useGridCommandsAttrPtr;
	}
	consolePtr->SetGridButtonVisible(useGridCommands);
	consolePtr->SetMmButtonVisible(useGridCommands);

	// scrollbar commands
	bool useScrollBarCommands = false;
	if (m_useScollBarCommandsAttrPtr.IsValid()){
		useScrollBarCommands = *m_useScollBarCommandsAttrPtr;
	}
	consolePtr->SetScrollbarsButtonVisible(useScrollBarCommands);

	// status bar commands
	bool useStatusBarCommands = false;
	if (m_useStatusBarCommandsAttrPtr.IsValid()){
		useStatusBarCommands = *m_useStatusBarCommandsAttrPtr;
	}
	consolePtr->SetStatusButtonVisible(useStatusBarCommands);
}


} // namespace iqt2d


