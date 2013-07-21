/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#ifndef istd_TChangeNotifier_included
#define istd_TChangeNotifier_included


#include "istd/IChangeable.h"
#include "istd/TPointerBase.h"


namespace istd
{


/**
	Help class which provides the automatic update mechanism of the model.

	\ingroup ModelObserver
	\ingroup Main
	\ingroup Helpers
*/
template <class Changeable>
class TChangeNotifier: public istd::TPointerBase<Changeable>
{
public:
	typedef istd::TPointerBase<Changeable> BaseClass;

	explicit TChangeNotifier(Changeable* changeablePtr = NULL, int changeFlags = IChangeable::CF_MODEL, istd::IPolymorphic* updateParamsPtr = NULL);
	TChangeNotifier(const TChangeNotifier& notifier);
	virtual  ~TChangeNotifier();

	/**
		Allow Attach to some 'changeable' pointer.
	*/
	void SetPtr(Changeable* changeablePtr);
	/**
		Call update on attached object and detach it.
	*/
	void Reset();
	/**
		Similiar like method Reset(), but update will be called with active flag CF_ABORTED.
		It should be used only if you are sure, that no changes was done, or result will be ignored.
	*/
	void Abort();

	/**
		Method call operator returning slave 'changeable' pointer.
	*/
	const Changeable* operator->() const;
	/**
		Method call operator returning slave 'changeable' pointer.
	*/
	Changeable* operator->();
	/**
		Access to slave 'changeable' pointer.
	*/
	operator Changeable*() const;

private:
	int m_changeFlags;
	istd::IPolymorphic* m_updateParamsPtr;
};


template <class Changeable>
TChangeNotifier<Changeable>::TChangeNotifier(Changeable* changeablePtr, int changeFlags, istd::IPolymorphic* updateParamsPtr)
:	BaseClass(changeablePtr),
	m_changeFlags(changeFlags),
	m_updateParamsPtr(updateParamsPtr)
{
	if (changeablePtr != NULL){
		changeablePtr->BeginChanges(m_changeFlags, m_updateParamsPtr);
	}
}


template <class Changeable>
TChangeNotifier<Changeable>::TChangeNotifier(const TChangeNotifier& notifier)
:	BaseClass(notifier),
	m_changeFlags(notifier.m_changeFlags),
	m_updateParamsPtr(notifier.m_updateParamsPtr)
{
	if (BaseClass::IsValid()){
		BaseClass::operator->()->BeginChanges(notifier.m_changeFlags, notifier.m_updateParamsPtr);
	}
}


template <class Changeable>
TChangeNotifier<Changeable>::~TChangeNotifier()
{
	Reset();
}


template <class Changeable>
void TChangeNotifier<Changeable>::SetPtr(Changeable* changeablePtr)
{
	if (changeablePtr != BaseClass::GetPtr()){
		Reset();

		BaseClass::SetPtr(changeablePtr);

		if (changeablePtr != NULL){
			changeablePtr->BeginChanges(m_changeFlags, m_updateParamsPtr);
		}
	}
}


template <class Changeable>
inline void TChangeNotifier<Changeable>::Reset()
{
	Changeable* changeablePtr = BaseClass::GetPtr();

	if (changeablePtr != NULL){
		changeablePtr->EndChanges(m_changeFlags, m_updateParamsPtr);

		BaseClass::Reset();
	}
}


template <class Changeable>
inline void TChangeNotifier<Changeable>::Abort()
{
	Changeable* changeablePtr = BaseClass::GetPtr();

	if (changeablePtr != NULL){
		changeablePtr->EndChanges(m_changeFlags | IChangeable::CF_ABORTED, m_updateParamsPtr);

		BaseClass::Reset();
	}
}


template <class Changeable>
inline const Changeable* TChangeNotifier<Changeable>::operator->() const
{
	Q_ASSERT(BaseClass::IsValid());

	return BaseClass::GetPtr();
}


template <class Changeable>
inline Changeable* TChangeNotifier<Changeable>::operator->()
{
	Q_ASSERT(BaseClass::IsValid());

	return BaseClass::GetPtr();
}


template <class Changeable>
inline TChangeNotifier<Changeable>::operator Changeable*() const
{
	Q_ASSERT(BaseClass::IsValid());

	return BaseClass::GetPtr();
}


/**
	Basic change notifier for unspecified type.

	\ingroup ModelObserver
	\ingroup Main
	\ingroup Helpers
*/
typedef TChangeNotifier<IChangeable> CChangeNotifier;


} // namespace istd


#endif // !istd_TChangeNotifier_included

