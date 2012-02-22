/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef icmpstr_CMultiAttributeDelegateWidget_included
#define icmpstr_CMultiAttributeDelegateWidget_included


// Qt includes
#include <QWidget>
#include <QIcon>
#include <QItemDelegate>


// ACF includes
#include "icmpstr/CElementSelectionInfoManagerBase.h"


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
				const std::string& attributeId,
				int attributeFlags);

	QString GetText() const;
	void SetText(const QString& text);

protected Q_SLOTS:
	void OnShowDialog();

private:
	const CElementSelectionInfoManagerBase& m_elementSelectionInfoManager;

	QLineEdit* m_textEditor;
	std::string m_attributeId;
	int m_attributeFlags;

	QItemDelegate& m_itemDelegate;
};


} // namespace icmpstr


#endif // !icmpstr_CMultiAttributeDelegateWidget_included

