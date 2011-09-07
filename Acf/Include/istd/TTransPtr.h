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


#ifndef istd_TRetSmartPtr_included
#define istd_TRetSmartPtr_included


#include "istd/TPointerBase.h"


namespace istd
{


/**
	Implementation of reduced a smart pointer used as return parameters.
	This is a part of smart pointer concept.
	\sa istd::TSmartPtr
*/
template <class Type>
class TTransPtr
{
public:
	TTransPtr(const TTransPtr& other);

	/**
		Check, whether the object is in valid state.
	*/
	bool IsValid() const;

	/**
		Get access to pointed object.
	*/
	const Type* GetPtr() const;

	/**
		Get access to pointed object.
	*/
	Type* GetPtr();

	template <class CastedType>
	CastedType Cast() const
	{
		return dynamic_cast<CastedType>(GetPtr());
	}

	// operators
	Type& operator*() const;
	Type* operator->() const;

protected:
	TTransPtr();

	class RefCountBase: public TPointerBase<Type>
	{
	public:
		typedef TPointerBase<Type> BaseClass;

		RefCountBase(Type* ptr)
		:	BaseClass(ptr)
		{
			I_ASSERT(ptr != NULL);
		}
		virtual ~RefCountBase(){}

		// abstract methods
		virtual void OnAttached() = 0;
		virtual void OnDetached() = 0;
	};

	RefCountBase* m_counterPtr;
};


// public methods

template <class Type>
TTransPtr<Type>::TTransPtr(const TTransPtr& other)
:	m_counterPtr(other.m_counterPtr)
{
}


template <class Type>
bool TTransPtr<Type>::IsValid() const
{
	return (m_counterPtr != NULL) && (m_counterPtr->GetPtr() != NULL);
}


template <class Type>
inline const Type* TTransPtr<Type>::GetPtr() const
{
	if (m_counterPtr != NULL){
		return m_counterPtr->GetPtr();
	}
	else{
		return NULL;
	}
}


template <class Type>
inline Type* TTransPtr<Type>::GetPtr()
{
	if (m_counterPtr != NULL){
		return m_counterPtr->GetPtr();
	}
	else{
		return NULL;
	}
}


template <class Type>
inline Type& TTransPtr<Type>::operator*() const
{
	I_ASSERT(m_counterPtr != NULL);
	I_ASSERT(m_counterPtr->GetPtr() != NULL);

	return *m_counterPtr->GetPtr();
}


template <class Type>
inline Type* TTransPtr<Type>::operator->() const
{
	I_ASSERT(m_counterPtr != NULL);
	I_ASSERT(m_counterPtr->GetPtr() != NULL);

	return m_counterPtr->GetPtr();
}


// protected methods

template <class Type>
TTransPtr<Type>::TTransPtr()
{
}


} // namespace istd


#endif // !istd_TRetSmartPtr_included


