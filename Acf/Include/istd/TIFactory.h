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


#ifndef istd_TIFactory_included
#define istd_TIFactory_included


// ACF includes
#include <istd/IFactoryInfo.h>


namespace istd
{


/**
	Generic interface for a factory.
*/
template <class Interface>
class TIFactory: virtual public IFactoryInfo  
{
public:
	typedef Interface InterfaceType;

	/**
		Create an instance of the object, mapped to the keyId \c keyId.
		\param	keyId		
		\return			pointer to created object or NULL if it was not possible to create it or keyId does not exist.
	*/
	virtual Interface* CreateInstance(const QByteArray& keyId = "") const = 0;
};


typedef TIFactory<void> IVoidFactory;
typedef TIFactory<istd::IPolymorphic> IFactory;


} // namespace istd


#endif // !istd_TIFactory_included

