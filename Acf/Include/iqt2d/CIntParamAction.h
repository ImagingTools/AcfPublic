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


#ifndef iqt2d_CIntParamAction_h
#define iqt2d_CIntParamAction_h


// Qt includes
#include <QtWidgets/QAction>
#include <QtWidgets/QWidgetAction>
#include <QtWidgets/QSpinBox>


namespace iqt2d
{


class CIntParamAction: public QAction
{
public:
	CIntParamAction(const QIcon& icon, const QString& text, int minValue, int maxValue, int value, QObject* parentPtr = NULL);
	CIntParamAction(const QString& text, int minValue, int maxValue, int value, QObject* parentPtr = NULL);

	int GetValue() const
	{
		Q_ASSERT(m_spinEditor);

		if (m_spinEditor){
			return m_spinEditor->value();
		}

		return 0;
	}

	QSpinBox* GetEditor() const
	{
		Q_ASSERT(m_spinEditor);

		return m_spinEditor;
	}

	QWidgetAction* GetWidgetAction() const
	{
		Q_ASSERT(m_widgetActionPtr);

		return m_widgetActionPtr;
	}

protected:
	void Init(int minValue, int maxValue, int value);

	QWidgetAction* m_widgetActionPtr;
	QSpinBox* m_spinEditor;
};


}


#endif //!iqt2d_CIntParamAction_h
