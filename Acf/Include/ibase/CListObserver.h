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
#include <ibase/CObservableListBase.h>
#include <imod/CSingleModelObserverBase.h>


namespace ibase
{


/**
	Base implementation for observing a list.
	Routes ChangeSet change infos to specific virtual method
*/
class CListObserver: public imod::CSingleModelObserverBase
{
public:
	// reimplemented (imod::CSingleModelObserverBase)
	virtual void OnUpdate(const istd::IChangeable::ChangeSet& changeSet) override;

protected:
	virtual void OnListReset() = 0;
	virtual void OnBeforeElementRemoved(qsizetype index) = 0;
	virtual void OnAfterElementAdded(qsizetype index) = 0;
	virtual void OnAfterElementUpdated(qsizetype index) = 0;
};


} // namespace ibase


