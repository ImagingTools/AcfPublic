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


#ifndef istd_CEventBasedNotifier_included
#define istd_CEventBasedNotifier_included


// Qt includes
#include <QtCore/QObject>

// ACF includes
#include "istd/TChangeNotifier.h"
#include "istd/TOptDelPtr.h"


namespace istd
{


class NotificationTarget;


/**
	Implementation of model changes notification between different threads.
*/
class CEventBasedNotifier
{
public:
	explicit CEventBasedNotifier(istd::IChangeable* slavePtr, int changeFlags = 0, istd::IPolymorphic* changeParamsPtr = NULL);
	virtual ~CEventBasedNotifier();

private:
	NotificationTarget* m_notificationTarget;
};


/**
	\internal

	Help class to realize the post-processing of istd::IChangeable::EndChanges()
*/
class NotificationTarget: protected QObject
{
	Q_OBJECT

	friend class CEventBasedNotifier;

protected:
	NotificationTarget(istd::IChangeable* slavePtr, int changeFlags = 0, istd::IPolymorphic* changeParamsPtr = NULL);

	void Reset();

protected Q_SLOTS:
	void DoBeginChanges();
	void DoEndChanges();

Q_SIGNALS:
	void EmitBeginChanges();
	void EmitEndChanges();

private:
	istd::IChangeable* m_slavePtr;
	int m_changeFlags;
	istd::TOptDelPtr<istd::IPolymorphic> m_changeParamsPtr;

	/**
		Flag to inidicate, that BeginChange notification was sent.
	*/
	bool m_isBeginPending;
};


} // namespace istd


#endif // !istd_CEventBasedNotifier_included


