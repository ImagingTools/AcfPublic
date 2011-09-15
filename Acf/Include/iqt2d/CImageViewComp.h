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


#ifndef iqt2d_CImageViewComp_included
#define iqt2d_CImageViewComp_included


#include "iqtgui/TGuiObserverWrap.h"

#include "iqt2d/CImageShape.h"
#include "iqt2d/CSceneProviderGuiComp.h"


namespace iqt2d
{


/**
	Show observed bitmap on the scene.
	This class extends standard scene provider to provide background bitmap object.
*/
class CImageViewComp: public iqtgui::TGuiObserverWrap<CSceneProviderGuiComp, CImageShape>
{
public:
	typedef iqtgui::TGuiObserverWrap<CSceneProviderGuiComp, CImageShape> BaseClass;

	I_BEGIN_COMPONENT(CImageViewComp);
		I_REGISTER_INTERFACE(imod::IObserver);
		I_ASSIGN(m_isFrameVisibleAttrPtr, "IsImageFrameVisible", "If true, image frame will be visible", true, false);
		I_ASSIGN(m_imagePositionModeAttrPtr, "ImagePositionMode", "Mode of image position:\n 0 - corner\n 1 - center", true, 0);
		I_ASSIGN(m_fitToViewOnChangeAttrPtr, "FitToViewOnImageChanges", "Fit the current image to view", false, false);
	I_END_COMPONENT;

	// reimplemented (imod::IObserver)
	virtual bool OnDetached(imod::IModel* modelPtr);

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags = 0);

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiDestroyed();

private:
	I_ATTR(bool, m_isFrameVisibleAttrPtr);
	I_ATTR(int, m_imagePositionModeAttrPtr);
	I_ATTR(bool, m_fitToViewOnChangeAttrPtr);
};


} // namespace iqt2d


#endif // !iqt2d_CImageViewComp_included


