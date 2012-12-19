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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef ibase_THierarchicalBase_included
#define ibase_THierarchicalBase_included


#include "ibase/ibase.h"

#include "istd/TIHierarchical.h"
#include "istd/TChangeDelegator.h"


namespace ibase
{


/**
	Template based implementation of a hierarchical object. 
	This class is a pseudo-implementation of istd::TIHierarchical template interface.
*/
template <class Base, class Interface = typename Base::InterfaceType>
class THierarchicalBase: public istd::TChangeDelegator<Base>
{
public:
	typedef istd::TChangeDelegator<Base> BaseClass;

	THierarchicalBase();

	virtual void SetParentPtr(Interface* parentPtr);

	// pseudo-reimplemented (istd::TIHierarchical<Interface>)
	virtual int GetHierarchicalFlags() const;
	virtual int GetChildsCount() const;
	virtual Interface* GetChild(int index) const;
	virtual Interface* GetParent() const;

protected:
	Interface* m_parentPtr;
};


// public methods

template <class Base, class Interface>
THierarchicalBase<Base, Interface>::THierarchicalBase()
{
	m_parentPtr = NULL;
}


template <class Base, class Interface>
void THierarchicalBase<Base, Interface>::SetParentPtr(Interface* parentPtr)
{
	m_parentPtr = parentPtr;

	istd::IChangeable* changeablePtr = dynamic_cast<istd::IChangeable*>(parentPtr);
	if (changeablePtr){
		BaseClass::SetSlavePtr(changeablePtr);
	}
}


// pseudo-reimplemented (istd::TIHierarchical<Interface>)

template <class Base, class Interface>
int THierarchicalBase<Base, Interface>::GetHierarchicalFlags() const
{
	return BaseClass::HF_CHILDS_SUPPORTED | BaseClass::HF_PARENT_SUPPORTED;
}


template <class Base, class Interface>
int THierarchicalBase<Base, Interface>::GetChildsCount() const
{
	return 0;
}


template <class Base, class Interface>
Interface* THierarchicalBase<Base, Interface>::GetChild(int /*index*/) const
{
	return NULL;
}


template <class Base, class Interface>
Interface* THierarchicalBase<Base, Interface>::GetParent() const
{
	return m_parentPtr;
}


} // namespace ibase


#endif // ibase_THierarchicalBase_included


