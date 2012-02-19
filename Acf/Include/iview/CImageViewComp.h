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


#ifndef iview_CImageViewComp_included
#define iview_CImageViewComp_included


// ACF includes
#include "icomp/CComponentBase.h"

#include "iqtgui/TGuiComponentBase.h"
#include "iqtgui/TGuiObserverWrap.h"


// QSF includes
#include "iview/CImageShape.h"

#include "iview/CNoneCalibration.h"
#include "iview/CNoneCalibrationShape.h"
#include "iview/CConsoleGui.h"


namespace iview
{


/**
	Show observed bitmap on the 2D-console.
	This class extends standard 2D-console to provide background bitmap object.
*/
class CImageViewComp:
			public iqtgui::TGuiObserverWrap<
						iqtgui::TGuiComponentBase<iview::CConsoleGui>,
						iview::CImageShape>,
			virtual public ibase::ICommandsProvider
{
public:
	typedef iqtgui::TGuiObserverWrap<
				iqtgui::TGuiComponentBase<iview::CConsoleGui>,
				iview::CImageShape> BaseClass;

	I_BEGIN_COMPONENT(CImageViewComp);
		I_REGISTER_INTERFACE(imod::IObserver);
		I_REGISTER_INTERFACE(imod::IModelEditor);
		I_REGISTER_INTERFACE(ibase::ICommandsProvider);
		I_ASSIGN(m_showControlButtonsAttrPtr, "ShowControlButtons", "If true, control buttons will be shown", true, false);
	I_END_COMPONENT;

	// reimplemented (ibase::ICommandsProvider)
	virtual const ibase::IHierarchicalCommand* GetCommands() const;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags);
	virtual void OnGuiModelAttached();

private:
	I_ATTR(bool, m_showControlButtonsAttrPtr);
	iview::CNoneCalibration m_calibration;
	iview::CNoneCalibrationShape m_calibrationShape;
};


} // namespace iview


#endif // !iview_CImageViewComp_included


