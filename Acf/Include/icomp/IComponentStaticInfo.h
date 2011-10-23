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


#ifndef icomp_IComponentStaticInfo_included
#define icomp_IComponentStaticInfo_included


// STL includes
#include <set>
#include <string>


// ACF includes
#include "istd/IPolymorphic.h"
#include "istd/CString.h"


namespace icomp
{


class IAttributeStaticInfo;
class IComponent;


/**
	This interface provide static information about component meta info.
	Components can implements interfaces and contain attributes and subcomponents.
	Attributes have values specified in IComponentContext object.

	\ingroup ComponentConcept
*/
class IComponentStaticInfo: virtual public istd::IPolymorphic
{
public:
	/**
		Specify type of the component realization
	*/
	enum ComponentType
	{
		/**
			Undefined.
		*/
		CT_NONE,

		/**
			Component is realized as a class and managed by the ACF registry package (arp).
		*/
		CT_REAL,

		/**
			Component is the composition of real or other composite components.
		*/
		CT_COMPOSITE
	};

	enum MetaGroupId
	{
		/**
			ID of meta group storing list of supported interfaces.
		*/
		MGI_INTERFACES = 0,
		/**
			ID of meta group storing list of attributes.
		*/
		MGI_ATTRIBUTES,
		/**
			ID of group for subcomponents.
		*/
		MGI_SUBCOMPONENTS,
		/**
			ID of group for embedded types.
		*/
		MGI_EMBEDDED_COMPONENTS
	};

	typedef std::set<std::string> Ids;

	/**
		Get information about component type.
	*/
	virtual int GetComponentType() const = 0;

	/**
		Get set of attributes.
	*/
	virtual const IAttributeStaticInfo* GetAttributeInfo(const std::string& attributeId) const = 0;

	/**
		Return number of interfaces for specific slot.
		\param	subcomponentId	ID of subcomponent.
								\sa	GetMetaIds() and MGI_SUBCOMPONENTS.
	*/
	virtual const IComponentStaticInfo* GetSubcomponentInfo(const std::string& subcomponentId) const = 0;

	/**
		Return number of interfaces for specific slot.
		\param	subcomponentId	ID of subcomponent.
								\sa	GetMetaIds() and MGI_EMBEDDED_COMPONENTS.
	*/
	virtual const IComponentStaticInfo* GetEmbeddedComponentInfo(const std::string& embeddedId) const = 0;

	/**
		Get list of meta IDs associated with some meta key.
		\sa MetaGroupId
	*/
	virtual Ids GetMetaIds(int metaGroupId) const = 0;

	/**
		Get human readable description of this component.
	*/
	virtual const istd::CString& GetDescription() const = 0;

	/**
		Get keywords for this component.
	*/
	virtual const istd::CString& GetKeywords() const = 0;
};


} // namespace icomp


#endif // !icomp_IComponentStaticInfo_included


