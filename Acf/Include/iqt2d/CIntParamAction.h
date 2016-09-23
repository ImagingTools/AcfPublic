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


#ifndef iqt2d_CIntParamAction_included
#define iqt2d_CIntParamAction_included


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QAction>
#include <QtWidgets/QWidgetAction>
#include <QtWidgets/QSpinBox>
#else
#include <QtGui/QAction>
#include <QtGui/QWidgetAction>
#include <QtGui/QSpinBox>
#endif

// ACF includes
#include <iqt2d/CActionAdapter.h>


namespace iqt2d
{


class CIntParamAction: public CActionAdapter::Action
{
public:
	typedef CActionAdapter::Action BaseClass;

	CIntParamAction(const QIcon& icon, const QString& text, int minValue, int maxValue, int value, QObject* parentPtr = NULL);
	CIntParamAction(const QString& text, int minValue, int maxValue, int value, QObject* parentPtr = NULL);

	int GetValue() const;
	void SetValue(int x);

	QSpinBox* GetEditor() const;
	QWidgetAction* GetWidgetAction() const;

protected:
	// reimplemented (CActionAdapter::Action)
	virtual void OnActionAdded(CActionAdapter& adapter);

protected:
	void Init(int minValue, int maxValue, int value);

	QWidgetAction* m_widgetActionPtr;
	QSpinBox* m_spinEditor;
};


inline int CIntParamAction::GetValue() const
{
	Q_ASSERT(m_spinEditor);

	if (m_spinEditor){
		return m_spinEditor->value();
	}

	return 0;
}


inline void CIntParamAction::SetValue(int x)
{
	Q_ASSERT(m_spinEditor);

	if (m_spinEditor){
		m_spinEditor->setValue(x);
	}
}


inline QSpinBox* CIntParamAction::GetEditor() const
{
	Q_ASSERT(m_spinEditor);

	return m_spinEditor;
}


inline QWidgetAction* CIntParamAction::GetWidgetAction() const
{
	Q_ASSERT(m_widgetActionPtr);

	return m_widgetActionPtr;
}


} // namespace iqt2d


#endif //!iqt2d_CIntParamAction_included


