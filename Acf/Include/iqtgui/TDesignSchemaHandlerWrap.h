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


// Qt includes
#include <QtCore/QObject>
#include <QtCore/QCoreApplication>

// ACF includes
#include <iqt/CDesignThemeEvent.h>


namespace iqtgui
{


template <class Base>
class TDesignSchemaHandlerWrap: public Base
{
public:
	typedef Base BaseClass;

	TDesignSchemaHandlerWrap();

	/**
		If enabled, listen to the design schema change events from the application context.
	*/
	virtual void EnableDesignHandler(bool enable = true);

protected:
	virtual void OnDesignSchemaChanged(const QByteArray& themeId) = 0;

private:
	class DesignSchemaEventsFilter: public QObject
	{
	public:
		typedef QObject BaseClass;

		explicit DesignSchemaEventsFilter(TDesignSchemaHandlerWrap& parent);

	protected:
		// reimplemented (QObject)
		bool eventFilter(QObject* sourcePtr, QEvent* eventPtr);

	private:
		TDesignSchemaHandlerWrap& m_parent;
	};

	DesignSchemaEventsFilter m_designSchemaEventsFilter;
	bool m_isFilterInstalled;
};


// public methods of class TDesignSchemaHandlerWrap

template <class Base>
TDesignSchemaHandlerWrap<Base>::TDesignSchemaHandlerWrap()
	:m_designSchemaEventsFilter(*this),
	m_isFilterInstalled(false)
{
}


template <class Base>
void TDesignSchemaHandlerWrap<Base>::EnableDesignHandler(bool enable)
{
	QCoreApplication* applicationPtr = QCoreApplication::instance();
	if (applicationPtr != NULL){
		if (enable){
			if (!m_isFilterInstalled){
				applicationPtr->installEventFilter(&m_designSchemaEventsFilter);

				m_isFilterInstalled = true;
			}
		}
		else{
			if (m_isFilterInstalled){
				applicationPtr->removeEventFilter(&m_designSchemaEventsFilter);

				m_isFilterInstalled = false;
			}
		}
	}
}


// public methods of the embedded class DesignSchemaEventsFilter

template <class Base>
TDesignSchemaHandlerWrap<Base>::DesignSchemaEventsFilter::DesignSchemaEventsFilter(TDesignSchemaHandlerWrap& parent)
	:m_parent(parent)
{
}


// protected methods of the embedded class DesignSchemaEventsFilter

// reimplemented (QObject)

template <class Base>
bool TDesignSchemaHandlerWrap<Base>::DesignSchemaEventsFilter::eventFilter(QObject* sourcePtr, QEvent* eventPtr)
{
	if (sourcePtr == QCoreApplication::instance()){
		if (eventPtr->type() == iqt::CDesignThemeEvent::s_eventType){
			const iqt::CDesignThemeEvent* designEventPtr = dynamic_cast<const iqt::CDesignThemeEvent*>(eventPtr);
			Q_ASSERT(designEventPtr != nullptr);

			m_parent.OnDesignSchemaChanged(designEventPtr->GetThemeId());
		}
	}

	return BaseClass::eventFilter(sourcePtr, eventPtr);
}


} // namespace iqtgui


