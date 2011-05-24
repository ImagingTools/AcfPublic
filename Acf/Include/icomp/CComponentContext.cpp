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


#include "icomp/CComponentContext.h"


#include "icomp/IRegistryElement.h"
#include "icomp/IComponentStaticInfo.h"
#include "icomp/IAttributeStaticInfo.h"


namespace icomp
{


CComponentContext::CComponentContext(
			const IRegistryElement* elementPtr,
			const IComponentStaticInfo* staticInfoPtr,
			const IComponentContext* parentPtr,
			const std::string& contextId)
:	m_registryElement(*elementPtr),
	m_staticInfo(*staticInfoPtr),
	m_parentPtr(parentPtr),
	m_contextId(contextId)
{
	I_ASSERT(elementPtr != NULL);
	I_ASSERT(staticInfoPtr != NULL);
}


// reimplemented (icomp::IComponentContext)

const IRegistryElement& CComponentContext::GetRegistryElement() const
{
	return m_registryElement;
}


const IComponentStaticInfo& CComponentContext::GetStaticInfo() const
{
	return m_staticInfo;
}


const IComponentContext* CComponentContext::GetParentContext() const
{
	return m_parentPtr;
}


const iser::IObject* CComponentContext::GetAttribute(const std::string& attributeId, int* definitionLevelPtr) const
{
	const IRegistryElement::AttributeInfo* infoPtr = m_registryElement.GetAttributeInfo(attributeId);

	if (infoPtr  != NULL){
		const std::string& exportId = infoPtr->exportId;
		if (!exportId.empty() && (m_parentPtr != NULL)){
			const iser::IObject* parentAttributePtr = NULL;
			if (definitionLevelPtr != NULL){
				int parentLevel = -1;

				parentAttributePtr = m_parentPtr->GetAttribute(exportId, &parentLevel);
				I_ASSERT((parentAttributePtr == NULL) || (parentLevel >= 0));	// if attribute is retured parent level must be set

				*definitionLevelPtr = parentLevel + 1;
			}
			else{
				parentAttributePtr = m_parentPtr->GetAttribute(exportId);
			}

			if (parentAttributePtr != NULL){
				return parentAttributePtr;
			}
		}

		if (infoPtr->attributePtr.IsValid()){
			if (definitionLevelPtr != NULL){
				*definitionLevelPtr = 0;
			}

			return infoPtr->attributePtr.GetPtr();
		}
	}

	const IAttributeStaticInfo* attributeInfoPtr = m_staticInfo.GetAttributeInfo(attributeId);
	if (attributeInfoPtr != NULL){
		if ((attributeInfoPtr->GetAttributeFlags() & icomp::IAttributeStaticInfo::AF_OBLIGATORY) != 0){
			const iser::IObject* defaultAttributePtr = attributeInfoPtr->GetAttributeDefaultValue();
			if (defaultAttributePtr != NULL){
				if (definitionLevelPtr != NULL){
					*definitionLevelPtr = 0;
				}

				return defaultAttributePtr;
			}
		}
	}

	return NULL;
}


}//namespace icomp


