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


#ifndef ibase_TSerializableContainer_included
#define ibase_TSerializableContainer_included


#include "iser/IArchive.h"
#include "iser/ISerializable.h"
#include "iser/CArchiveTag.h"

#include "ibase/TContainer.h"


namespace ibase
{


/**
	Common implementation for an abstract serializable container. 
	Derived class must only reimplement the SerializeItem(). 
*/
template <typename ItemClass, typename ContainerClass = std::vector<ItemClass> >
class TSerializableContainer: public TContainer<ItemClass, ContainerClass>, virtual public iser::ISerializable
{
public:
	typedef TContainer<ItemClass, ContainerClass> BaseClass;

	// reimplemented (iser::Serializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	// abstract methods

	/**
		Serialize a single item in the container.
	*/
	virtual bool SerializeItem(ItemClass& item, iser::IArchive& archive) = 0;
};


// protected members	

// reimplemented (iser::Serializable)

template <typename ItemClass, typename ContainerClass>
bool TSerializableContainer<ItemClass, ContainerClass>::Serialize(iser::IArchive& archive)
{
	if (!archive.IsStoring()){
		this->Reset();
	}

	int itemCount = int(BaseClass::m_items.size());

	static iser::CArchiveTag itemsTag("Items", "List of items");
	static iser::CArchiveTag itemTag("Item", "Item");

	bool retVal = archive.BeginMultiTag(itemsTag, itemTag, itemCount);
	if (!retVal){
		return false;
	}

	if (!archive.IsStoring()){
		BaseClass::m_items.resize(itemCount);
	}

	for (int index = 0; index < itemCount; index++){
		ItemClass& item = BaseClass::m_items.at(index);

		bool retVal = archive.BeginTag(itemTag);

		retVal = retVal && SerializeItem(item, archive);

		retVal = retVal && archive.EndTag(itemTag);
	}

	return retVal;
}


} // namespace ibase


#endif // !ibase_TSerializableContainer_included


