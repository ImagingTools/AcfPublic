/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#include "icomp/CComponentStaticInfoBase.h"


namespace icomp
{


// reimplemented (icomp::IComponentStaticInfo)

int CComponentStaticInfoBase::GetComponentType() const
{
	return CT_NONE;
}


const IAttributeStaticInfo* CComponentStaticInfoBase::GetAttributeInfo(const QByteArray& /*attributeId*/) const
{
	return NULL;
}


const IComponentStaticInfo* CComponentStaticInfoBase::GetEmbeddedComponentInfo(const QByteArray& /*embeddedId*/) const
{
	return NULL;
}


const QString& CComponentStaticInfoBase::GetDescription() const
{
	static QString emptyString;

	return emptyString;
}


const QString& CComponentStaticInfoBase::GetKeywords() const
{
	static QString emptyString;

	return emptyString;
}


//	reimplemented (icomp::IElementStaticInfo)

IElementStaticInfo::Ids CComponentStaticInfoBase::GetMetaIds(int /*metaGroupId*/) const
{
	Ids retVal;

	return retVal;
}


const IElementStaticInfo* CComponentStaticInfoBase::GetSubelementInfo(const QByteArray& /*subcomponentId*/) const
{
	return NULL;
}


//	reimplemented (iattr::IAttributesMetaInfoProvider)

iattr::IAttributesProvider::AttributeIds CComponentStaticInfoBase::GetAttributeMetaIds() const
{
	iattr::IAttributesProvider::AttributeIds retVal;

	return retVal;
}


const iattr::IAttributeMetaInfo* CComponentStaticInfoBase::GetAttributeMetaInfo(const QByteArray& /*attributeId*/) const
{
	return NULL;
}


} // namespace icomp


