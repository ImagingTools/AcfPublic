/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqtgui_TDesignerGuiCompBase_included
#define iqtgui_TDesignerGuiCompBase_included


// Qt includes
#include <QtCore/qmetaobject.h>


// ACF includes
#include "iqtgui/TGuiComponentBase.h"


namespace iqtgui
{


/**
	Base class for all Qt GUI componentes, which use the Qt designer's UI.
 */
template <class UI, class WidgetType = QWidget>
class TDesignerGuiCompBase: public TGuiComponentBase<WidgetType>, public UI
{
public:
	typedef TGuiComponentBase<WidgetType> BaseClass;

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual QWidget* InitWidgetToParent(QWidget* parentPtr);

protected:
	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiRetranslate();
};


// public methods

// reimplemented (iqtgui::CGuiComponentBase)

template <class UI, class WidgetType>
QWidget* TDesignerGuiCompBase<UI, WidgetType>::InitWidgetToParent(QWidget* parentPtr)
{
	Q_ASSERT(!BaseClass::IsGuiCreated());

	QWidget* widgetPtr = BaseClass::InitWidgetToParent(parentPtr);

	WidgetType* concreteWidgetPtr = dynamic_cast<WidgetType*>(widgetPtr);
	Q_ASSERT(concreteWidgetPtr != NULL);

	UI::setupUi(concreteWidgetPtr);

	return concreteWidgetPtr;
}


// protected methods

// reimplemented (iqtgui::CGuiComponentBase)

template <class UI, class WidgetType>
void TDesignerGuiCompBase<UI, WidgetType>::OnGuiRetranslate()
{
	WidgetType* widgetPtr = dynamic_cast<WidgetType*>(BaseClass::GetWidget());
	if (widgetPtr != NULL){
		UI::retranslateUi(widgetPtr);
	}

	BaseClass::OnGuiRetranslate();
}


} // namespace iqtgui


#endif // !iqtgui_TDesignerGuiCompBase_included


