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


#ifndef iattr_IAttributesManager_included
#define iattr_IAttributesManager_included


// ACF includes
#include <iattr/IAttributesProvider.h>


namespace iattr
{


/**
	Common interface for a container of properties.
*/
class IAttributesManager: virtual public IAttributesProvider
{
public:
	/**
		Reset properties.
		The method set all static properties to their default values 
		and removes all dynamically added properties from the manager.
	*/
	virtual void RemoveAllAttributes() = 0;

	/**
		Insert an property into the object.
		\param	attributeId		Unique ID of the property in the properties repository.
		\param	attributePtr	QCoreApplicationProperty data object.
		\param	releaseFlag		If true, this attribute will be deleted by manager.
		\return	\c true, if this attribute could be added or \c false elesewhere.
	*/
	virtual bool InsertAttribute(
				const QByteArray& attributeId,
				iser::IObject* attributePtr,
				bool releaseFlag) = 0;

	/**
		Remove an existing property from the object.
		\return	\c true, if this attribute could be removed or \c false elesewhere.
	*/
	virtual bool RemoveAttribute(const QByteArray& attributeId) = 0;
};


} // namespace iattr


#endif // !iattr_IAttributesManager_included


