/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
#include <istd/IPolymorphic.h>

// ACF-Solutions includes
#include <iauth/CLogoutEvent.h>


namespace iauth
{


template<class BaseClass>
class TLogoutEventHandlerWrap: public BaseClass, virtual public istd::IPolymorphic
{
public:
	virtual bool OnTryToLogout();

	// reimplemented (QObject)
	virtual bool event(QEvent* e) override;
};


template<class BaseClass>
bool TLogoutEventHandlerWrap<BaseClass>::OnTryToLogout()
{
	return true;
}


// reimplemented (QObject)

template<class BaseClass>
bool TLogoutEventHandlerWrap<BaseClass>::event(QEvent* e)
{
	CLogoutEvent* logoutEventPtr = dynamic_cast<CLogoutEvent*>(e);
	if (logoutEventPtr != nullptr) {
		if (!OnTryToLogout()){
			logoutEventPtr->ignore();
		}

		return true;
	}

	return BaseClass::event(e);
}


}	// namespace iauth


