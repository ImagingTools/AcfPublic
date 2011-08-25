#ifndef iqtgui_CTextElider_included
#define iqtgui_CTextElider_included


// QT includes
#include <QObject>
#include <QString>
#include <QMap>
#include <QTimer>


namespace iqtgui
{


class CTextElider
		:	public QObject
{
public:
	CTextElider(QObject* parentPtr = NULL);
	virtual ~CTextElider(void);

	// reimplemented (QObject)
	virtual bool eventFilter(QObject* objectPtr, QEvent* eventPtr);

	virtual bool InsertElideObject(QObject* elideObject);
	virtual void RemoveElideObject(QObject* elideObject);
	virtual void RemoveAllElideObjects();

	void SetUpdateInterval(int mSec = 300);
	void SetAddition(QString addition);
	QString GetAddition() const;

private:
	struct ElideObjectInfo
	{
		QString baseString;
		QString elideString;
	};
	typedef QMap<QObject*, ElideObjectInfo> ElideObjectsMap;

	ElideObjectsMap m_objectPtrMap;

	QTimer m_textObservingTimer;
	int m_updateInterval;
	QString m_addition;

private:
	virtual void UpdateElidedText(QObject& elideObject);
	void OnTimeout();
};


} // namespace iqtgui


#endif // !iqtgui_CTextElider_included