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


#ifndef icomp_TComponentCloneWrap_included
#define icomp_TComponentCloneWrap_included


#include "icomp/IComponent.h"
#include "icomp/CInterfaceManipBase.h"
#include "icomp/CComponentContext.h"


namespace icomp
{


template <class BaseClass>
class TComponentCloneWrap: virtual public BaseClass, protected icomp::CInterfaceManipBase
{
public:
	// pseudo-reimplemented (istd::IChangeable)
	virtual istd::IChangeable* CloneMe() const;
};


// pseudo-reimplemented (istd::IChangeable)
	
template <class BaseClass>
istd::IChangeable* TComponentCloneWrap<BaseClass>::CloneMe() const
{
	const icomp::CComponentContext* contextPtr = dynamic_cast<const icomp::CComponentContext*>(BaseClass::GetComponentContext());
	if (contextPtr != NULL){
		const icomp::IComponent* parentComponentPtr = BaseClass::GetParentComponent();
		if (parentComponentPtr != NULL){
			istd::TDelPtr<istd::IChangeable> clonedPtr;
			
			clonedPtr.SetCastedOrRemove(ExtractInterface<istd::IChangeable>(parentComponentPtr->CreateSubcomponent(contextPtr->GetContextId())));

			if (clonedPtr.IsValid()){
				if (clonedPtr->CopyFrom(*this)){
					return clonedPtr.PopPtr();
				}
			}
		}
	}

	return NULL;
}


} // namespace icomp


#endif //!icomp_TComponentCloneWrap_included


