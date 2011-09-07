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


#include "idoc/CSingleDocumentTemplateBase.h"


// STL includes
#include <algorithm>


// ACF includes
#include "istd/CStaticServicesProvider.h"

#include "iser/ISerializable.h"

#include "isys/IFileSystem.h"

#include "idoc/IDocumentManager.h"
#include "idoc/CSerializedStateComparator.h"


namespace idoc
{


void CSingleDocumentTemplateBase::SetSupportedFeatures(int featureFlags)
{
	m_supportedFeatures = featureFlags;
}


void CSingleDocumentTemplateBase::SetDocumentTypeId(const std::string& documentTypeId)
{
	m_documentTypeId = documentTypeId;
}


void CSingleDocumentTemplateBase::SetDefaultDirectory(const istd::CString& defaultDirectory)
{
	m_defaultDirectory = defaultDirectory;
}


// reimplemented (idoc::IDocumentTemplate)

bool CSingleDocumentTemplateBase::IsFeatureSupported(int featureFlags, const std::string& documentId) const
{
	if (documentId == m_documentTypeId){
		return ((m_supportedFeatures & featureFlags) != 0);
	}

	return false;
}


IDocumentTemplate::Ids CSingleDocumentTemplateBase::GetDocumentTypeIds() const
{
	IDocumentTemplate::Ids retVal;

	retVal.push_back(m_documentTypeId);

	return retVal;
}


IDocumentTemplate::Ids CSingleDocumentTemplateBase::GetViewTypeIds(const std::string& documentTypeId) const
{
	if (IsDocumentTypeSupported(documentTypeId)){
		return CSingleDocumentTemplateBase::GetDocumentTypeIds();
	}

	return Ids();
}


IDocumentTemplate::Ids CSingleDocumentTemplateBase::GetDocumentTypeIdsForFile(const istd::CString& filePath) const
{
	IDocumentTemplate::Ids retVal;

	Ids docTypeIds = GetDocumentTypeIds();
	for (		Ids::const_iterator iter = docTypeIds.begin();
				iter != docTypeIds.end();
				++iter){
		const std::string& id = *iter;

		iser::IFileLoader* loaderPtr = GetFileLoader(*iter);
		if (loaderPtr->IsOperationSupported(NULL, &filePath)){
			retVal.push_back(id);
		}
	}

	return retVal;
}


IDocumentStateComparator* CSingleDocumentTemplateBase::CreateStateComparator(const std::string& documentTypeId) const
{
	if (IsDocumentTypeSupported(documentTypeId)){
		return new CSerializedStateComparator;
	}

	return NULL;
}


istd::CString CSingleDocumentTemplateBase::GetDefaultDirectory(const istd::CString& sugestedDir, const std::string* documentTypeIdPtr) const
{
	if (sugestedDir.IsEmpty()){
		if ((documentTypeIdPtr == NULL) || IsDocumentTypeSupported(*documentTypeIdPtr)){
			return m_defaultDirectory;
		}
		else{
			return istd::CString();
		}
	}

	return sugestedDir;
}


} // namespace idoc


