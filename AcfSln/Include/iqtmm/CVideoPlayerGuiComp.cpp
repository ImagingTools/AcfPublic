/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#include "iqtmm/CVideoPlayerGuiComp.h"


namespace iqtmm
{


// public methods

// reimplemented (iqtgui::CGuiComponentBase)

void CVideoPlayerGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	if (m_urlParamsGuiCompPtr.IsValid() && m_urlParamModelCompPtr.IsValid()){
		m_urlParamsGuiCompPtr->CreateGui(UrlParamFrame);

		UrlParamFrame->setVisible(true);
	}
	else{
		UrlParamFrame->setVisible(false);
	}

	if (m_controllerBarGuiCompPtr.IsValid()){
		m_controllerBarGuiCompPtr->CreateGui(ControllerBarFrame);

		ControllerBarFrame->setVisible(true);
	}
	else{
		ControllerBarFrame->setVisible(false);
	}

	if (m_videoGuiCompPtr.IsValid()){
		m_videoGuiCompPtr->CreateGui(FrameView);
	}
}


void CVideoPlayerGuiComp::OnGuiDestroyed()
{
	if (m_mediaControllerCompPtr.IsValid()){
		m_mediaControllerCompPtr->CloseMedium();
	}

	if (m_controllerBarGuiCompPtr.IsValid() && m_controllerBarGuiCompPtr->IsGuiCreated()){
		m_controllerBarGuiCompPtr->DestroyGui();
	}

	if (m_videoGuiCompPtr.IsValid() && m_videoGuiCompPtr->IsGuiCreated()){
		m_videoGuiCompPtr->DestroyGui();
	}

	if (m_urlParamsGuiCompPtr.IsValid() && m_urlParamsGuiCompPtr->IsGuiCreated()){
		m_urlParamsGuiCompPtr->DestroyGui();
	}

	BaseClass::OnGuiDestroyed();
}


// protected methods

// reimplemented (imod::CSingleModelObserverBase)

void CVideoPlayerGuiComp::OnUpdate(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	if (m_mediaControllerCompPtr.IsValid() && m_urlParamCompPtr.IsValid()){
		m_mediaControllerCompPtr->OpenMediumUrl(m_urlParamCompPtr->GetPath(), false);
	}
}


// reimplemented (icomp::CComponentBase)

void CVideoPlayerGuiComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_urlParamModelCompPtr.IsValid()){
		m_urlParamModelCompPtr->AttachObserver(this);
	}
}


void CVideoPlayerGuiComp::OnComponentDestroyed()
{
	if (m_urlParamModelCompPtr.IsValid()){
		m_urlParamModelCompPtr->DetachObserver(this);
	}

	BaseClass::OnComponentDestroyed();
}


} // namespace iqtmm


