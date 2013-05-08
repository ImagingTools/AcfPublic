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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqtgui/CImagePropertyGuiComp.h"


namespace iqtgui
{


// public methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CImagePropertyGuiComp::UpdateGui(int /*updateFlags*/)
{
	Q_ASSERT(IsGuiCreated());

	PropertyTree->clear();

	iimg::IBitmap* bitmapPtr = GetObjectPtr();
	if (bitmapPtr != NULL && IsGuiCreated()){
		QTreeWidgetItem* widthItemPtr = new QTreeWidgetItem();
		widthItemPtr->setText(0, tr("Width"));
		widthItemPtr->setText(1, QString("%1").arg(bitmapPtr->GetImageSize().GetX()));

		QTreeWidgetItem* heightItemPtr = new QTreeWidgetItem();
		heightItemPtr->setText(0, tr("Height"));
		heightItemPtr->setText(1, QString("%1").arg(bitmapPtr->GetImageSize().GetY()));

		QTreeWidgetItem* depthItemPtr = new QTreeWidgetItem();
		depthItemPtr->setText(0, tr("Depth"));
		depthItemPtr->setText(1, QString("%1 bits").arg(bitmapPtr->GetComponentBitsCount() * bitmapPtr->GetComponentsCount()));

		PropertyTree->addTopLevelItem(widthItemPtr);
		PropertyTree->addTopLevelItem(heightItemPtr);
		PropertyTree->addTopLevelItem(depthItemPtr);
	}
}


} // namespace iqtgui


