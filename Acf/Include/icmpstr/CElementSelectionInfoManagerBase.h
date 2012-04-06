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


#ifndef icmpstr_CElementSelectionInfoManagerBase_included
#define icmpstr_CElementSelectionInfoManagerBase_included


// ACF includes
#include "istd/TDelPtr.h"
#include "istd/TOptDelPtr.h"
#include "istd/CClassInfo.h"

#include "imod/TSingleModelObserverBase.h"

#include "icomp/IComponentEnvironmentManager.h"
#include "icomp/IRegistryElement.h"

#include "icmpstr/IAttributeSelectionObserver.h"
#include "icmpstr/IElementSelectionInfo.h"
#include "icmpstr/IRegistryConsistInfo.h"


namespace icmpstr
{


class CElementSelectionInfoManagerBase: public imod::TSingleModelObserverBase<IElementSelectionInfo>
{
public:
	typedef imod::TSingleModelObserverBase<IElementSelectionInfo> BaseClass;

	CElementSelectionInfoManagerBase();

	icomp::IRegistry* GetRegistry() const;
	QStringList GetExportAliases(const std::string& attributeName) const;
	const icomp::IComponentStaticInfo* GetComponentMetaInfo(const icomp::CComponentAddress& address) const;
	const iser::IObject* GetAttributeObject(const std::string& attributeId, const icomp::IRegistry::ElementInfo& elementInfo) const;
	const icomp::IAttributeStaticInfo* GetAttributeStaticInfo(const std::string& attributeId, const icomp::IRegistry::ElementInfo& elementInfo) const;

	// abstract methods
	virtual const icomp::IComponentEnvironmentManager* GetMetaInfoManagerPtr() const = 0;
	virtual const icmpstr::IRegistryConsistInfo* GetConsistencyInfoPtr() const = 0;

protected:
	void UpdateAddressToMetaInfoMap();

	// reimplemented (imod::CSingleModelObserverBase)
	virtual void OnUpdate(int updateFlags, istd::IPolymorphic* updateParamsPtr);

protected:
	struct AttrInfo
	{
		istd::TPointerBase<const icomp::IRegistryElement::AttributeInfo> infoPtr;
		istd::TPointerBase<const icomp::IAttributeStaticInfo> staticInfoPtr;
	};

	typedef QMap<std::string, AttrInfo> ElementIdToAttrInfoMap;
	typedef QMap<std::string, ElementIdToAttrInfoMap> AttrInfosMap;

	typedef QMap<icomp::CComponentAddress, istd::TOptDelPtr<const icomp::IComponentStaticInfo> > AddressToInfoMap;

	AddressToInfoMap m_adressToMetaInfoMap;
};


} // namespace icmpstr


#endif // !icmpstr_CElementSelectionInfoManagerBase_included

