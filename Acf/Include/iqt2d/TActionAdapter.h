#pragma once


// Qt includes
#include <QtWidgets/QAction>

// ACF includes
#include "istd/IPolymorphic.h"


namespace iqt2d
{


class IActionAdapter : public istd::IPolymorphic
{
public:
	virtual QAction* AddAction(QAction& action) = 0;;
	virtual QAction* AddSeparator() = 0;;

	virtual QWidget* GetWidget() const = 0;
};


class CExtendedAction : public QAction
{
public:
	CExtendedAction(const QString& text, QObject* parent): QAction(text, parent){}
	CExtendedAction(const QIcon& icon, const QString& text, QObject* parent): QAction(icon, text, parent){}

//protected:
	virtual void Process(IActionAdapter& /*adapter*/){}
};


template <class Widget>
class TActionAdapter : public IActionAdapter
{
public:
	TActionAdapter(Widget& host): m_hostPtr(&host)
	{
	}

	virtual QAction* AddAction(QAction& action)
	{
		m_hostPtr->addAction(&action);

		CExtendedAction* extActionPtr = dynamic_cast<CExtendedAction*>(&action);
		if (extActionPtr){
			extActionPtr->Process(*this);
		}

		return &action;
	}

	virtual QAction* AddSeparator()
	{
		QAction* separatorPtr = new QAction(m_hostPtr);
		separatorPtr->setSeparator(true);

		m_hostPtr->addAction(separatorPtr);
		return separatorPtr;
	}

	virtual QWidget* GetWidget() const
	{
		return m_hostPtr;
	}

protected:
	Widget* m_hostPtr;
};


}



