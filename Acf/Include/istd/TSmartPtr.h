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


#ifndef istd_TSmartPtr_included
#define istd_TSmartPtr_included


#include "istd/TTransPtr.h"


namespace istd
{


/**
	Implementation of a smart pointer.
	This implementation uses internal counter object. Internal counter object is used to
	count of instances of smart pointers and will be shared by all its copies.

	\ingroup Main
*/
template <class Type, class Accessor = DefaultAccessor<Type> >
class TSmartPtr: public TTransPtr<Type>
{
public:
	typedef TTransPtr<Type> BaseClass;
	typedef typename BaseClass::RefCountBase RefCountBase;

	TSmartPtr();
	TSmartPtr(Type* pointer);
	TSmartPtr(const TTransPtr<Type>& pointer);
	TSmartPtr(const TSmartPtr& pointer);
	~TSmartPtr();

	/**
		Set this pointer to NULL.
	*/
	void Reset();

	/**
		Set pointed object.
	*/
	void SetPtr(Type* pointer);

	/**
		Set this pointer using casted pointer of other type.
		If casting is not possible, object will be removed.
	*/
	template <class SourceType>
	bool SetCastedOrRemove(SourceType* ptr)
	{
		Type* castedPtr = dynamic_cast<Type*>(ptr);

		SetPtr(castedPtr);

		if (castedPtr != NULL){
			return true;
		}
		else{
			Accessor::Delete(ptr);

			return false;
		}
	}

	// operators
	TSmartPtr& operator=(const TSmartPtr& otherCounter);

protected:
	class RefCounter: public RefCountBase
	{
	public:
		typedef RefCountBase BaseClass;

		RefCounter(Type* ptr)
		:	BaseClass(ptr)
		{
			m_count = 1;
		}

		// reimplemented (RefCountBase)
		virtual void OnAttached()
		{
			I_ASSERT(IsValid());
			I_ASSERT(m_count > 0);

			++m_count;
		}

		virtual void OnDetached()
		{
			I_ASSERT(IsValid());
			I_ASSERT(m_count > 0);

			if (--m_count <= 0){
				Accessor::Delete(BaseClass::GetPtr());

				delete this;
			}
		}

	private:
		int m_count;
	};

	using TTransPtr<Type>::m_counterPtr;

	/**
		Detach counter object without changing of internal counter pointer.
	*/
	void Detach();
};


template <class Type, class Accessor>
TSmartPtr<Type, Accessor>::TSmartPtr()
{
	m_counterPtr = NULL;
}


template <class Type, class Accessor>
TSmartPtr<Type, Accessor>::TSmartPtr(Type* pointer)
{
	m_counterPtr = new RefCounter(pointer);
}


template <class Type, class Accessor>
TSmartPtr<Type, Accessor>::TSmartPtr(const TTransPtr<Type>& pointer)
:	BaseClass(pointer)
{
	if (m_counterPtr != NULL){
		m_counterPtr->OnAttached();
	}
}


template <class Type, class Accessor>
TSmartPtr<Type, Accessor>::TSmartPtr(const TSmartPtr& pointer)
:	BaseClass(pointer)
{
	if (m_counterPtr != NULL){
		m_counterPtr->OnAttached();
	}
}


template <class Type, class Accessor>
TSmartPtr<Type, Accessor>::~TSmartPtr()
{
	Detach();
}


template <class Type, class Accessor>
void TSmartPtr<Type, Accessor>::Reset()
{
	if (m_counterPtr != NULL){
		m_counterPtr->OnDetached();

		m_counterPtr = NULL;
	}
}


template <class Type, class Accessor>
inline void TSmartPtr<Type, Accessor>::SetPtr(Type* pointer)
{
	Detach();

	m_counterPtr = new RefCounter(pointer);
}


template <class Type, class Accessor>
TSmartPtr<Type, Accessor>& TSmartPtr<Type, Accessor>::operator=(const TSmartPtr& other)
{
	Detach();

	m_counterPtr = other.m_counterPtr;

	if (m_counterPtr != NULL){
		m_counterPtr->OnAttached();
	}

	return *this;
}


// protected methods

template <class Type, class Accessor>
void TSmartPtr<Type, Accessor>::Detach()
{
	if (m_counterPtr != NULL){
		m_counterPtr->OnDetached();
	}
}


} // namespace istd


#endif // !istd_TSmartPtr_included


