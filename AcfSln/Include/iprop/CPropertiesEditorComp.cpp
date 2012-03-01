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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


// Qt includes
#include <QtCore/QUrl>
#include <QtGui/QHeaderView>
#include <QtGui/QToolButton>
#include <QtGui/QDesktopServices>
#include <QtGui/QTreeWidgetItemIterator>


// ACF includes
#include "istd/TChangeNotifier.h"

#include "iprop/TProperty.h"
#include "iprop/CPropertiesEditorComp.h"


namespace iprop
{


// reimplemented (iqtgui::TGuiObserverWrap)

void CPropertiesEditorComp::UpdateGui(int /*updateFlags*/)
{
	I_ASSERT(IsGuiCreated());

	IPropertiesManager* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){

		int propertiesCount = objectPtr->GetPropertiesCount();
		
		for(int propertyIndex = 0; propertyIndex < propertiesCount; propertyIndex++){
			const IProperty* propertyPtr = dynamic_cast<const IProperty*>(objectPtr->GetProperty(propertyIndex));
			if (propertyPtr != NULL){

				QString propertyId = QString::fromStdString(objectPtr->GetPropertyId(propertyIndex));
				QString propertyDescription = objectPtr->GetPropertyDescription(propertyIndex);

				UpdatePropertyEditor(*propertyPtr, propertyId, propertyDescription);
			}
		}
	}
}


// reimplemented (CGuiComponentBase)

void CPropertiesEditorComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	PropertyTree->setSelectionMode(QAbstractItemView::SingleSelection);
}


// private methods

void CPropertiesEditorComp::UpdatePropertyEditor(
			const IProperty& objectProperty,
			const QString& propertyId,
			const QString& propertyDescription)
{
	QTreeWidgetItem* propertyItemPtr = FindPropertyItem(propertyId);
	if (propertyItemPtr == NULL){
		propertyItemPtr = new QTreeWidgetItem;

		propertyItemPtr->setText(CT_PROPERTY, propertyId);
		propertyItemPtr->setData(CT_PROPERTY, DR_PROPERTY_ID, propertyId);
		propertyItemPtr->setStatusTip(CT_PROPERTY, propertyDescription);
	}

	I_ASSERT(propertyItemPtr != NULL);

	SetDataToEditor(objectProperty, *propertyItemPtr);
}


QString CPropertiesEditorComp::GetPropertyId(const QTreeWidgetItem& propertyItem) const
{
	return propertyItem.data(CT_PROPERTY, DR_PROPERTY_ID).toString(); 
}


QTreeWidgetItem* CPropertiesEditorComp::FindPropertyItem(const QString& propertyId) const
{
	QTreeWidgetItemIterator treeIter(PropertyTree);

	while (*treeIter){
		QTreeWidgetItem* propertyItemPtr = *treeIter;

		I_ASSERT(propertyItemPtr != NULL);

		QString currentPropertyId = GetPropertyId(*propertyItemPtr);
		if (propertyId == currentPropertyId){
			return propertyItemPtr;
		}

		treeIter++;
	}

	return NULL;
}


void CPropertiesEditorComp::SetDataToEditor(const IProperty& objectProperty, QTreeWidgetItem& propertyItem)
{
	const CBoolProperty* boolPropertyPtr = dynamic_cast<const CBoolProperty*>(&objectProperty);
	if (boolPropertyPtr != NULL){
		bool value = boolPropertyPtr->GetValue();
		propertyItem.setText(CT_VALUE, value ? tr("true") : tr("false"));
	}

	const CIntProperty* intPropertyPtr = dynamic_cast<const CIntProperty*>(&objectProperty);
	if (intPropertyPtr != NULL){
		propertyItem.setText(CT_VALUE, QString("%1").arg(intPropertyPtr->GetValue()));
	}

	const CDoubleProperty* doublePropertyPtr = dynamic_cast<const CDoubleProperty*>(&objectProperty);
	if (doublePropertyPtr != NULL){
		propertyItem.setText(CT_VALUE, QString("%1").arg(doublePropertyPtr->GetValue(), 3, 'f', 3));
	}

	const CStringProperty* stringPropertyPtr = dynamic_cast<const CStringProperty*>(&objectProperty);
	if (stringPropertyPtr != NULL){
		propertyItem.setText(CT_VALUE, stringPropertyPtr->GetValue());
	}

	const CStdStringProperty* idPropertyPtr = dynamic_cast<const CStdStringProperty*>(&objectProperty);
	if (idPropertyPtr != NULL){
		propertyItem.setText(CT_VALUE, idPropertyPtr->GetValue().c_str());
	}
}


} // namespace iprop


