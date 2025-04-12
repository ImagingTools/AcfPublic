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


#include <ibase/CObservableListBase.h>


namespace ibase
{


// protected static methods

istd::IChangeable::ChangeSet CObservableListBase::ElementAddChanges(qsizetype index)
{
	istd::IChangeable::ChangeSet changeSet(CF_ELEMENT_ADDED);
	changeSet.SetChangeInfo(CN_INDEX_ID, index);

	return changeSet;
}


istd::IChangeable::ChangeSet CObservableListBase::ElementRemoveChanges(qsizetype index)
{
	istd::IChangeable::ChangeSet changeSet(CF_ELEMENT_REMOVED);
	changeSet.SetChangeInfo(CN_INDEX_ID, index);

	return changeSet;
}


istd::IChangeable::ChangeSet CObservableListBase::ElementUpdatedChanges(qsizetype index)
{
	istd::IChangeable::ChangeSet changeSet(CF_ELEMENT_UPDATED);
	changeSet.SetChangeInfo(CN_INDEX_ID, index);

	return changeSet;
}


} // namespace ibase


