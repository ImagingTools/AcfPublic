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


#include <iwidgets/CFocusDecorator.h>


namespace iwidgets
{


// public methods

CFocusDecorator::CFocusDecorator(QObject* parentPtr)
	:QObject(parentPtr)
{
}


CFocusDecorator::~CFocusDecorator()
{
	UnregisterAllWidgets();
}


bool CFocusDecorator::RegisterWidget(QWidget* widgetPtr, GraphicsEffectFactory* factoryPtr)
{
	if (widgetPtr == NULL){
		return false;
	}

	if (m_widgetEffectsMap.contains(widgetPtr)){
		return true;
	}

	widgetPtr->installEventFilter(this);

	connect(widgetPtr, SIGNAL(destroyed(QObject*)), this, SLOT(OnObjectDestroyed(QObject*)));

	m_widgetEffectsMap[widgetPtr] = factoryPtr;

	return true;
}


void CFocusDecorator::UnregisterWidget(QWidget* widgetPtr)
{
	if (widgetPtr == NULL){
		return;
	}

	if (m_widgetEffectsMap.contains(widgetPtr)){
		widgetPtr->removeEventFilter(this);

		widgetPtr->setGraphicsEffect(NULL);

		m_widgetEffectsMap.remove(widgetPtr);
	}
}


void CFocusDecorator::UnregisterAllWidgets()
{
	while(!m_widgetEffectsMap.isEmpty()){
		QWidget* widgetPtr = dynamic_cast<QWidget*>(m_widgetEffectsMap.begin().key());

		UnregisterWidget(widgetPtr);
	}
}


// protected methods

// reimplemented (QObject)

bool CFocusDecorator::eventFilter(QObject* objectPtr, QEvent* eventPtr)
{
	if (objectPtr != NULL && eventPtr != NULL){
		int eventType = eventPtr->type();
		switch (eventType){
			case QEvent::FocusIn:{
				QWidget* widgetPtr = dynamic_cast<QWidget*>(objectPtr);
				if (widgetPtr != NULL){
					GraphicsEffectFactory* factoryPtr = m_widgetEffectsMap.value(widgetPtr, NULL);
					if (factoryPtr != NULL){
						widgetPtr->setGraphicsEffect(factoryPtr->CreateInstance());
					}
				}
				break;
			}

			case QEvent::FocusOut:{
				QWidget* widgetPtr = dynamic_cast<QWidget*>(objectPtr);
				if (widgetPtr != NULL){
					widgetPtr->setGraphicsEffect(NULL);
				}
				break;
			}

			case QEvent::Close:{
				QWidget* widgetPtr = dynamic_cast<QWidget*>(objectPtr);
				if (widgetPtr != NULL){
					m_widgetEffectsMap.remove(widgetPtr);
				}
				break;
			}
		}
	}

	return QObject::eventFilter(objectPtr, eventPtr);
}


// private slots

void CFocusDecorator::OnObjectDestroyed(QObject* objectPtr)
{
	objectPtr->removeEventFilter(this);

	m_widgetEffectsMap.remove(objectPtr);
}


} // namespace iwidgets
