/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqt/CSafeNotifier.h"


// Qt includes
#include <QApplication>


namespace iqt
{


	
NotificationTarget::NotificationTarget(istd::IChangeable* slavePtr, int changeFlags, istd::IPolymorphic* changeParamsPtr)
:	BaseClass(slavePtr),
	m_changeFlags(changeFlags),
	m_changeParamsPtr(changeParamsPtr)
{
	moveToThread(QApplication::instance()->thread());

	connect(this, SIGNAL(EmitEndChanges(int, istd::IPolymorphic*)), this, SLOT(DoEndChanges(int, istd::IPolymorphic*)));

	BaseClass::BeginChanges(changeFlags, changeParamsPtr);
}


void NotificationTarget::Reset()
{
	EndChanges(m_changeFlags, m_changeParamsPtr);
}


// reimplemented (istd::IChangeable)

void NotificationTarget::EndChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr)
{
	Q_EMIT EmitEndChanges(changeFlags, changeParamsPtr);
}


// protected slots

void NotificationTarget::DoEndChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr)
{
	BaseClass::EndChanges(changeFlags, changeParamsPtr);
}


CSafeNotifier::CSafeNotifier(istd::IChangeable* slavePtr,  int changeFlags, istd::IPolymorphic* changeParamsPtr)
{
	m_notificationTarget = new NotificationTarget(slavePtr, changeFlags, changeParamsPtr);
}


CSafeNotifier::~CSafeNotifier()
{
	m_notificationTarget->Reset();

	m_notificationTarget->deleteLater();
}


} // namespace iqt


