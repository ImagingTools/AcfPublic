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


#ifndef istd_TCachedUpdateManagerWrap_included
#define istd_TCachedUpdateManagerWrap_included


#include <istd/IChangeable.h>


namespace istd
{


/**
	Help wrapper class supporting of cached parts.
*/
template <class Base>
class TCachedUpdateManagerWrap: virtual public Base
{
public:
	typedef Base BaseClass;

	TCachedUpdateManagerWrap();

	// reimplemented (istd::IChangeable)
	virtual void BeginChanges(const IChangeable::ChangeSet& changeSet);
	virtual void EndChanges(const IChangeable::ChangeSet& changeSet);

protected:
	/**
		Ensures cache is valid.
		If cache is not valid method CalculateCache will be called to update it.
	*/
	bool EnsureCacheValid() const;
	/**
		Make cache invalid.
		This is automatically done when model/observer mechanism is used.
	*/
	void InvalidateCache(const IChangeable::ChangeSet& changeSet);
	/**
		Say that cache is valid.
	*/
	void SetCacheValid();
	/**
		Calculate cache.
		It will be called, if cache was not valid and EnsureCacheValid() is called.
		Default implementation does nothing and is provided to ensure
		that base class for all derived classes implement this method.
	*/
	virtual bool CalculateCache(const IChangeable::ChangeSet& changeSet);

private:
	int m_changesCounter;
	mutable bool m_isCacheValid;
	mutable IChangeable::ChangeSet m_cumulatedSet;
};


// public inline methods

// reimplemented (istd::IChangeable)

template <class Base>
void TCachedUpdateManagerWrap<Base>::BeginChanges(const IChangeable::ChangeSet& changeSet)
{
	Q_ASSERT(m_changesCounter >= 0);

	InvalidateCache(changeSet);

	BaseClass::BeginChanges(changeSet);

	++m_changesCounter;
}


template <class Base>
void TCachedUpdateManagerWrap<Base>::EndChanges(const IChangeable::ChangeSet& changeSet)
{
	--m_changesCounter;
	Q_ASSERT(m_changesCounter >= 0);

	BaseClass::EndChanges(changeSet);
}


// protected inline methods

template <class Base>
inline bool TCachedUpdateManagerWrap<Base>::EnsureCacheValid() const
{
	if (!m_isCacheValid && (m_changesCounter <= 0)){
		m_isCacheValid = true;	// set to avoid recursion

		m_isCacheValid = const_cast<TCachedUpdateManagerWrap<Base>*>(this)->CalculateCache(m_cumulatedSet);

		m_cumulatedSet.Reset();
	}

	return m_isCacheValid;
}


template <class Base>
void TCachedUpdateManagerWrap<Base>::InvalidateCache(const IChangeable::ChangeSet& changeSet)
{
	m_cumulatedSet += changeSet;

	m_isCacheValid = false;
}


template <class Base>
inline void TCachedUpdateManagerWrap<Base>::SetCacheValid()
{
	m_cumulatedSet.Reset();

	m_isCacheValid = true;
}


template <class Base>
inline bool TCachedUpdateManagerWrap<Base>::CalculateCache(const IChangeable::ChangeSet& /*changeSet*/)
{
	return true;
}


// public methods

template <class Base>
TCachedUpdateManagerWrap<Base>::TCachedUpdateManagerWrap()
:	m_changesCounter(0),
	m_isCacheValid(false)
{
}


} // namespace istd


#endif // !istd_TCachedUpdateManagerWrap_included


