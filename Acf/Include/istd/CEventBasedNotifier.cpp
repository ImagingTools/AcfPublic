/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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


#include "istd/CEventBasedNotifier.h"


// Qt includes
#include <QtCore/QCoreApplication>


namespace istd
{


// public methods

CEventBasedNotifier::CEventBasedNotifier(istd::IChangeable* slavePtr,  int changeFlags, istd::IPolymorphic* changeParamsPtr)
{
	m_notificationTarget = new NotificationTarget(slavePtr, changeFlags, changeParamsPtr);
}


CEventBasedNotifier::~CEventBasedNotifier()
{
	m_notificationTarget->Reset();

	m_notificationTarget->deleteLater();
}


// public methods of the internal class NotificationTarget

NotificationTarget::NotificationTarget(istd::IChangeable* slavePtr, int changeFlags, istd::IPolymorphic* changeParamsPtr)
:	m_slavePtr(slavePtr),
	m_changeFlags(changeFlags),
	m_changeParamsPtr(changeParamsPtr),
	m_isBeginPending(true)
{
	moveToThread(QCoreApplication::instance()->thread());

	connect(this, SIGNAL(EmitBeginChanges(int, istd::IPolymorphic*)), this, SLOT(DoBeginChanges(int, istd::IPolymorphic*)));
	connect(this, SIGNAL(EmitEndChanges(int, istd::IPolymorphic*)), this, SLOT(DoEndChanges(int, istd::IPolymorphic*)));

	Q_EMIT EmitBeginChanges(changeFlags, changeParamsPtr);
}


void NotificationTarget::Reset()
{
	I_ASSERT(!m_isBeginPending);

	Q_EMIT EmitEndChanges(m_changeFlags, m_changeParamsPtr);

	m_slavePtr = NULL;
}


// protected slots

void NotificationTarget::DoBeginChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr)
{
	m_isBeginPending = false;

	if (m_slavePtr != NULL){
		m_slavePtr->BeginChanges(changeFlags, changeParamsPtr);
	}
}


void NotificationTarget::DoEndChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr)
{
	if (m_slavePtr != NULL && !m_isBeginPending){
		m_slavePtr->EndChanges(changeFlags, changeParamsPtr);
	}
}


} // namespace istd


