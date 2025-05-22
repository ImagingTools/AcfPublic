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


#pragma once


// ACF includes
#include <istd/TInterfacePtr.h>


namespace istd
{


template<class InterfaceType>
class TOptInterfacePtr
{
public:
	typedef typename InterfaceType Interface;
	typedef istd::TUniqueInterfacePtr<InterfaceType> UniqueInterfacePtr;
	typedef istd::TSharedInterfacePtr<InterfaceType> SharedInterfacePtr;

	TOptInterfacePtr()
	{
	}

	TOptInterfacePtr(Interface* ptr)
		:m_ptr(ptr)
	{
	}

	TOptInterfacePtr(SharedInterfacePtr ptr)
		:m_taskPtr(ptr)
	{
	}

	TOptInterfacePtr(UniqueInterfacePtr& ptr)
	{
		m_taskPtr.FromUnique(ptr);
	}

	void SetPtr(UniqueInterfacePtr& ptr)
	{
		m_taskPtr.FromUnique(ptr);
	}

	void SetPtr(SharedInterfacePtr ptr)
	{
		m_taskPtr = ptr;
	}

	void TakeOver(Interface* ptr)
	{
		m_ptr = SharedInterfacePtr(ptr);
	}

	void SetOptionalPtr(Interface* ptr)
	{
		m_ptr = ptr;
	}

	bool IsValid() const
	{
		return (m_ptr != nullptr) || m_taskPtr.IsValid();
	}

	void Reset() const
	{
		m_ptr = nullptr;
		m_taskPtr.Reset();
	}

	Interface* GetPtr() const
	{
		if (m_ptr != nullptr){
			return m_ptr;
		}
		else if (m_taskPtr.IsValid()){
			return m_taskPtr.GetPtr();
		}

		return nullptr;
	}

	const Interface* operator->() const
	{
		Q_ASSERT(GetPtr() != nullptr);

		return GetPtr();
	}

	Interface* operator->()
	{
		Q_ASSERT(GetPtr() != nullptr);

		return const_cast<Interface*>(GetPtr());
	}

	const Interface& operator*() const
	{
		Q_ASSERT(GetPtr() != nullptr);

		return *GetPtr();
	}

	Interface& operator*()
	{
		Q_ASSERT(GetPtr() != nullptr);

		return *GetPtr();
	}

private:
	SharedInterfacePtr m_taskPtr;
	Interface* m_ptr = nullptr;
};


} // namespace istd


