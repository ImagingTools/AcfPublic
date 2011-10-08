/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iprop_CPropertiesManager_included
#define iprop_CPropertiesManager_included


#include "istd/TComposedFactory.h"
#include "istd/TSingleFactory.h"
#include "istd/TOptPointerVector.h"
#include "istd/TDelPtr.h"

#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"

#include "iprop/TProperty.h"
#include "iprop/TMultiProperty.h"
#include "iprop/IPropertiesManager.h"


namespace iprop
{


/**
	Basic implementation of an property container.
*/
class CPropertiesManager: virtual public iprop::IPropertiesManager
{
public:
	/*
		Internal property info item.
	*/
	struct PropertyInfo
	{
		std::string propertyId;
		std::string propertyDescription;
		int propertyFlags;

		istd::TOptDelPtr<iser::IObject> objectPtr; 
	};

	CPropertiesManager();

	/**
		Get property info object for a given property ID.
	*/
	PropertyInfo* GetPropertyInfo(const std::string& propertyId) const;

	/**
		Register a new property type.
	*/
	template <typename PropertyType>
	static bool RegisterPropertyType();

	// reimplemented (iprop::IPropertiesManager)
	virtual int GetPropertiesCount() const;
	virtual iser::IObject* GetProperty(int propertyIndex) const;
	virtual std::string GetPropertyId(int propertyIndex) const;
	virtual istd::CString GetPropertyDescription(int propertyIndex) const;
	virtual void InsertProperty(
				iser::IObject* objectPtr,
				const std::string& propertyId,
				const std::string& propertyDescription,
				int propertyFlags,
				bool releaseFlag);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	bool ReadProperties(
				iser::IArchive& archive,
				const iser::CArchiveTag& attributesTag,
				const iser::CArchiveTag& attributeTag);

	bool WriteProperties(
				iser::IArchive& archive,
				const iser::CArchiveTag& attributesTag,
				const iser::CArchiveTag& attributeTag) const;

private:
	typedef istd::TComposedFactory<iser::IObject> PropertyFactory;

	istd::TPointerVector<PropertyInfo> m_propertiesList;

	static PropertyFactory s_propertyFactory;
};


// public static methods

template <typename AttributeImpl>
bool CPropertiesManager::RegisterPropertyType()
{
	return s_propertyFactory.RegisterFactory(new istd::TSingleFactory<iser::IObject, AttributeImpl>(AttributeImpl::GetTypeName()), true);
}


} // namespace iprop


#endif // !iprop_CPropertiesManager_included


