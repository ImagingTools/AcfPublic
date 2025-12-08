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
#include <icomp/CComponentContext.h>
#include <icomp/CCompositeComponent.h>
#include <icomp/CCompositeComponentContext.h>
#include <icomp/CSimComponentContextBase.h>


namespace icomp
{


template <class BaseClass>
class TComponentCloneWrap: virtual public BaseClass, protected CInterfaceManipBase
{
public:
	// pseudo-reimplemented (istd::IChangeable)
	virtual istd::IChangeableUniquePtr CloneMe(istd::IChangeable::CompatibilityMode mode = istd::IChangeable::CM_WITHOUT_REFS) const override;
};


// pseudo-reimplemented (istd::IChangeable)

template <class BaseClass>
istd::IChangeableUniquePtr TComponentCloneWrap<BaseClass>::CloneMe(istd::IChangeable::CompatibilityMode mode) const
{
	icomp::IComponentContextSharedPtr contextPtr = BaseClass::GetComponentContext();
	if (contextPtr != nullptr){
		QByteArray contextId = contextPtr->GetContextId();

		const icomp::ICompositeComponent* parentComponentPtr = dynamic_cast<const icomp::ICompositeComponent*>(BaseClass::GetParentComponent());
		if (parentComponentPtr != nullptr){
			if ((mode == istd::IChangeable::CM_WITH_REFS) || (mode == istd::IChangeable::CM_CONVERT)){
				// we have to check if our owner has a parent composite component.
				// In this case we have to factorize not our component, but the complete parent composite component:
				const CCompositeComponent* parentCompositeComponentPtr = dynamic_cast<const CCompositeComponent*>(parentComponentPtr->GetParentComponent());
					if (parentCompositeComponentPtr != nullptr){
						const CCompositeComponentContext* parentContextPtr = dynamic_cast<const CCompositeComponentContext*>(parentCompositeComponentPtr->GetComponentContext().get());

					const IRegistry& registry = parentContextPtr->GetRegistry();
					IRegistry::Ids elementIds = registry.GetElementIds();

					for (IRegistry::Ids::ConstIterator elemIter = elementIds.constBegin(); elemIter != elementIds.constEnd(); ++elemIter){
						const icomp::ICompositeComponent* subComponentPtr = dynamic_cast<const icomp::ICompositeComponent*>(parentCompositeComponentPtr->GetSubcomponent(*elemIter).get());
						if (subComponentPtr != nullptr){
							icomp::IComponentContextSharedPtr subComponentContextPtr = subComponentPtr->GetComponentContext();

							if ((subComponentPtr->GetSubcomponent(contextId) != nullptr) && (subComponentContextPtr.get() == parentComponentPtr->GetComponentContext().get())) {
								contextId = *elemIter;

								parentComponentPtr = parentCompositeComponentPtr;
								break;
							}
						}
					}
				}
			}

			icomp::IComponentUniquePtr clonedComponentPtr = parentComponentPtr->CreateSubcomponent(contextId);
			istd::IChangeableUniquePtr clonedPtr;

			if (parentComponentPtr != nullptr){
				istd::IChangeable* changeablePtr = ExtractInterface<istd::IChangeable>(clonedComponentPtr.get());

				clonedPtr.SetPtr(clonedComponentPtr.release(), changeablePtr);
			}

			if (clonedPtr.IsValid()){
				if (clonedPtr->CopyFrom(*this, mode)){
					return clonedPtr;
				}
			}
		}
	}

	return istd::IChangeableUniquePtr();
}


} // namespace icomp


