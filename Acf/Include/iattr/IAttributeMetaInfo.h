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


#ifndef iattr_IAttributeMetaInfo_included
#define iattr_IAttributeMetaInfo_included


// ACF includes
#include <iser/IObject.h>


namespace iattr
{


/**
	Meta information describing single attribute.
*/
class IAttributeMetaInfo: virtual public istd::IChangeable
{
public:
	/**
		Flags signalizing set of attribute properties.
	*/
	enum AttributeFlags
	{
		/**
			Active if user declared this attribute as obligatory.
		*/
		AF_OBLIGATORY = 1 << 0,
		/**
			Active if this attribute can be unset (null).
			Please note, that sometimes obligatory attributes can be nullable - for example for simple types default value can be taken.
		*/
		AF_NULLABLE	= 1 << 1,
		/**
			Attribute is single type.
		*/
		AF_SINGLE = 1 << 2,
		/**
			Attribute is multiple type.
		*/
		AF_MULTIPLE = 1 << 3,
		/**
			Attribute is simple value type.
		*/
		AF_VALUE = 1 << 4,
		/**
			Attribute is simple value type.
		*/
		AF_READ_ONLY = 1 << 31
	};

	/**
		Get description of this attribute.
	 */
	virtual QString GetAttributeDescription() const = 0;

	/**
		Get default attribute value.
		\return	pointer to default attribute value, if set. Elsewhere it returns NULL.
	*/
	virtual const iser::IObject* GetAttributeDefaultValue() const = 0;

	/**
		Return attribute type ID.
		The attribute type ID identifies unique this attribute in factory.
		\sa	istd::TIFactory::CreateInstance.
	*/
	virtual QByteArray GetAttributeTypeId() const = 0;

	/**
		Get flags of this attribute.
	 */
	virtual int GetAttributeFlags() const = 0;
};


} // namespace iattr


#endif // !iattr_IAttributeMetaInfo_included


