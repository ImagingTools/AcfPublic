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


#ifndef istd_TTransPtr_included
#define istd_TTransPtr_included


// Qt includes
#include <QtCore/QSharedPointer>


namespace istd
{


/**
	Implementation of data transfer smart pointer.
	It should be used to pointer transfer only, not to store the pointers becouse it overtakes the pointer.
	Typically it is used as smart pointer return parameters.
	The adventage against 'normal' smart pointer (istd::TSmartPtr) is that the copy constructor is faster, because it overtakes the pointer.
	\sa istd::TSmartPtr
*/
template <class Type>
class TTransPtr
{
public:
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

	/**
		Set this pointer to NULL.
	*/
	void Reset();

	/**
		Swap two pointers.
	*/
	void Swap(TTransPtr& pointer);

	template <class CastedType>
	CastedType Cast() const
	{
		return dynamic_cast<CastedType>(GetPtr());
	}

	// operators
	/**
		Copy operator overtaking the pointer.
		\param	pointer	pointer to overtake - \em warning: After this operation this pointer is invalid!
	*/
	Type& operator*() const;
	Type* operator->() const;

	QSharedPointer<Type> m_impl;

protected:
	TTransPtr();
};


// public methods

template<class Type>
inline bool TTransPtr<Type>::IsValid() const
{
	return m_impl.data() != NULL;
}


template<class Type>
inline const Type * TTransPtr<Type>::GetPtr() const
{
	return m_impl.data();
}


template<class Type>
inline Type * TTransPtr<Type>::GetPtr()
{
	return m_impl.data();
}


template<class Type>
inline void TTransPtr<Type>::Reset()
{
	m_impl.reset();
}


template<class Type>
inline void TTransPtr<Type>::Swap(TTransPtr<Type> & pointer)
{
	m_impl.swap(pointer);
}


template<class Type>
inline Type & TTransPtr<Type>::operator*() const
{
	return *m_impl;
}


template<class Type>
inline Type * TTransPtr<Type>::operator->() const
{
	return m_impl.data();
}


template<class Type>
inline TTransPtr<Type>::TTransPtr()
{
}


} // namespace istd


#endif // !istd_TTransPtr_included


