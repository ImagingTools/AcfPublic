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


#include "iattr/CStandardAttributesFactory.h"


// ACF includes
#include "iattr/TAttribute.h"
#include "iattr/TMultiAttribute.h"


namespace iattr
{


static QByteArray integerAttrTypeName = CIntegerAttribute::GetTypeName();
static QByteArray realAttrTypeName = CRealAttribute::GetTypeName();
static QByteArray booleanAttrTypeName = CBooleanAttribute::GetTypeName();
static QByteArray stringAttrTypeName = CStringAttribute::GetTypeName();
static QByteArray idAttrTypeName = CIdAttribute::GetTypeName();

static QByteArray boolListAttrTypeName = CBooleanListAttribute::GetTypeName();
static QByteArray realListAttrTypeName = CRealListAttribute::GetTypeName();
static QByteArray integerListAttrTypeName = CIntegerListAttribute::GetTypeName();
static QByteArray stringListAttrTypeName = CStringListAttribute::GetTypeName();
static QByteArray idListAttrTypeName = CIdListAttribute::GetTypeName();


// reimplemented (istd::TIFactory<iser::IObject>)

iser::IObject* CStandardAttributesFactory::CreateInstance(const QByteArray& keyId) const
{
	if (keyId == integerAttrTypeName){
		return new CIntegerAttribute();
	}
	else if (keyId == realAttrTypeName){
		return new CRealAttribute();
	}
	else if (keyId == booleanAttrTypeName){
		return new CBooleanAttribute();
	}
	else if (keyId == stringAttrTypeName){
		return new CStringAttribute();
	}
	else if (keyId == idAttrTypeName){
		return new CIdAttribute();
	}
	else if (keyId == integerListAttrTypeName){
		return new CIntegerListAttribute();
	}
	else if (keyId == realListAttrTypeName){
		return new CRealListAttribute();
	}
	else if (keyId == boolListAttrTypeName){
		return new CBooleanListAttribute();
	}
	else if (keyId == stringListAttrTypeName){
		return new CStringListAttribute();
	}
	else if (keyId == idListAttrTypeName){
		return new CIdListAttribute();
	}
	else{
		return NULL;
	}
}


// reimplemented (istd::IFactoryInfo)

CStandardAttributesFactory::KeyList CStandardAttributesFactory::GetFactoryKeys() const
{
	return s_factoryKeys;
}


// static methods

const CStandardAttributesFactory& CStandardAttributesFactory::GetInstance()
{
	return s_instance;
}


// private static methods

CStandardAttributesFactory::KeyList CStandardAttributesFactory::GetInitialFactoryKeys()
{
	KeyList retVal;

	retVal.insert(integerAttrTypeName);
	retVal.insert(realAttrTypeName);
	retVal.insert(booleanAttrTypeName);
	retVal.insert(stringAttrTypeName);
	retVal.insert(idAttrTypeName);
	retVal.insert(integerListAttrTypeName);
	retVal.insert(realListAttrTypeName);
	retVal.insert(boolListAttrTypeName);
	retVal.insert(stringListAttrTypeName);
	retVal.insert(idListAttrTypeName);

	return retVal;
}


// static attributes
CStandardAttributesFactory::KeyList CStandardAttributesFactory::s_factoryKeys = CStandardAttributesFactory::GetInitialFactoryKeys();
CStandardAttributesFactory CStandardAttributesFactory::s_instance;


} // namespace iattr


