/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#ifndef istd_TUpdateManagerWrap_included
#define istd_TUpdateManagerWrap_included


// ACF includes
#include "istd/istd.h"


namespace istd
{


class IPolymorphic;


/**
	Help wrapper class allowing to reduce nested update notifying by counting of changes.
	If nested update is started, base class implementation of BeginChanges and EndChanges will be blocked.
*/
template <class Base>
class TUpdateManagerWrap: virtual public Base
{
public:
	typedef Base BaseClass;

	TUpdateManagerWrap();

	// pseudo-reimplemented (istd::IChangeable)
	virtual void BeginChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr = NULL);
	virtual void EndChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr = NULL);

private:
	int m_changeCounter;
	int m_cumulatedFlags;
};


// public methods

template <class BaseClass>
TUpdateManagerWrap<BaseClass>::TUpdateManagerWrap()
{
	m_changeCounter = 0;
}


// pseudo-reimplemented (istd::IChangeable)

template <class BaseClass>
void TUpdateManagerWrap<BaseClass>::BeginChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr)
{
	Q_ASSERT(m_changeCounter >= 0);

	if (m_changeCounter++ == 0){
		BaseClass::BeginChanges(changeFlags, changeParamsPtr);
		m_cumulatedFlags = changeFlags;
	}
	else{
		m_cumulatedFlags |= changeFlags;
	}
}


template <class BaseClass>
void TUpdateManagerWrap<BaseClass>::EndChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr)
{
	Q_ASSERT(m_changeCounter > 0);

	if (--m_changeCounter == 0){
		m_cumulatedFlags |= changeFlags;

		BaseClass::EndChanges(m_cumulatedFlags, changeParamsPtr);
	}
	else{
		m_cumulatedFlags &= ~BaseClass::CF_ABORTED;
	}
}


} // namespace istd


#endif // !istd_TUpdateManagerWrap_included


