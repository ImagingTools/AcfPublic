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


#include "icomp/CComponentStaticInfoBase.h"


namespace icomp
{


// reimplemented (icomp::IComponentStaticInfo)

int CComponentStaticInfoBase::GetComponentType() const
{
	return CT_NONE;
}


const IAttributeStaticInfo* CComponentStaticInfoBase::GetAttributeInfo(const std::string& /*attributeId*/) const
{
	return NULL;
}


const IComponentStaticInfo* CComponentStaticInfoBase::GetSubcomponentInfo(const std::string& /*subcomponentId*/) const
{
	return NULL;
}


const IComponentStaticInfo* CComponentStaticInfoBase::GetEmbeddedComponentInfo(const std::string& /*embeddedId*/) const
{
	return NULL;
}


IComponentStaticInfo::Ids CComponentStaticInfoBase::GetMetaIds(int /*metaGroupId*/) const
{
	Ids retVal;

	return retVal;
}


} // namespace icomp


