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


#include "idoc/CDocumentManagerBase.h"


#include "idoc/IDocumentTemplate.h"


namespace idoc
{		


CDocumentManagerBase::CDocumentManagerBase()
:	m_documentTemplatePtr(NULL)
{
}


void CDocumentManagerBase::SetDocumentTemplate(const IDocumentTemplate* documentTemplatePtr)
{
	m_documentTemplatePtr = documentTemplatePtr;

	m_baseAllowedFlags = 0;

	if (m_documentTemplatePtr != NULL){
		m_baseAllowedFlags |= OF_FILE_NEW;

		IDocumentTemplate::Ids docTypeIds = m_documentTemplatePtr->GetDocumentTypeIds();
		for (		IDocumentTemplate::Ids::const_iterator iter = docTypeIds.begin();
					iter != docTypeIds.end();
					++iter){
			const std::string& docTypeId = *iter;

			iser::IFileLoader* loaderPtr = m_documentTemplatePtr->GetFileLoader(docTypeId);
			if (		(loaderPtr != NULL) &&
						loaderPtr->IsOperationSupported(NULL, NULL, iser::IFileLoader::QF_FILE_ONLY | iser::IFileLoader::QF_NO_SAVING)){
				m_baseAllowedFlags |= OF_FILE_OPEN;

				break;
			}
		}
	}
}


// reimplemented (idoc::IDocumentManager)

int CDocumentManagerBase::GetAllowedOperationFlags(const istd::IPolymorphic* viewPtr) const
{
	int retVal = m_baseAllowedFlags;

	if (viewPtr == NULL){
		viewPtr = GetActiveView();
		if (viewPtr == NULL){
			return retVal;
		}
	}

	DocumentInfo docInfo;
	const istd::IChangeable* documentPtr = GetDocumentFromView(*viewPtr, &docInfo);
	if (documentPtr == NULL){
		return retVal;
	}

	if ((m_documentTemplatePtr != NULL) && (documentPtr != NULL)){
		std::string docTypeId = GetDocumentTypeId(*documentPtr);
		iser::IFileLoader* loaderPtr = m_documentTemplatePtr->GetFileLoader(docTypeId);
		if (loaderPtr != NULL){
			if (docInfo.filePath.IsEmpty() || loaderPtr->IsOperationSupported(
						documentPtr,
						&docInfo.filePath,
						iser::IFileLoader::QF_FILE_ONLY | iser::IFileLoader::QF_NO_LOADING)){
				retVal |= OF_FILE_SAVE;
			}

			if (loaderPtr->IsOperationSupported(
						documentPtr,
						NULL,
						iser::IFileLoader::QF_FILE_ONLY | iser::IFileLoader::QF_NO_LOADING)){
				retVal |= OF_FILE_SAVE_AS;
			}
		}
	}

	if (!docInfo.filePath.IsEmpty()){
		retVal |= OF_KNOWN_PATH;
	}

	return retVal;
}


const idoc::IDocumentTemplate* CDocumentManagerBase::GetDocumentTemplate() const
{
	return m_documentTemplatePtr;
}


} // namespace idoc


