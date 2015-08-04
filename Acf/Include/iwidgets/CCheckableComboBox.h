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


#ifndef iwidgets_CCheckableComboBox_included
#define iwidgets_CCheckableComboBox_included


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QComboBox>
#include <QtWidgets/QItemDelegate>
#else
#include <QtGui/QComboBox>
#include <QtGui/QItemDelegate>
#endif


// ACF includes
#include "istd/TDelPtr.h"

#include "iwidgets/iwidgets.h"


namespace iwidgets
{


class CCheckableComboBox: public QComboBox
{
	Q_OBJECT

public:
	typedef QComboBox BaseClass;

	CCheckableComboBox(QWidget* parentPtr = NULL);

	void SetItemsChecked(const QStringList& items, bool isChecked = true);

protected:
	virtual void UpdateDisplayText();

	// reimplemented (QWidget)
	virtual void paintEvent(QPaintEvent* eventPtr);

	// reimplemented (QObject)
	virtual bool eventFilter(QObject* object, QEvent* eventPtr);

Q_SIGNALS:
	/**
		Emit the list of items, they have checked state.
	*/
	void EmitActivatedItems(const QStringList& items);

private:
	class CCheckBoxDelegate: public QItemDelegate
	{
	public:
		typedef QItemDelegate BaseClass;

		CCheckBoxDelegate(CCheckableComboBox& parent);
	protected:
		// reimplemented (QItemDelegate)
		virtual void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
		virtual QWidget *createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;
		virtual void setEditorData(QWidget* editor, const QModelIndex &index) const;
		virtual void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const;

	private:
		CCheckableComboBox& m_parent;
	};

	QString m_displayText;
};


} // namespace iwidgets


#endif // !iwidgets_CCheckableComboBox_included


