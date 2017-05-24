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


#include <i2d/CObject2dFactory.h>


// ACF includes
#include <imod/TModelWrap.h>
#include <i2d/CLine2d.h>


namespace i2d
{


static QByteArray s_line2dTypeId = CLine2d::GetTypeName();


// reimplemented (istd::TIFactory<iser::IObject>)

iser::IObject* CObject2dFactory::CreateInstance(const QByteArray& keyId) const
{
	if (keyId == s_line2dTypeId){
		return new imod::TModelWrap<CLine2d>();
	}
	else{
		return NULL;
	}
}


// reimplemented (istd::IFactoryInfo)

CObject2dFactory::KeyList CObject2dFactory::GetFactoryKeys() const
{
	return s_factoryKeys;
}


// static methods

const CObject2dFactory& CObject2dFactory::GetInstance()
{
	return s_instance;
}


// private static methods

CObject2dFactory::KeyList CObject2dFactory::GetInitialFactoryKeys()
{
	KeyList retVal;

	retVal.insert(s_line2dTypeId);

	return retVal;
}


// static attributes

CObject2dFactory::KeyList CObject2dFactory::s_factoryKeys = CObject2dFactory::GetInitialFactoryKeys();

CObject2dFactory CObject2dFactory::s_instance;


} // namespace i2d


