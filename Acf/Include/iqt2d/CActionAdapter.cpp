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


#include <iqt2d/CActionAdapter.h>


namespace iqt2d
{


// public methods

CActionAdapter::CActionAdapter(QWidget& host)
	:m_hostPtr(&host)
{
}


QAction* CActionAdapter::AddAction(QAction& action)
{
	m_hostPtr->addAction(&action);

	Action* extActionPtr = dynamic_cast<Action*>(&action);
	if (extActionPtr){
		extActionPtr->OnActionAdded(*this);
	}

	return &action;
}

QAction* CActionAdapter::AddSeparator()
{
	QAction* separatorPtr = new QAction(m_hostPtr);
	separatorPtr->setSeparator(true);

	m_hostPtr->addAction(separatorPtr);
	return separatorPtr;
}


QWidget* CActionAdapter::GetWidget() const
{
	return m_hostPtr;
}


// public methods of the embedded class Action

CActionAdapter::Action::Action(const QString& text, QObject* parent): QAction(text, parent)
{
}


CActionAdapter::Action::Action(const QIcon& icon, const QString& text, QObject* parent): QAction(icon, text, parent)
{
}


void CActionAdapter::Action::OnActionAdded(CActionAdapter& /*adapter*/)
{
}


} // namespace iqt2d



