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


#include "ifilegui/CFileListProviderGuiComp.h"


namespace ifilegui
{


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CFileListProviderGuiComp::UpdateGui(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	Q_ASSERT(IsGuiCreated());

	ifile::IFileListProvider* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		FileList->clear();

		const QFileInfoList& fileList = objectPtr->GetFileList();

		for (int fileIndex = 0; fileIndex < fileList.count(); fileIndex++){
			QTreeWidgetItem* fileItemPtr = new QTreeWidgetItem();

			fileItemPtr->setText(0, fileList[fileIndex].absoluteFilePath());

			FileList->addTopLevelItem(fileItemPtr);
		}
	}
}


} // namespace ifilegui


