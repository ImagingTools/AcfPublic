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


#ifndef iattr_CStandardAttributesFactory_included
#define iattr_CStandardAttributesFactory_included


// ACF includes
#include <iser/IObject.h>


namespace iattr
{


/**
	Basic implementation of an property container.
*/
class CStandardAttributesFactory: virtual public iser::IObjectFactory
{
public:
	// reimplemented (istd::TIFactory<iser::IObject>)
	virtual iser::IObject* CreateInstance(const QByteArray& keyId = "") const;

	// reimplemented (istd::IFactoryInfo)
	virtual KeyList GetFactoryKeys() const;

	// static methods
	static const CStandardAttributesFactory& GetInstance();

private:
	static KeyList GetInitialFactoryKeys();

	// static attributes
	static KeyList s_factoryKeys;
	static CStandardAttributesFactory s_instance;
};


} // namespace iattr


#endif // !iattr_CStandardAttributesFactory_included


