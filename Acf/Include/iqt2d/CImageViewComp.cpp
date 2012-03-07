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


#include "iqt2d/CImageViewComp.h"


namespace iqt2d
{


// public methods

// reimplemented (ibase::ICommandsProvider)

const ibase::IHierarchicalCommand* CImageViewComp::GetCommands() const
{
	if (IsGuiCreated()){
		iview::CConsoleGui* consolePtr = GetQtWidget();
	
		return consolePtr->GetCommands();
	}

	return NULL;
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CImageViewComp::UpdateGui(int /*updateFlags*/)
{
	iview::CConsoleGui* consolePtr = GetQtWidget();
	I_ASSERT(consolePtr != NULL);

	consolePtr->UpdateView();

	if (m_fitOnStartAttrPtr.IsValid() && *m_fitOnStartAttrPtr){
		consolePtr->SetZoomToFit();
	}
}


// reimplemented (iqtui::CComponentBase)

void CImageViewComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	iview::CConsoleGui* consolePtr = GetQtWidget();
	I_ASSERT(consolePtr != NULL);

	iview::CConsoleGui::ViewImpl& view = consolePtr->GetViewRef();
	view.SetViewDraggable();

	view.ConnectBackgroundShape(this);
	view.ConnectCalibrationShape(&m_calibrationShape);
	view.SetCalibrationPtr(&m_calibration);
}


} // namespace iview


