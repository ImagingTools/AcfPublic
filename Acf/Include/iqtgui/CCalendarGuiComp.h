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


#ifndef iqtgui_CCalendarGuiComp_included
#define iqtgui_CCalendarGuiComp_included


// ACF includes
#include <iqtgui/TDesignerGuiCompBase.h>

#include <GeneratedFiles/iqtgui/ui_CCalendarGuiComp.h>


namespace iqtgui
{


/**
	Component for displaying a calendar.
*/
class CCalendarGuiComp: public iqtgui::TDesignerGuiCompBase<Ui::CCalendarGuiComp>
{
	Q_OBJECT
public:
	typedef iqtgui::TDesignerGuiCompBase<Ui::CCalendarGuiComp> BaseClass;

	I_BEGIN_COMPONENT(CCalendarGuiComp);
	I_END_COMPONENT;

protected:
	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiRetranslate();
};


} // namespace iqtgui


#endif // !iqtgui_CCalendarGuiComp_included


