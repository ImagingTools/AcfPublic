#include "iqtgui/CTextElider.h"


// Qt includes
#include <QVariant>
#include <QFont>
#include <QFontMetrics>
#include <QEvent>


// ACF includes
#include "istd/istd.h"


namespace iqtgui
{


// public methods

CTextElider::CTextElider(QObject* parentPtr)
		:	QObject(parentPtr),
			m_updateInterval(300),
			m_addition("...")
{
	m_textObservingTimer.installEventFilter(this);
}


CTextElider::~CTextElider()
{
	m_textObservingTimer.removeEventFilter(this);
	RemoveAllElideObjects();
}


// reimplemented (QObject)

bool CTextElider::eventFilter(QObject* objectPtr, QEvent* eventPtr)
{
	if (objectPtr != NULL && eventPtr != NULL){
		int eventType = eventPtr->type();
		switch (eventType){
			case QEvent::Resize:{
				QObject* elideObject = dynamic_cast<QObject*>(objectPtr);
				UpdateElidedText(*elideObject);
				break;
			}
			case QEvent::Timer:{
				QTimerEvent* timerEventPtr = dynamic_cast<QTimerEvent*>(eventPtr);
				if (timerEventPtr->timerId() == m_textObservingTimer.timerId()){
					OnTimeout();
				}
			}
		}
	}

	return QObject::eventFilter(objectPtr, eventPtr);
}


bool CTextElider::InsertElideObject(QObject* elideObject)
{
	bool insertPossible = !m_objectPtrMap.contains(elideObject);
	insertPossible = insertPossible && elideObject != NULL;
	I_ASSERT(insertPossible);

	if (insertPossible){
		ElideObjectInfo info;
		info.baseString = info.elideString = elideObject->property("text").value<QString>();
		elideObject->installEventFilter(this);
		m_objectPtrMap.insert(elideObject, info);

		UpdateElidedText(*elideObject);

		if (!m_textObservingTimer.isActive()){
			m_textObservingTimer.start(m_updateInterval);
		}
	}

	return insertPossible;
}


void CTextElider::RemoveElideObject(QObject* elideObject)
{
	if (elideObject == NULL){
		I_CRITICAL();

		return;
	}

	I_ASSERT(m_objectPtrMap.contains(elideObject));
	if (m_objectPtrMap.contains(elideObject)){
		elideObject->removeEventFilter(this);
	}

	m_objectPtrMap.remove(elideObject);
	if (m_textObservingTimer.isActive() && m_objectPtrMap.isEmpty()){
		m_textObservingTimer.stop();
	}
}


void CTextElider::RemoveAllElideObjects()
{
	while(!m_objectPtrMap.isEmpty()){
		QObject* objectPtr = m_objectPtrMap.begin().key();

		RemoveElideObject(objectPtr);
	}
}


void CTextElider::SetUpdateInterval(int miliseconds)
{
	if (m_updateInterval != miliseconds){
		m_updateInterval = miliseconds;
		
		m_textObservingTimer.setInterval(m_updateInterval);
	}
}


void CTextElider::SetAddition(QString addition)
{
	m_addition = addition;
}


QString CTextElider::GetAddition() const
{
	return m_addition;
}


// private methods

void CTextElider::UpdateElidedText(QObject& elideObject)
{
	QString elideText = elideObject.property("text").value<QString>();
	ElideObjectInfo& info = const_cast<ElideObjectInfo&>(m_objectPtrMap.find(&elideObject).value());

	QString newName = elideText;
	int newSize = newName.size() - m_addition.size();
	if (newSize < 0){
		newSize = 0;
	}
	newName.resize(newSize);

	if((!info.baseString.contains(elideText) && !info.baseString.contains(newName)) || !elideText.contains(m_addition)){
		info.baseString = elideText;
	}

	QFont font = elideObject.property("font").value<QFont>();
	QFontMetrics metrics(font);
	QString formattedName = metrics.elidedText(
				info.baseString,
				Qt::ElideLeft,
				elideObject.property("size").toSize().width());
	newName = info.baseString;

	if(info.baseString != formattedName && m_addition.size() < formattedName.size()){
		// formattedName is only used to get max displayable text length
		newName.resize(formattedName.size() - m_addition.size());
		newName += m_addition;
	}
	info.elideString = newName;

	elideObject.setProperty("text", info.elideString);
}


void CTextElider::OnTimeout()
{
	QMapIterator<QObject*, ElideObjectInfo> elideObjectIterator(m_objectPtrMap);
	while (elideObjectIterator.hasNext()){
		elideObjectIterator.next();
		if (elideObjectIterator.key() != NULL){
			QObject* currentObjectPtr = elideObjectIterator.key();
			ElideObjectInfo& info = const_cast<ElideObjectInfo&>(elideObjectIterator.value());

			QString currentText = currentObjectPtr->property("text").toString();
			if (!currentText.isEmpty()){
				if (!info.baseString.isEmpty() && (info.baseString == currentText || info.elideString == currentText)){
					// no new Name or empty/initialization-state
				}
				else{
					QString containedString = currentText;
					int newSize = containedString.size() - m_addition.size();
					containedString.resize(newSize);
					if (info.baseString < currentText || 
						!info.baseString.contains(containedString)){
						info.baseString = currentText;
					}
					UpdateElidedText(*currentObjectPtr);
				}
			}
		}
	}
}


} // namespace iqtgui
