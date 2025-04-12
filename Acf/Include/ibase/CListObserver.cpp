/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#include <ibase/CListObserver.h>


namespace ibase
{


// public methods

// reimplemented (imod::CSingleModelObserverBase)

void CListObserver::OnUpdate(const istd::IChangeable::ChangeSet& changeSet)
{
	if (changeSet.Contains(CObservableListBase::CF_ELEMENT_ADDED)) {
		OnAfterElementAdded(changeSet.GetChangeInfo(CObservableListBase::CN_INDEX_ID).toInt());
	}
	if (changeSet.Contains(CObservableListBase::CF_ELEMENT_REMOVED)) {
		OnBeforeElementRemoved(changeSet.GetChangeInfo(CObservableListBase::CN_INDEX_ID).toInt());
	}
	if (changeSet.Contains(CObservableListBase::CF_ELEMENT_UPDATED)) {
		OnAfterElementUpdated(changeSet.GetChangeInfo(CObservableListBase::CN_INDEX_ID).toInt());
	}
	if (changeSet.Contains(istd::IChangeable::CF_ALL_DATA) || changeSet.Contains(CObservableListBase::CF_RESET)) {
		OnListReset();
	}
}


} // namespace ibase


