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


#ifndef icomp_CRegistry_included
#define icomp_CRegistry_included


#include "istd/TChangeDelegator.h"

#include "imod/TModelWrap.h"

#include "icomp/IRegistry.h"
#include "icomp/CRegistryElement.h"


namespace icomp
{


/**
	Standard implementation of registry.
*/
class CRegistry: virtual public IRegistry
{
public:
	// reimplemented (icomp::IRegistry)
	virtual Ids GetElementIds() const;
	virtual const ElementInfo* GetElementInfo(const std::string& elementId) const;
	virtual ElementInfo* InsertElementInfo(
				const std::string& elementId,
				const icomp::CComponentAddress& address,
				bool ensureElementCreated = true);
	virtual bool RemoveElementInfo(const std::string& elementId);
	virtual bool RenameElement(const std::string& oldElementId, const std::string& newElementId);
	virtual Ids GetEmbeddedRegistryIds() const;
	virtual IRegistry* GetEmbeddedRegistry(const std::string& registryId) const;
	virtual IRegistry* InsertEmbeddedRegistry(const std::string& registryId);
	virtual bool RemoveEmbeddedRegistry(const std::string& registryId);
	virtual bool RenameEmbeddedRegistry(const std::string& oldRegistryId, const std::string& newRegistryId);
	virtual const ExportedInterfacesMap& GetExportedInterfacesMap() const;
	virtual const ExportedComponentsMap& GetExportedComponentsMap() const;
	virtual void SetElementInterfaceExported(
				const std::string& elementId,
				const std::string& interfaceName,
				bool state = true);
	virtual void SetElementExported(
				const std::string& exportId,
				const std::string& elementId);
	virtual const QString& GetDescription() const;
	virtual void SetDescription(const QString& description);
	virtual const QString& GetKeywords() const;
	virtual void SetKeywords(const QString& keywords);
	
	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);
	virtual I_DWORD GetMinimalVersion(int versionId) const;

protected:
	typedef imod::TModelWrap<istd::TChangeDelegator<CRegistryElement> > Element;

	/**
		Called to create instance of registry element.
	*/
	virtual icomp::IRegistryElement* CreateRegistryElement(
				const std::string& elementId,
				const icomp::CComponentAddress& address) const;
	virtual bool SerializeComponents(iser::IArchive& archive);
	virtual bool SerializeEmbeddedRegistries(iser::IArchive& archive);
	virtual bool SerializeExportedInterfaces(iser::IArchive& archive);
	virtual bool SerializeExportedComponents(iser::IArchive& archive);

private:
	typedef std::map<std::string, ElementInfo> ComponentsMap;
	typedef istd::TDelPtr<IRegistry> RegistryPtr;
	typedef std::map<std::string, RegistryPtr> EmbeddedRegistriesMap;

	ComponentsMap m_componentsMap;
	EmbeddedRegistriesMap m_embeddedRegistriesMap;
	ExportedInterfacesMap m_exportedInterfacesMap;
	ExportedComponentsMap m_exportedComponentsMap;

	QString m_description;
	QString m_keywords;
};


} // namespace icomp


#endif // !icomp_CRegistry_included


