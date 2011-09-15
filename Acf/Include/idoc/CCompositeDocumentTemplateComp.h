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


#ifndef idoc_CCompositeDocumentTemplateComp_included
#define idoc_CCompositeDocumentTemplateComp_included


#include "icomp/CComponentBase.h"

#include "idoc/IDocumentTemplate.h"


namespace idoc
{


/**
	Complex document template consists of more simple templates.
*/
class CCompositeDocumentTemplateComp: public icomp::CComponentBase, virtual public IDocumentTemplate
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CCompositeDocumentTemplateComp);
		I_REGISTER_INTERFACE(idoc::IDocumentTemplate);
		I_ASSIGN_MULTI_0(m_slaveTemplatesCompPtr, "SlaveTemplates", "Set of document templates", true);
	I_END_COMPONENT;

	// reimplemented (idoc::IDocumentTemplate)
	virtual bool IsFeatureSupported(int featureFlags, const std::string& documentTypeId) const;
	virtual Ids GetDocumentTypeIds() const;
	virtual Ids GetViewTypeIds(const std::string& documentTypeId) const;
	virtual Ids GetDocumentTypeIdsForFile(const istd::CString& filePath) const;
	virtual iser::IFileLoader* GetFileLoader(const std::string& documentTypeId) const;
	virtual istd::IChangeable* CreateDocument(const std::string& documentTypeId) const;
	virtual istd::IPolymorphic* CreateView(
				const std::string& documentTypeId,
				istd::IChangeable* documentPtr,
				const std::string& viewTypeId = std::string()) const;
	virtual imod::IUndoManager* CreateUndoManager(const std::string& documentTypeId, istd::IChangeable* documentPtr) const;
	virtual IDocumentStateComparator* CreateStateComparator(const std::string& documentTypeId) const;
	virtual istd::CString GetDefaultDirectory(const istd::CString& sugestedDir = "", const std::string* documentTypeIdPtr = NULL) const;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_MULTIREF(idoc::IDocumentTemplate, m_slaveTemplatesCompPtr);

	typedef std::map<std::string, const idoc::IDocumentTemplate*> IdToTemplateMap;
	IdToTemplateMap m_idToTemplateMap;
};


} // namespace idoc


#endif // !idoc_CCompositeDocumentTemplateComp_included


