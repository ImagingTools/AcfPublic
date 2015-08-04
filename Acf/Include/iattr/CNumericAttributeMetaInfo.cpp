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


#include "iattr/CNumericAttributeMetaInfo.h"


namespace iattr
{


CNumericAttributeMetaInfo::CNumericAttributeMetaInfo(const QByteArray& typeId)
:	BaseClass(typeId)
{
}


bool CNumericAttributeMetaInfo::SetMinAttributeValue(const iser::IObject* valuePtr, bool releaseFlag)
{
	m_minAttributePtr.SetPtr(valuePtr, releaseFlag);

	return true;
}


bool CNumericAttributeMetaInfo::SetMaxAttributeValue(const iser::IObject* valuePtr, bool releaseFlag)
{
	m_maxAttributePtr.SetPtr(valuePtr, releaseFlag);

	return true;
}


// reimplemented (iattr::IEnumAttributeMetaInfo)

bool CNumericAttributeMetaInfo::GetMinimalValue(iser::IObject& result) const
{
	if (m_minAttributePtr.IsValid()){
		return result.CopyFrom(*m_minAttributePtr);
	}

	return false;
}


bool CNumericAttributeMetaInfo::GetMaximalValue(iser::IObject& result) const
{
	if (m_maxAttributePtr.IsValid()){
		return result.CopyFrom(*m_maxAttributePtr);
	}

	return false;
}


} // namespace iattr


