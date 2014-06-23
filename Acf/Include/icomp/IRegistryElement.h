/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef icomp_IRegistryElement_included
#define icomp_IRegistryElement_included


// Qt includes
#include <QtCore/QByteArray>
#include <QtCore/QSet>

// ACF includes
#include "istd/istd.h"
#include "istd/TDelPtr.h"

#include "iser/ISerializable.h"
#include "iser/IObject.h"


namespace icomp
{


class IComponentStaticInfo;


/**
	Represents element of registry describing component parameters.
	Registry reflects state of registry files.

	\ingroup ComponentConcept
*/
class IRegistryElement: virtual public iser::ISerializable
{
public:
	typedef QSet< QByteArray> Ids;
	typedef istd::TDelPtr<iser::IObject> AttributePtr;

	enum ChangeFlags
	{
		/**
			Indicate that data model is changed.
		*/
		CF_ATTRIBUTE_CHANGED = 0x29734ba,
		CF_FLAGS_CHANGED
	};

	enum ElementFlags
	{
		/**
			Indicate that instance of this element should be automatically created.
		*/
		EF_AUTO_INSTANCE = 0x0001
	};

	/**
		Describe information stored with each attribute.
	*/
	struct AttributeInfo
	{
		AttributePtr attributePtr;
		QByteArray exportId;
		QByteArray attributeTypeName;
	};

	/**
		Get flags of this registry element.
		\sa	ElementFlags
	*/
	virtual quint32 GetElementFlags() const = 0;
	/**
		Set flags of this registry element.
		\sa	ElementFlags
	*/
	virtual void SetElementFlags(quint32 flags) = 0;

	/**
		Get ID list of existing attributes.
	*/
	virtual Ids GetAttributeIds() const = 0;

	/**
		Insert new attribute info object to collection of attributes.
		\param	attributeId		unique ID of new attribute.
		\param	createAttribute	if it is true, new attribute instance will be created.
	*/
	virtual AttributeInfo* InsertAttributeInfo(const QByteArray& attributeId, const QByteArray& attributeType) = 0;

	/**
		Create attribute object for specified ID.
	*/
	virtual iser::IObject* CreateAttribute(const QByteArray& attributeType) const = 0;

	/**
		Get access to stored attribute info structure.
	*/
	virtual const AttributeInfo* GetAttributeInfo(const QByteArray& attributeId) const = 0;

	/**
		Removes attribute info structure from this collection.
	*/
	virtual bool RemoveAttribute(const QByteArray& attributeId) = 0;
};


} // namespace icomp


#endif // !icomp_IRegistryElement_included


