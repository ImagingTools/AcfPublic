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


#pragma once


// ACF includes
#include <istd/IChangeable.h>


namespace ibase
{


/**
	Base implementation for creating simple observable collection.
	Contains helper methods for constructing ChangeSets.

	\sa CListObserver
 */
class CObservableListBase
{
public:
	enum ChangeFlags
	{
		CF_ELEMENT_ADDED = 0x382b230,
		CF_ELEMENT_REMOVED,
		CF_ELEMENT_UPDATED,
		CF_RESET
	};

	inline static const QByteArray CN_INDEX_ID = QByteArrayLiteral("INDEX");

protected:
	static istd::IChangeable::ChangeSet ElementAddChanges(qsizetype index);
	static istd::IChangeable::ChangeSet ElementRemoveChanges(qsizetype index);
	static istd::IChangeable::ChangeSet ElementUpdatedChanges(qsizetype index);
};


} // namespace ibase


