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


#ifndef istd_TSmartPtr_included
#define istd_TSmartPtr_included


// STD includes
#include <memory>

// ACF includes
#include <istd/TTransPtr.h>


namespace istd
{


/**
	\deprecated Use QSharedPointer instead!
	\ingroup Main
*/
template <class Type>
class TSmartPtr: public TTransPtr<Type>
{
public:
	TSmartPtr();
	
	explicit TSmartPtr(Type* pointer);

	TSmartPtr(const TTransPtr<Type>& trans);

	void SetPtr(Type* pointer);
	bool operator==(const TSmartPtr& other) const;

	/**
		Set this pointer using casted pointer of other type.
		If casting is not possible, object will be removed.
	*/
	template <class SourceType>
	bool SetCastedOrRemove(SourceType* pointer)
	{
		Type* castedPtr = dynamic_cast<Type*>(pointer);

		SetPtr(castedPtr);

		if (castedPtr != NULL){
			return true;
		}
		else{
			if (pointer != NULL){
				delete pointer;
			}

			return false;
		}
	}

	using TTransPtr<Type>::m_impl;
};


template <class Type>
inline TSmartPtr<Type>::TSmartPtr() : TTransPtr<Type>()
{
}


template <class Type>
inline TSmartPtr<Type>::TSmartPtr(Type* pointer)
{
	m_impl.reset(pointer);
}


template<class Type>
inline TSmartPtr<Type>::TSmartPtr(const TTransPtr<Type> & trans)
{
	m_impl = trans.m_impl;
}


template <class Type>
inline void TSmartPtr<Type>::SetPtr(Type* pointer)
{
	m_impl.reset(pointer);
}


template <class Type>
inline bool TSmartPtr<Type>::operator==(const TSmartPtr<Type>& other) const
{
	return this->GetPtr() == other.GetPtr();
}


} // namespace istd


#endif // !istd_TSmartPtr_included


