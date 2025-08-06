/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#ifndef icmpstr_CMultiAttributeEditor_included
#define icmpstr_CMultiAttributeEditor_included


// ACF includes
#include <iwidgets/CItemDelegate.h>

// ACF-Solutions includes
#include <icmpstr/CElementSelectionInfoManagerBase.h>
#include <GeneratedFiles/icmpstr/ui_CMultiAttributeEditor.h>


namespace icmpstr
{


class CMultiAttributeEditor: public QDialog
{
	Q_OBJECT
public:
	CMultiAttributeEditor(
				QWidget* parentPtr,
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
	void OnItemChanged(QListWidgetItem* itemPtr);

protected:
	void CreateValuesTree(const QStringList& values);
	void UpdateItemState(QListWidgetItem& item);

private:
	class ValueItemDelegate: public iwidgets::CItemDelegate
	{
	public:
		typedef iwidgets::CItemDelegate BaseClass;

		ValueItemDelegate(const CMultiAttributeEditor& parent);
		
		// reimplemented (QItemDelegate)
		virtual QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
		virtual void setEditorData(QWidget* editor, const QModelIndex& index ) const override;
		virtual void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const override;

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

