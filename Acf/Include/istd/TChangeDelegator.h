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


#ifndef istd_TChangeDelegator_included
#define istd_TChangeDelegator_included


// ACF includes
#include "istd/CChangeDelegator.h"


namespace istd
{


/**
	Binder of some istd::IChangeable implementation and changing delegator.
	\sa CChangeDelegator

	\ingroup DataModel
*/
template <class Base>
class TChangeDelegator:
			public Base,
			public CChangeDelegator
{
public:
	typedef Base BaseClass;
	typedef CChangeDelegator BaseClass2;

	TChangeDelegator();
	explicit TChangeDelegator(istd::IChangeable* slavePtr);

	// reimplemented (istd::IChangeable)
	virtual void OnBeginChanges();
	virtual void OnEndChanges(const istd::IChangeable::ChangeSet& changeSet);
};


// public methods

template <class Base>
TChangeDelegator<Base>::TChangeDelegator()
{
}


template <class Base>
TChangeDelegator<Base>::TChangeDelegator(IChangeable* slavePtr)
{
	BaseClass2::SetSlavePtr(slavePtr);
}


// pseudo-reimplemented (istd::IChangeable)

template <class Base>
void TChangeDelegator<Base>::OnBeginChanges()
{
	BaseClass2::OnBeginChanges();

	BaseClass::OnBeginChanges();
}


template <class Base>
void TChangeDelegator<Base>::OnEndChanges(const istd::IChangeable::ChangeSet& changeSet)
{
	BaseClass::OnEndChanges(changeSet);

	BaseClass2::OnEndChanges(changeSet);
}


} // namespace istd


#endif // !istd_TChangeDelegator_included

