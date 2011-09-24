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


#ifndef iattr_IAttributesManager_included
#define iattr_IAttributesManager_included


#include "iser/ISerializable.h"

#include "iattr/iattr.h"


namespace iattr
{


class IAttribute;


/**
	Interface for an attribute container
*/
class IAttributesManager: virtual public iser::ISerializable
{
public:
	/**
		Get number of attributes.
	*/
	virtual int GetAttributesCount() const = 0;

	/**
		Get attribute with the given index.
	*/
	virtual iser::IObject* GetAttribute(int attributeIndex) const = 0;

	/**
		Get the ID of the attribute with the given index \c attributeIndex.
		Attribute ID must be unique in the attribute set.
	*/
	virtual std::string GetAttributeId(int attributeIndex) const = 0;

	/**
		Get the description of the attribute with the given index \c attributeIndex
	*/
	virtual istd::CString GetAttributeDescription(int attributeIndex) const = 0;

	/**
		Insert an attribute into the object.
		\param objectPtr	Attribute data object.
		\param attributeId	Unique ID of the attribute in the attributes repository.
		\param attributeDescription	Human readable description of the attribute.
		\param attributeFlags	Attribute flags. \sa IAttribute::AttributeFlags.
		\param releaseFlag	Indicate who control the attribute's memory.
		If \c releaseFlag is \c true, the control over the \c objectPtr will be overtaken by this object.
	*/
	virtual void InsertAttribute(
				iser::IObject* objectPtr,
				const std::string& attributeId,
				const std::string& attributeDescription,
				int attributeFlags,
				bool releaseFlag) = 0;
};


} // namespace iattr


#endif // !iattr_IAttributesManager_included


