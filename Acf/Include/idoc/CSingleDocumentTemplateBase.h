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


#ifndef idoc_CSingleDocumentTemplateBase_included
#define idoc_CSingleDocumentTemplateBase_included


// STL includes
#include <limits>

#include "imod/IModel.h"

#include "idoc/IDocumentTemplate.h"


namespace idoc
{		


class IDocumentManager;


/**
	Base class implementing document template for single document type.
*/
class CSingleDocumentTemplateBase: virtual public idoc::IDocumentTemplate
{
public:
	const std::string& GetDocumentTypeId() const;
	virtual void SetSupportedFeatures(int featureFlags);
	virtual void SetDocumentTypeId(const std::string& documentTypeId);
	virtual void SetDefaultDirectory(const istd::CString& defaultDirectory);

	// reimplemented (idoc::IDocumentTemplate)
	virtual bool IsFeatureSupported(int featureFlags, const std::string& documentTypeId) const;
	virtual Ids GetDocumentTypeIds() const;
	virtual Ids GetViewTypeIds(const std::string& documentTypeId) const;
	virtual Ids GetDocumentTypeIdsForFile(const istd::CString& filePath) const;
	virtual IDocumentStateComparator* CreateStateComparator(const std::string& documentTypeId) const;
	virtual istd::CString GetDefaultDirectory(const istd::CString& sugestedDir = "", const std::string* documentTypeIdPtr = NULL) const;

protected:
	bool IsDocumentTypeSupported(const std::string& documentTypeId) const;
	bool IsViewTypeSupported(const std::string& viewTypeId) const;

private:
	istd::CString m_defaultDirectory;

	std::string m_documentTypeId;
	std::string m_viewTypeId;

	int m_supportedFeatures;
};


// inline methods

inline const std::string& CSingleDocumentTemplateBase::GetDocumentTypeId() const
{
	return m_documentTypeId;
}


// inline protected methods

inline bool CSingleDocumentTemplateBase::IsDocumentTypeSupported(const std::string& documentTypeId) const
{
	return documentTypeId.empty() || (documentTypeId == m_documentTypeId);	// default or the same type is accepted
}


inline bool CSingleDocumentTemplateBase::IsViewTypeSupported(const std::string& viewTypeId) const
{
	return viewTypeId.empty() || (viewTypeId == m_viewTypeId);	// default or the same type is accepted
}


} // namespace idoc


#endif // !idoc_CSingleDocumentTemplateBase_included

