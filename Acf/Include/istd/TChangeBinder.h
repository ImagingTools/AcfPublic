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


#ifndef istd_TChangeBinder_included
#define istd_TChangeBinder_included


// ACF includes
#include "istd/IPolymorphic.h"


namespace istd
{


/**
	Binder of two istd::IChangeable implementations
	\sa CChangeDelegator
*/
template <class Base, class Base2>
class TChangeBinder: public Base, public Base2
{
public:
	typedef Base BaseClass;
	typedef Base2 BaseClass2;

	// pseudo-reimplemented (istd::IChangeable)
	virtual void BeginChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr = NULL);
	virtual void EndChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr = NULL);
};


// pseudo-reimplemented (istd::IChangeable)

template <class Base, class Base2>
void TChangeBinder<Base, Base2>::BeginChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr)
{
	Base::BeginChanges(changeFlags, changeParamsPtr);
	Base2::BeginChanges(changeFlags, changeParamsPtr);
}


template <class Base, class Base2>
void TChangeBinder<Base, Base2>::EndChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr)
{
	Base::EndChanges(changeFlags, changeParamsPtr);
	Base2::EndChanges(changeFlags, changeParamsPtr);
}


} // namespace istd


#endif // !istd_TChangeBinder_included


