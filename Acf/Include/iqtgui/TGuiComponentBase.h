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


#ifndef iqtgui_TGuiComponentBase_included
#define iqtgui_TGuiComponentBase_included


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QWidget>
#else
#include <QtGui/QWidget>
#endif


// ACF includes
#include <iqtgui/CGuiComponentBase.h>


namespace iqtgui
{


/**	Base class for all Qt GUI componentes.
 */
template <class WidgetType>
class TGuiComponentBase: public CGuiComponentBase
{
public:
	typedef CGuiComponentBase BaseClass;

	TGuiComponentBase();

	virtual WidgetType* GetQtWidget() const;

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual QWidget* CreateQtWidget(QWidget* parentPtr);
};


// public methods

template <class WidgetType>
TGuiComponentBase<WidgetType>::TGuiComponentBase()
{
}


template <class WidgetType>
WidgetType* TGuiComponentBase<WidgetType>::GetQtWidget() const
{
	return dynamic_cast<WidgetType*>(GetWidget());
}


// reimplemented (iqtgui::CGuiComponentBase)

template <class WidgetType>
QWidget* TGuiComponentBase<WidgetType>::CreateQtWidget(QWidget* parentPtr)
{
	Q_ASSERT(!IsGuiCreated());

	WidgetType* widgetPtr = new WidgetType(parentPtr);

	return widgetPtr;
}


} // namespace iqtgui


#endif // !iqtgui_TGuiComponentBase_included


