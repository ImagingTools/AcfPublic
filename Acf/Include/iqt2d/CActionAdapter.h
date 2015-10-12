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


#pragma once


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QAction>
#else
#include <QtGui/QAction>
#endif


namespace iqt2d
{


class CActionAdapter
{
public:
	CActionAdapter(QWidget& host);

	virtual QAction* AddAction(QAction& action);
	virtual QAction* AddSeparator();
	virtual QWidget* GetWidget() const;

	class Action: public QAction
	{
	public:
		Action(const QString& text, QObject* parent);
		Action(const QIcon& icon, const QString& text, QObject* parent);

		virtual void OnActionAdded(CActionAdapter& /*adapter*/);
	};

protected:
	QWidget* m_hostPtr;
};


} // namespace iqt2d


