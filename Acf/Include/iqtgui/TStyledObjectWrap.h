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


#pragma once


// ACF includes
#include <iqtgui/iqtgui.h>
#include <iqtgui/CIconProvider.h>
#include <iqt/CDesignThemeEvent.h>

// Qt includes
#include <QtWidgets/QWidget>
#include <QtCore/QCoreApplication>


namespace iqtgui
{

/**
	Wrapper for QWidget (or any QObject in general) which reacts to global style (DesignSchema) change event
	and provides helper methods for icons
 */
template <class Base>
class TStyledObjectWrap: public Base, public CIconProvider
{
	static_assert(std::is_base_of_v<QObject, Base>, "TStyledObjectWrap must wrap a QObject derived class");

	typedef Base BaseClass;

protected:

	template<typename... Args>
	TStyledObjectWrap(Args&&... args)
		: Base(std::forward<Args>(args)...)
	{
		EnableDesignHandler(true);
	}

	virtual void OnDesignChanged() = 0;
	
	void EnableDesignHandler(bool enable)
	{
		auto* app = QCoreApplication::instance();
		if (app != nullptr){
			if (enable){
				app->installEventFilter(this);
			}
			else{
				app->removeEventFilter(this);
			}
		}
	}

	// reimplemented (QObject)
	virtual bool eventFilter(QObject* sourcePtr, QEvent* eventPtr) override
	{
		if (sourcePtr == QCoreApplication::instance()){
			if (eventPtr->type() == iqt::CDesignThemeEvent::s_eventType){
				Q_ASSERT(dynamic_cast<const iqt::CDesignThemeEvent*>(eventPtr) != nullptr);
				auto* designEventPtr = static_cast<const iqt::CDesignThemeEvent*>(eventPtr);
				
				SetThemeId(designEventPtr->GetThemeId());
				OnDesignChanged();
			}
		}

		return BaseClass::eventFilter(sourcePtr, eventPtr);
	}

};


using StyledWidget = TStyledObjectWrap<QWidget>;


} // namespace iqtgui


