/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "icmpstr/CMultiAttributeDelegateWidget.h"


// Qt includes
#include <QtGui/QFocusEvent>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#else
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#endif

// ACF-Solutions includes
#include "icmpstr/CMultiAttributeEditor.h"

	
namespace icmpstr
{


// public methods

CMultiAttributeDelegateWidget::CMultiAttributeDelegateWidget(
			QItemDelegate& itemDelegate,
			const CElementSelectionInfoManagerBase& elementSelectionInfoManager,
			QWidget* parentWidget,
			const QByteArray& attributeId,
			int attributeFlags)
	:BaseClass(parentWidget),
	m_itemDelegate(itemDelegate),
	m_attributeId(attributeId),
	m_attributeFlags(attributeFlags),
	m_elementSelectionInfoManager(elementSelectionInfoManager)
{
	QHBoxLayout* layout = new QHBoxLayout(this);
	layout->setMargin(0);
	layout->setSpacing(0);

	m_textEditor = new QLineEdit(this);
	setFocusProxy(m_textEditor);
	setFocusPolicy(Qt::StrongFocus);

	QPushButton* editButton = new QPushButton(this);
	editButton->setMaximumSize(QSize(19, 19));
	editButton->setText("...");
	connect(editButton, SIGNAL(clicked()), this, SLOT(OnShowDialog()));

	layout->addWidget(m_textEditor);
	layout->addWidget(editButton);

	setAutoFillBackground(true);
}


QString CMultiAttributeDelegateWidget::GetText() const
{
	return m_textEditor->text();
}


void CMultiAttributeDelegateWidget::SetText(const QString& text)
{
	m_textEditor->setText(text);

	m_textEditor->setCursorPosition(0);
}


// protected slots

void CMultiAttributeDelegateWidget::OnShowDialog()
{
	istd::TDelPtr<CMultiAttributeEditor> multiEditorDialogPtr(new CMultiAttributeEditor(m_elementSelectionInfoManager, m_attributeId, m_attributeFlags));
	multiEditorDialogPtr->setWindowTitle(m_attributeId);

	multiEditorDialogPtr->SetEditorText(m_textEditor->text());

	if (multiEditorDialogPtr->exec() == QDialog::Accepted){
		SetText(multiEditorDialogPtr->GetAttributeValues().join(";"));

		// clear own focus:
		clearFocus();

		// reset focus to the parent widget
		Q_ASSERT(parentWidget() != NULL);
		parentWidget()->setFocus();

		// Send focus out event, to enforce the closing of the attribute editor:
		QFocusEvent e(QEvent::FocusOut);
		
		QApplication::sendEvent(this, &e);
	}
}


} // namespace icmpstr


