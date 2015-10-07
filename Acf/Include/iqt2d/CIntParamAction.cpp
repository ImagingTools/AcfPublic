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


#include "iqt2d/CIntParamAction.h"


namespace iqt2d
{


CIntParamAction::CIntParamAction(const QIcon& icon, const QString& text, int minValue, int maxValue, int value, QObject* parentPtr)
:	QAction(icon, text, parentPtr)
{
	Init(minValue, maxValue, value);
}


CIntParamAction::CIntParamAction(const QString& text, int minValue, int maxValue, int value, QObject* parentPtr)
:	QAction(text, parentPtr)
{
	Init(minValue, maxValue, value);
}


void CIntParamAction::Init(int minValue, int maxValue, int value)
{
	m_spinEditor = new QSpinBox(NULL);
	m_spinEditor->setRange(minValue, maxValue);
	m_spinEditor->setValue(value);

	m_widgetActionPtr = new QWidgetAction(this);
	m_widgetActionPtr->setDefaultWidget(m_spinEditor);
}


} // namespace iqt2d


