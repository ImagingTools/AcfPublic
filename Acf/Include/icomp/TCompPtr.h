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
#include <icomp/IComponent.h>
#include <icomp/CInterfaceManipBase.h>


template <class InterfaceType>
class TSharedCompPtr: protected CInterfaceManipBase
{
public:
	TSharedCompPtr(const TCompPtr& source)
		:m_ptr(source.ptr)
	{
	}

	TSharedCompPtr(icomp::IComponent* ptr)
	{
		m_ptr.SetPtr(ptr, ExtractIntefrace<InterfaceType>(ptr));
	}
	
	bool IsValid() const
	{
		return m_ptr.IsValid();
	}

	const InterfaceType* operator->() const
	{
		Q_ASSERT(m_ptr.IsValid());

		return m_ptr.operator->();
	}

	InterfaceType* operator->()
	{
		Q_ASSERT(m_ptr.IsValid());

		return m_ptr.operator->();
	}

	const InterfaceType& operator*() const
	{
		Q_ASSERT(m_ptr.IsValid());

		return *m_ptr;
	}

	InterfaceType& operator*()
	{
		Q_ASSERT(m_ptr.IsValid());

		return *m_ptr;
	}

private:
	typedef istd::TSharedInterfacePtr<InterfaceType, icomp::IComponent> PtrImpl;
	PtrImpl m_ptr;
};


} // namespace icomp


