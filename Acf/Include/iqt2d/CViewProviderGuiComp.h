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


#ifndef iqt2d_CViewProviderGuiComp_included
#define iqt2d_CViewProviderGuiComp_included


// ACF includes
#include "ibase/TCommandsProviderCompWrap.h"

#include "iqtgui/TGuiComponentBase.h"

#include "iview/CConsoleGui.h"

#include "iqt2d/IViewProvider.h"


namespace iqt2d
{


class CViewProviderGuiComp: 
			public	ibase::TCommandsProviderCompWrap<
						iqtgui::TGuiComponentBase<iview::CConsoleGui> >,
			virtual public IViewProvider
{
public:
	typedef ibase::TCommandsProviderCompWrap<
				iqtgui::TGuiComponentBase<iview::CConsoleGui> > BaseClass;

	I_BEGIN_COMPONENT(CViewProviderGuiComp);	
		I_REGISTER_INTERFACE(IViewProvider);
		I_ASSIGN(m_viewIdAttrPtr, "ViewId", "ID allowing identifying this view", true, 0);
		I_ASSIGN(m_useAntialiasingAttrPtr, "UseAntialiasing", "Enables using of antialiasing", false, false);
		I_ASSIGN(m_zoomToFitEnabledAttrPtr, "ZoomToFitEnabled", "If true, the shapes will be fit to the view according to the defined fitting mode", false, false);
		I_ASSIGN(m_useShapeEditCommandsAttrPtr, "UseShapeEditCommands", "If true, the commands for shape editing are available", false, false);
		I_ASSIGN(m_useGridCommandsAttrPtr, "UseGridCommands", "If true, the commands for grid mangement are available", false, false);
		I_ASSIGN(m_useScollBarCommandsAttrPtr, "UseScrollBarCommands", "If true, the commands for scroll bar management are available", false, false);
		I_ASSIGN(m_useStatusBarCommandsAttrPtr, "UseStatusBarCommands", "If true, the commands for status bar management are available", false, false);
		I_ASSIGN(m_fitModeAttrPtr, "FitMode", "Select fitting mode for the view. 0 - No fitting\n1 - Fit contents to view\n2 - Horizontal fit\n3 - Vertical fit\n4 - Both axes sclaled separately\n5 - Scale both axes proportional to display smallest AOI, which fully covers display", false, 0);
	I_END_COMPONENT;

	// reimplemented (ibase::ICommandsProvider)
	virtual const ibase::IHierarchicalCommand* GetCommands() const;

	// reimplemented (iqt2d::IViewProvider)
	virtual int GetViewId() const;
	virtual iview::IShapeView* GetView() const;

protected:
	// reimplemented (CGuiComponentBase)
	virtual void OnGuiCreated();

private:
	I_ATTR(int, m_viewIdAttrPtr);
	I_ATTR(bool, m_useAntialiasingAttrPtr);
	I_ATTR(bool, m_useShapeEditCommandsAttrPtr);
	I_ATTR(bool, m_useGridCommandsAttrPtr);
	I_ATTR(bool, m_useScollBarCommandsAttrPtr);
	I_ATTR(bool, m_useStatusBarCommandsAttrPtr);
	I_ATTR(bool, m_zoomToFitEnabledAttrPtr);
	I_ATTR(int, m_fitModeAttrPtr);
};


} // namespace iqt2d


#endif // !iqt2d_CViewProviderGuiComp_included


