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


#ifndef iprop_CPropertiesEditorComp_included
#define iprop_CPropertiesEditorComp_included


// Qt includes
#include <QtGui/QTreeWidget>


// ACF includes
#include "iprop/IPropertiesManager.h"

#include "iqtgui/TDesignerGuiObserverCompBase.h"
#include "iqtgui/CItemDelegate.h"

#include "iprop/Generated/ui_CPropertiesEditorComp.h"


namespace iprop
{


/**
	Tree view based property editor component.
*/
class CPropertiesEditorComp:
			public iqtgui::TDesignerGuiObserverCompBase<
						Ui::CPropertiesEditorComp, IPropertiesManager>
{
	Q_OBJECT
public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CPropertiesEditorComp, IPropertiesManager> BaseClass;

	enum ColumnType
	{
		CT_PROPERTY = 0,
		CT_VALUE = 1
	};

	enum DataRole
	{
		DR_PROPERTY_ID = Qt::UserRole + 1
	};
	
	I_BEGIN_COMPONENT(CPropertiesEditorComp);
	I_END_COMPONENT;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags = 0);

	// reimplemented (CGuiComponentBase)
	virtual void OnGuiCreated();

private:
	class EditorDelegate: public iqtgui::CItemDelegate
	{
	public:
		typedef iqtgui::CItemDelegate BaseClass;

		EditorDelegate(CPropertiesEditorComp& parent);

		// reimplemented (QItemDelegate)
		virtual QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& /*option*/, const QModelIndex& index) const;
		virtual void setEditorData(QWidget* editor, const QModelIndex& index) const;
		virtual void setModelData(QWidget* editor,QAbstractItemModel* model, const QModelIndex& index) const;

	private:
		CPropertiesEditorComp& m_parent;
	};

private:

	void UpdatePropertyEditor(
				const IProperty& objectProperty,
				const QString& propertyId,
				const QString& propertyDescription);

	QString GetPropertyId(const QTreeWidgetItem& propertyItem) const;

	QTreeWidgetItem* FindPropertyItem(const QString& propertyId) const;

	void SetDataToEditor(const IProperty& objectProperty, QTreeWidgetItem& propertyItem);
};


} // namespace iqtgui


#endif // !iprop_CPropertiesEditorComp_included


