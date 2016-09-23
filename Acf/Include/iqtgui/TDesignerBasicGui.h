/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqtgui_TDesignerBasicGui_included
#define iqtgui_TDesignerBasicGui_included


// Qt includes
#include <QtCore/QMetaObject>

// ACF includes
#include <iqtgui/TGuiComponentBase.h>


namespace iqtgui
{


/**
	Simple integration of designer-generated GUI with QT widget class.
 */
template <class UI, class WidgetType = QDialog>
class TDesignerBasicGui: public WidgetType, public UI
{
public:
	typedef WidgetType BaseClass;

	TDesignerBasicGui(QWidget* parentPtr = 0, Qt::WindowFlags f = 0);
};


// public methods

// reimplemented (iqtgui::CGuiComponentBase)

template <class UI, class WidgetType>
TDesignerBasicGui<UI, WidgetType>::TDesignerBasicGui(QWidget* parentPtr, Qt::WindowFlags f)
:	BaseClass(parentPtr, f)
{
	UI::setupUi(this);
}


} // namespace iqtgui


#endif // !iqtgui_TDesignerBasicGui_included


