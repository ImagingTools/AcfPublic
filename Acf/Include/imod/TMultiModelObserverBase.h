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


#ifndef imod_TMultiModelObserverBase_included
#define imod_TMultiModelObserverBase_included


#include "imod/imod.h"


#include "imod/CMultiModelObserverBase.h"


namespace imod
{


/**
	Basic implementation of an multiple model observer.

	\ingroup ModelObserver
*/
template<class ObjectClass>
class TMultiModelObserverBase: public CMultiModelObserverBase
{
public:
	typedef CMultiModelObserverBase BaseClass;

	ObjectClass* GetObjectPtr(int objectIndex) const;

	// reimplemented (imod::IObserver)
	virtual bool OnAttached(imod::IModel* modelPtr);
};


// public methods

template<class ObjectClass>
ObjectClass* TMultiModelObserverBase<ObjectClass>::GetObjectPtr(int objectIndex) const
{
	I_ASSERT(objectIndex >= 0)
	I_ASSERT(objectIndex < GetModelCount());

	return dynamic_cast<ObjectClass*>(GetModelPtr(objectIndex));
}
	

// reimplemented (imod::IObserver)

template<class ObjectClass>
bool TMultiModelObserverBase<ObjectClass>::OnAttached(imod::IModel* modelPtr)
{
	ObjectClass* objectPtr = dynamic_cast<ObjectClass*>(modelPtr);
	if (objectPtr == NULL){
		return false;
	}

	return BaseClass::OnAttached(modelPtr);
}


} // namespace imod


#endif // !imod_TMultiModelObserverBase_included

