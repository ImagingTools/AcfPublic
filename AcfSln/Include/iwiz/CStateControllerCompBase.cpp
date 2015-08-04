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


#include "iwiz/CStateControllerCompBase.h"


// ACF includes
#include "istd/CChangeNotifier.h"


namespace iwiz
{


CStateControllerCompBase::CStateControllerCompBase()
	:m_isStateActive(false),
	m_isStateEnabled(true),
	m_isEnterAllowed(true),
	m_isLeaveAllowed(true)
{
}


// reimplemented (iproc::IStateController)

bool CStateControllerCompBase::IsStateEnabled() const
{
	return m_isStateEnabled;
}


bool CStateControllerCompBase::IsStateActive() const
{
	return m_isStateActive;
}


bool CStateControllerCompBase::IsEnterAllowed(bool /*isActionAllowed*/, const IStateController* /*prevStatePtr*/) const
{
	return m_isEnterAllowed;
}


bool CStateControllerCompBase::IsLeaveAllowed(bool /*isActionAllowed*/, const IStateController* /*nextStatePtr*/) const
{
	return m_isLeaveAllowed;
}


bool CStateControllerCompBase::TryEnterState(bool /*isActionAllowed*/, const IStateController* /*prevStatePtr*/)
{
	Q_ASSERT(m_isStateEnabled);

	if (IsEnterAllowed()){
		if (!m_isStateActive){
			istd::CChangeNotifier notifier(this);
			m_isStateActive = true;
		}

		return true;
	}

	return false;
}


bool CStateControllerCompBase::TryLeaveState(bool /*isActionAllowed*/, const IStateController* /*nextStatePtr*/)
{
	Q_ASSERT(m_isStateEnabled);

	if (IsLeaveAllowed()){
		if (m_isStateActive){
			istd::CChangeNotifier notifier(this);
			m_isStateActive = false;
		}

		return true;
	}

	return false;
}


bool CStateControllerCompBase::IsResetAllowed() const
{
	return true;
}


} // namespace iwiz

