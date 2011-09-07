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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqt_CSafeNotifier_included
#define iqt_CSafeNotifier_included


#include "iqt/iqt.h"


#include "istd/CChangeDelegator.h"
#include "istd/TChangeNotifier.h"


namespace iqt
{


class NotificationTarget;


/**
	Implementation of model changes notification between different threads.
*/
class CSafeNotifier
{
public:
	explicit CSafeNotifier(istd::IChangeable* slavePtr, int changeFlags = 0, istd::IPolymorphic* changeParamsPtr = NULL);
	~CSafeNotifier();

private:
	NotificationTarget* m_notificationTarget;
};


/**
	\internal

	Help class to realize the post-processing of istd::IChangeable::EndChanges()
*/
class NotificationTarget: protected QObject, protected istd::CChangeDelegator
{
	Q_OBJECT

	friend class CSafeNotifier;

protected:
	typedef istd::CChangeDelegator BaseClass;

	NotificationTarget(istd::IChangeable* slavePtr, int changeFlags = 0, istd::IPolymorphic* changeParamsPtr = NULL);

	void Reset();

	// reimplemented (istd::IChangeable)
	virtual void EndChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr = NULL);
protected Q_SLOTS:
	void DoEndChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr);

Q_SIGNALS:
	void EmitEndChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr);

private:
	int m_changeFlags;
	istd::IPolymorphic* m_changeParamsPtr;
};


} // namespace iqt


#endif // !iqt_CSafeNotifier_included


