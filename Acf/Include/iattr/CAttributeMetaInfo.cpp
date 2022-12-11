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


#include <iattr/CAttributeMetaInfo.h>


namespace iattr
{


CAttributeMetaInfo::CAttributeMetaInfo(const QByteArray& typeId)
:	m_attributeTypeId(typeId),
	m_attributeFlags(0)
{
}


void CAttributeMetaInfo::SetAttributeTypeId(const QByteArray& typeId)
{
	m_attributeTypeId = typeId;
}


void CAttributeMetaInfo::SetAttributeDescription(const QString& description)
{
	m_description = description;
}


void CAttributeMetaInfo::SetAttributeFlags(int attributeFlags)
{
	m_attributeFlags = attributeFlags;
}


void CAttributeMetaInfo::SetAttributeDefaultValue(const iser::IObject* defaultValuePtr, bool releaseFlag)
{
	m_defaultValuePtr.SetPtr(defaultValuePtr, releaseFlag);
}


// reimplemented (iattr::IAttributeMetaInfo)

QString CAttributeMetaInfo::GetAttributeDescription() const
{
	return m_description;
}


const iser::IObject* CAttributeMetaInfo::GetAttributeDefaultValue() const
{
	return m_defaultValuePtr.GetPtr();
}


QByteArray CAttributeMetaInfo::GetAttributeTypeId() const
{
	return m_attributeTypeId;
}


int CAttributeMetaInfo::GetAttributeFlags() const
{
	return m_attributeFlags;
}


} // namespace iattr


