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


#ifndef iqtmm_CVideoPlayerGuiComp_included
#define iqtmm_CVideoPlayerGuiComp_included


// ACF includes
#include "imod/IModel.h"
#include "imod/CSingleModelObserverBase.h"
#include "ifile/IFileNameParam.h"
#include "iqtgui/TDesignerGuiCompBase.h"

// ACF-Solutions includes
#include "imm/IMediaController.h"

#include "GeneratedFiles/iqtmm/ui_CVideoPlayerGuiComp.h"


namespace iqtmm
{


/**
	GUI component used to display video player.
*/
class CVideoPlayerGuiComp:
			public iqtgui::TDesignerGuiCompBase<Ui::CVideoPlayerGuiComp>,
			protected imod::CSingleModelObserverBase
{
public:
	typedef iqtgui::TDesignerGuiCompBase<Ui::CVideoPlayerGuiComp> BaseClass;

	I_BEGIN_COMPONENT(CVideoPlayerGuiComp);
		I_ASSIGN(m_mediaControllerCompPtr, "MediaController", "Controller used to open and display media", true, "MediaController");
		I_ASSIGN(m_videoGuiCompPtr, "VideoGui", "View for a video display", true, "VideoGui");
		I_ASSIGN(m_urlParamsGuiCompPtr, "UrlGui", "Sequence directory selection GUI", false, "UrlGui");
		I_ASSIGN(m_controllerBarGuiCompPtr, "ControllerBarGui", "Displayed on the bottom used typically to controll of playback", false, "ControllerBarGui");
		I_ASSIGN(m_urlParamCompPtr, "UrlParams", "Parameter storing media URL or file or directory", true, "UrlParams");
		I_ASSIGN_TO(m_urlParamModelCompPtr, m_urlParamCompPtr, true);
	I_END_COMPONENT;

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiDestroyed();

protected:
	// reimplemented (imod::CSingleModelObserverBase)
	virtual void OnUpdate(int updateFlags, istd::IPolymorphic* updateParamsPtr);

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_REF(imm::IMediaController, m_mediaControllerCompPtr);
	I_REF(iqtgui::IGuiObject, m_videoGuiCompPtr);
	I_REF(iqtgui::IGuiObject, m_urlParamsGuiCompPtr);
	I_REF(iqtgui::IGuiObject, m_controllerBarGuiCompPtr);
	I_REF(ifile::IFileNameParam, m_urlParamCompPtr);
	I_REF(imod::IModel, m_urlParamModelCompPtr);
};


} // namespace iqtmm


#endif // !iqtmm_CVideoPlayerGuiComp_included

