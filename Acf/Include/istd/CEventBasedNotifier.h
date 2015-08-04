/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef istd_CEventBasedNotifier_included
#define istd_CEventBasedNotifier_included


// Qt includes
#include <QtCore/QObject>

// ACF includes
#include "istd/CChangeNotifier.h"
#include "istd/TOptDelPtr.h"


namespace istd
{


class CAssyncNotifier;


/**
	Implementation of model changes notification between different threads.

	\ingroup DataModel
*/
class CEventBasedNotifier
{
public:
	explicit CEventBasedNotifier(istd::IChangeable* slavePtr, const IChangeable::ChangeSet* changeSetPtr = &IChangeable::GetAnyChange());
	virtual ~CEventBasedNotifier();

private:
	CAssyncNotifier* m_assyncNotifierPtr;
};


/**
	\internal

	Help class to realize the post-processing of \c istd::IChangeable::EndChanges
*/
class CAssyncNotifier: protected QObject
{
	Q_OBJECT

	friend class CEventBasedNotifier;

public:
	~CAssyncNotifier();

protected:
	CAssyncNotifier(istd::IChangeable* slavePtr, const IChangeable::ChangeSet& changeSet);

protected Q_SLOTS:
	void DoBeginChanges();

Q_SIGNALS:
	void EmitBeginChanges();

private:
	/**
		Target object should be updated. Cannot be \c NULL.
	*/
	istd::IChangeable* m_slavePtr;

	/**
		Set of changes.
	*/
	IChangeable::ChangeSet m_changeIds;

	/**
		Inidicates that \c BeginChange was called on slave object.
	*/
	bool m_isBeginCalled;
};


} // namespace istd


#endif // !istd_CEventBasedNotifier_included


