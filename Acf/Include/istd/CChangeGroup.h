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


#ifndef istd_CChangeGroup_included
#define istd_CChangeGroup_included


// ACF includes
#include <istd/IChangeable.h>


namespace istd
{


/**
	Help class which provides the group of changes for update mechanism of the model.
	\note It should not be overriden.

	\ingroup ModelObserver
	\ingroup Main
	\ingroup DataModel
*/
class CChangeGroup
{
public:
	/**
		Constructs the group.
		\param	changeablePtr	Your object prepared to change. If it is NULL, nothing will be done.
		\param	changeSetPtr	Pointer to set of change flags (its IDs).
								It cannot be \c NULL.
	*/
	explicit CChangeGroup(IChangeable* changeablePtr, const IChangeable::ChangeSet* changeSetPtr = &IChangeable::GetNoChanges());
	~CChangeGroup();

	/**
		Check if this pointer is valid.
		It will be invalid after \c Reset() and \c Abort() only.
	*/
	bool IsValid() const;

	/**
		Call update on attached object and detach it.
	*/
	void Reset();

private:
	// blocked copy constructor
	CChangeGroup(const CChangeGroup& group);

	IChangeable* m_changeablePtr = nullptr;

	const IChangeable::ChangeSet m_changeSet;
};


inline CChangeGroup::CChangeGroup(IChangeable* changeablePtr, const IChangeable::ChangeSet* changeSetPtr)
:	m_changeablePtr(changeablePtr),
	m_changeSet(*changeSetPtr)
{
	Q_ASSERT(changeSetPtr != NULL);

	if (m_changeablePtr != NULL){
		m_changeablePtr->BeginChangeGroup(m_changeSet);
	}
}


inline CChangeGroup::~CChangeGroup()
{
	if (m_changeablePtr != NULL){
		m_changeablePtr->EndChangeGroup(m_changeSet);
	}
}


} // namespace istd


#endif // !istd_CChangeGroup_included


