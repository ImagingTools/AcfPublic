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


#ifndef icmpstr_CMultiAttributeEditor_included
#define icmpstr_CMultiAttributeEditor_included


// ACF includes
#include "iqtgui/CTreeWidgetFilter.h"
#include "iqtgui/CItemDelegate.h"

// ACF-Solutions includes
#include "icmpstr/CElementSelectionInfoManagerBase.h"
#include "icmpstr/Generated/ui_CMultiAttributeEditor.h"


namespace icmpstr
{


class CMultiAttributeEditor: public QDialog
{
	Q_OBJECT
public:
	CMultiAttributeEditor(
				const CElementSelectionInfoManagerBase& elementSelectionInfoManager,
				const QByteArray& attributeId,
				int attributeFlags);

	/**
		Set the list of the attributes as a text object
	*/
	void SetEditorText(const QString& attributeValuesText);		

	/**
		Get attribute values
	*/
	QStringList GetAttributeValues() const;

protected Q_SLOTS:
	void OnItemAdd();
	void OnItemRemove();
	void OnItemMoveUp();
	void OnItemMoveDown();
	void UpdateButtonStates();

protected:
	void CreateValuesTree(const QStringList& values);

private:
	class ValueItemDelegate: public iqtgui::CItemDelegate
	{
	public:
		typedef iqtgui::CItemDelegate BaseClass;

		ValueItemDelegate(const CMultiAttributeEditor& parent);
		
		// reimplemented (QItemDelegate)
		virtual QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;
		virtual void setEditorData(QWidget* editor, const QModelIndex& index ) const;
		virtual void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const;

	private:
		const CMultiAttributeEditor& m_parent;
	};


	const CElementSelectionInfoManagerBase& m_elementSelectionInfoManager;
	QByteArray m_attributeId;
	int m_attributeFlags;

	Ui::CMultiAttributeEditor m_dialog;

	ValueItemDelegate m_valueItemDelegate;
};


} // namespace icmpstr


#endif // !icmpstr_CMultiAttributeEditor_included

