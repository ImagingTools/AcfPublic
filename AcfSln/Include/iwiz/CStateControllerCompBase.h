/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef iwiz_CStateControllerCompBase_included
#define iwiz_CStateControllerCompBase_included


// ACF includes
#include "icomp/CComponentBase.h"

#include "iproc/IStateController.h"


namespace iwiz
{


class CStateControllerCompBase:
			public icomp::CComponentBase,
			virtual public iproc::IStateController
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CStateControllerCompBase);
		I_REGISTER_INTERFACE(iproc::IStateController);
		I_REGISTER_INTERFACE(istd::IChangeable);
	I_END_COMPONENT;

	CStateControllerCompBase();

	// reimplemented (iproc::IStateController)
	virtual bool IsStateEnabled() const;
	virtual bool IsStateActive() const;
	virtual bool IsEnterAllowed(bool isActionAllowed = true, const IStateController* prevStatePtr = NULL) const;
	virtual bool IsLeaveAllowed(bool isActionAllowed = true, const IStateController* nextStatePtr = NULL) const;
	virtual bool TryEnterState(bool isActionAllowed = true, const IStateController* prevStatePtr = NULL);
	virtual bool TryLeaveState(bool isActionAllowed = true, const IStateController* nextStatePtr = NULL);
	virtual bool IsResetAllowed() const;

protected:
	mutable bool m_isStateActive;
	mutable bool m_isStateEnabled;
	mutable bool m_isEnterAllowed;
	mutable bool m_isLeaveAllowed;
};


} // namespace iwiz


#endif // !iwiz_CStateControllerCompBase_included


