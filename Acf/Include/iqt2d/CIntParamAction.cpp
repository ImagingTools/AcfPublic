#include "iqt2d/CIntParamAction.h"

// Qt includes
#include <QtWidgets/QMenu>


namespace iqt2d
{


CIntParamAction::CIntParamAction(const QIcon& icon, const QString& text, int minValue, int maxValue, int value, QObject* parentPtr)
:	CExtendedAction(icon, text, parentPtr)
{
	Init(minValue, maxValue, value);
}


CIntParamAction::CIntParamAction(const QString& text, int minValue, int maxValue, int value, QObject* parentPtr)
:	CExtendedAction(text, parentPtr)
{
	Init(minValue, maxValue, value);
}


// protected 

void CIntParamAction::Init(int minValue, int maxValue, int value)
{
	m_spinEditor = new QSpinBox(NULL);
	m_spinEditor->setRange(minValue, maxValue);
	m_spinEditor->setValue(value);

	m_widgetActionPtr = new QWidgetAction(this);
	m_widgetActionPtr->setDefaultWidget(m_spinEditor);
}


// reimplemented (CExtendedAction)

void CIntParamAction::Process(IActionAdapter& adapter)
{
	// add widget actions to menus only
	if (dynamic_cast<QMenu*>(adapter.GetWidget())){
		adapter.AddAction(*m_widgetActionPtr);
	}
}


} // namespace iqt2d


