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


#include "iqtgui/CVersionInfoGuiComp.h"


namespace iqtgui
{


// reimplemented (iqtgui::CGuiComponentBase)

void CVersionInfoGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

#if QT_VERSION < 0x050000
	Tree->header()->setResizeMode(QHeaderView::ResizeToContents);
#else
	Tree->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
#endif

	for (int i = 0; i < m_versionInfosCompPtr.GetCount(); i++){
		iser::IVersionInfo* infoPtr = m_versionInfosCompPtr[i];
		Q_ASSERT(infoPtr != NULL);

		iser::IVersionInfo::VersionIds ids = infoPtr->GetVersionIds();
		for (iser::IVersionInfo::VersionIds::const_iterator it = ids.begin(); it != ids.end(); it++){	
			QTreeWidgetItem* itemPtr = new QTreeWidgetItem(Tree);
			
			itemPtr->setText(0, infoPtr->GetVersionIdDescription(*it));
		
			quint32 number = 0;
			infoPtr->GetVersionNumber(*it, number);
			itemPtr->setText(1, infoPtr->GetEncodedVersionName(*it, number));		
		}
	}
}


} // namespace iqtgui


