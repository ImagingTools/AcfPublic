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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iqtmm_CPlaybackControllerGuiComp_included
#define iqtmm_CPlaybackControllerGuiComp_included


// Qt includes
#include <QtCore/QTimer>

// ACF includes
#include "iqtgui/TDesignerGuiObserverCompBase.h"

// ACF-Solutions includes
#include "imm/IVideoController.h"

#include "Generated/ui_CPlaybackControllerGuiComp.h"


namespace iqtmm
{


/**
	Component to play some image (frame) sequence from a directory.
*/
class CPlaybackControllerGuiComp:
			public iqtgui::TDesignerGuiObserverCompBase<Ui::CPlaybackControllerGuiComp, imm::IVideoController>
{
	Q_OBJECT
public:
	typedef iqtgui::TDesignerGuiObserverCompBase<Ui::CPlaybackControllerGuiComp, imm::IVideoController> BaseClass;

	I_BEGIN_COMPONENT(CPlaybackControllerGuiComp);
		I_ASSIGN(m_showPlayButtonAttrPtr, "ShowPlayButton", "Allow to display play button", true, true);
		I_ASSIGN(m_showPositionSliderAttrPtr, "ShowPositionSlider", "Shows and allows edit position slider", true, true);
		I_ASSIGN(m_showTimePositionAttrPtr, "ShowTimePosition", "Shows and allows edit current time position", true, false);
		I_ASSIGN(m_showFrameIndexAttrPtr, "ShowFrameIndex", "Shows and allows edit current frame index", true, false);
		I_ASSIGN(m_showRepeatButtonAttrPtr, "ShowRepeatButton", "Allow to display play button", true, true);
	I_END_COMPONENT;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags = 0);

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private Q_SLOTS:
	void OnTimerTick();

private Q_SLOTS:
	void on_PlayButton_toggled(bool isToggled);
	void on_PositionSlider_valueChanged(int position);
	void on_FrameIndexSB_valueChanged(int position);
	void on_TimeEdit_editingFinished();

private:
	QTimer m_playTimer;
	int m_currentFrameIndex;

	I_ATTR(bool, m_showPlayButtonAttrPtr);
	I_ATTR(bool, m_showPositionSliderAttrPtr);
	I_ATTR(bool, m_showTimePositionAttrPtr);
	I_ATTR(bool, m_showFrameIndexAttrPtr);
	I_ATTR(bool, m_showRepeatButtonAttrPtr);
};


} // namespace iqtmm


#endif // !iqtmm_CPlaybackControllerGuiComp_included

