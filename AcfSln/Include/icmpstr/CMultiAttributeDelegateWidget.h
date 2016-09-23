/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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


#ifndef icmpstr_CMultiAttributeDelegateWidget_included
#define icmpstr_CMultiAttributeDelegateWidget_included


// Qt includes
#include <QtGui/QIcon>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QWidget>
#include <QtWidgets/QItemDelegate>
#else
#include <QtGui/QWidget>
#include <QtGui/QItemDelegate>
#endif

// ACF-Solutions includes
#include <icmpstr/CElementSelectionInfoManagerBase.h>


namespace icmpstr
{


class CMultiAttributeDelegateWidget: public QWidget
{
	Q_OBJECT
public:
	typedef QWidget BaseClass;

public:
	CMultiAttributeDelegateWidget(
				QItemDelegate& itemDelegate,
				const CElementSelectionInfoManagerBase& elementSelectionInfoManager,
				QWidget* parentWidget,
				const QByteArray& attributeId,
				int attributeFlags);

	QString GetText() const;
	void SetText(const QString& text);

protected Q_SLOTS:
	void OnShowDialog();

private:
	QItemDelegate& m_itemDelegate;
	QLineEdit* m_textEditor;
	QByteArray m_attributeId;
	int m_attributeFlags;

	const CElementSelectionInfoManagerBase& m_elementSelectionInfoManager;
};


} // namespace icmpstr


#endif // !icmpstr_CMultiAttributeDelegateWidget_included

