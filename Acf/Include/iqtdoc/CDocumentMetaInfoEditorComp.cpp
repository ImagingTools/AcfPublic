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


#include <iqtdoc/CDocumentMetaInfoEditorComp.h>


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QFormLayout>
#else
#include <QtGui/QFormLayout>
#endif


namespace iqtdoc
{


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CDocumentMetaInfoEditorComp::OnGuiModelAttached()
{
	BaseClass::OnGuiModelAttached();

	ResetItems();

	QWidget* containerWidgetPtr = GetWidget();
	Q_ASSERT(containerWidgetPtr != NULL);

	QFormLayout* formLayoutPtr = dynamic_cast<QFormLayout*>(containerWidgetPtr->layout());
	Q_ASSERT(formLayoutPtr != NULL);

	typedef idoc::IDocumentMetaInfo::MetaInfoTypes MetaInfoTypes;

	idoc::IDocumentMetaInfo* objectPtr = GetObservedObject();
	if (objectPtr != NULL){
		MetaInfoTypes types = objectPtr->GetMetaInfoTypes();

		for (		MetaInfoTypes::ConstIterator index = types.constBegin();
					index != types.constEnd();
					++index){
			int metaInfoType = *index;

			MetaInfoItem metaInfoItem;

			QString metaInfoLabel = objectPtr->GetMetaInfoName(metaInfoType);
			QString metaInfo = objectPtr->GetMetaInfo(metaInfoType).toString();

			if (!metaInfoLabel.isEmpty()){
				bool isWritable = objectPtr->IsMetaInfoWritable(metaInfoType);

				metaInfoItem.labelPtr = new QLabel(metaInfoLabel, containerWidgetPtr);
				metaInfoItem.editPtr = new QLineEdit(metaInfo, containerWidgetPtr);
				connect(metaInfoItem.editPtr, SIGNAL(editingFinished()), this, SLOT(OnItemEditingFinished()));
				metaInfoItem.editPtr->setEnabled(isWritable);
				metaInfoItem.editPtr->setProperty("MetaInfoType", metaInfoType);

				m_metaInfoItemsMap[metaInfoType] = metaInfoItem;

				formLayoutPtr->addRow(metaInfoItem.labelPtr, metaInfoItem.editPtr);
			}
		}
	}
}


void CDocumentMetaInfoEditorComp::OnGuiModelDetached()
{
	ResetItems();

	BaseClass::OnGuiModelDetached();
}


void CDocumentMetaInfoEditorComp::UpdateGui(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	Q_ASSERT(IsGuiCreated());
}


// reimplemented (iqtgui::CComponentBase)

void CDocumentMetaInfoEditorComp::OnGuiCreated()
{
	QWidget* containerWidgetPtr = GetWidget();
	Q_ASSERT(containerWidgetPtr != NULL);

	QFormLayout* formLayoutPtr = new QFormLayout(containerWidgetPtr);
	formLayoutPtr->setContentsMargins(0, 0, 0, 0);

	containerWidgetPtr->setLayout(formLayoutPtr);

	BaseClass::OnGuiCreated();
}


// protected slots

void CDocumentMetaInfoEditorComp::OnItemEditingFinished()
{
	QLineEdit* editorPtr = dynamic_cast<QLineEdit*>(sender());
	Q_ASSERT(editorPtr != NULL);

	idoc::IDocumentMetaInfo* objectPtr = GetObservedObject();
	if (objectPtr != NULL){
		int metaInfoType = editorPtr->property("MetaInfoType").toInt();

		objectPtr->SetMetaInfo(metaInfoType, editorPtr->text());
	}
}


// private methods

void CDocumentMetaInfoEditorComp::ResetItems()
{
	for (		MetaInfoItemsMap::Iterator index = m_metaInfoItemsMap.begin();
				index != m_metaInfoItemsMap.end();
				++index){
		MetaInfoItem& item = index.value();

		delete item.labelPtr;
		delete item.editPtr;
	}

	m_metaInfoItemsMap.clear();
}


} // namespace iqtdoc


