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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqtgui_TDesignerGuiObserverCompBase_included
#define iqtgui_TDesignerGuiObserverCompBase_included


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QWidget>
#else
#include <QtGui/QWidget>
#endif

// ACF includes
#include "imod/TSingleModelObserverBase.h"
#include "ibase/TModelObserverCompWrap.h"
#include "iqtgui/TGuiObserverWrap.h"
#include "iqtgui/TDesignerGuiCompBase.h"


namespace iqtgui
{


/**
	Base class for all Qt GUI components.

	\ingroup ModelObserver
 */
template <class UI, class Model, class WidgetType = QWidget>
class TDesignerGuiObserverCompBase:
			public ibase::TModelObserverCompWrap<
						iqtgui::TGuiObserverWrap< iqtgui::TDesignerGuiCompBase<UI, WidgetType>, imod::TSingleModelObserverBase<Model> > >
{
public:
	typedef ibase::TModelObserverCompWrap<
				iqtgui::TGuiObserverWrap< iqtgui::TDesignerGuiCompBase<UI, WidgetType>, imod::TSingleModelObserverBase<Model> > > BaseClass;

	I_BEGIN_BASE_COMPONENT(TDesignerGuiObserverCompBase);
		I_REGISTER_INTERFACE(imod::IModelEditor);
	I_END_COMPONENT;
};


} // namespace iqtgui


#endif // !iqtgui_TDesignerGuiObserverCompBase_included


