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


#include <istd/CEventBasedNotifier.h>


// Qt includes
#include <QtCore/QCoreApplication>
#include <QtCore/QThread>


namespace istd
{


// public methods

CEventBasedNotifier::CEventBasedNotifier(istd::IChangeable* slavePtr,  const IChangeable::ChangeSet* changeSetPtr)
{
	Q_ASSERT(changeSetPtr != NULL);

	if (slavePtr != NULL){
		m_assyncNotifierPtr = new CAssyncNotifier(slavePtr, *changeSetPtr);
	}
	else{
		m_assyncNotifierPtr = NULL;
	}
}


CEventBasedNotifier::~CEventBasedNotifier()
{
	if (m_assyncNotifierPtr != NULL){
		m_assyncNotifierPtr->deleteLater();
	}
}


// public methods of the internal class CAssyncNotifier

CAssyncNotifier::CAssyncNotifier(istd::IChangeable* slavePtr, const IChangeable::ChangeSet& changeSet)
:	m_slavePtr(slavePtr),
	m_changeIds(changeSet),
 	m_isBeginCalled(false)
{
	Q_ASSERT(slavePtr != NULL);

	if (QCoreApplication::instance() != NULL){
		moveToThread(QCoreApplication::instance()->thread());
	}

	connect(this, SIGNAL(EmitBeginChanges()), this, SLOT(DoBeginChanges()));

	Q_EMIT EmitBeginChanges();
}


CAssyncNotifier::~CAssyncNotifier()
{
	Q_ASSERT(m_isBeginCalled);

	if (m_isBeginCalled){
		m_slavePtr->EndChanges(m_changeIds);
	}
}


// protected slots

void CAssyncNotifier::DoBeginChanges()
{
	Q_ASSERT(!m_isBeginCalled);

	m_isBeginCalled = true;

	m_slavePtr->BeginChanges(m_changeIds);
}


} // namespace istd


