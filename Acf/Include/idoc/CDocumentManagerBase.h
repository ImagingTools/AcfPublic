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


#ifndef idoc_CDocumentManagerBase_included
#define idoc_CDocumentManagerBase_included


#include "idoc/IDocumentManager.h"


namespace idoc
{


class IDocumentTemplate;


class CDocumentManagerBase: virtual public idoc::IDocumentManager
{
public:
	CDocumentManagerBase();

	// reimplemented (idoc::IDocumentManager)
	virtual int GetAllowedOperationFlags(const istd::IPolymorphic* viewPtr = NULL) const;

	// reimplemented (idoc::IDocumentTypesInfo)
	virtual bool IsFeatureSupported(int featureFlags, const std::string& documentTypeId) const;
	virtual Ids GetDocumentTypeIds() const;
	virtual istd::CString GetDocumentTypeName(const std::string& documentTypeId) const;
	virtual iser::IFileTypeInfo* GetDocumentFileTypeInfo(const std::string& documentTypeId) const;
	virtual Ids GetDocumentTypeIdsForFile(const istd::CString& filePath) const;
	virtual istd::CString GetDefaultDirectory(const istd::CString& sugestedDir = "", const std::string* documentTypeIdPtr = NULL) const;

protected:
	virtual const idoc::IDocumentTemplate* GetDocumentTemplate() const;
	void SetDocumentTemplate(const idoc::IDocumentTemplate* documentTemplatePtr);

private:
	const IDocumentTemplate* m_documentTemplatePtr;

	int m_baseAllowedFlags;
};


} // namespace idoc


#endif // idoc_CDocumentManagerBase_included


