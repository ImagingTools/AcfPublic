/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "idoc/CSingleDocumentTemplateBase.h"


// ACF includes
#include "iser/ISerializable.h"

#include "idoc/IDocumentManager.h"


namespace idoc
{


CSingleDocumentTemplateBase::CSingleDocumentTemplateBase()
:	m_supportedFeatures(0)
{
}


void CSingleDocumentTemplateBase::SetSupportedFeatures(int featureFlags)
{
	m_supportedFeatures = featureFlags;
}


void CSingleDocumentTemplateBase::SetDocumentTypeId(const QByteArray& id)
{
	m_documentTypeId = id;
}


void CSingleDocumentTemplateBase::SetDocumentTypeName(const QString& name)
{
	m_documentTypeName = name;
}


void CSingleDocumentTemplateBase::SetViewTypeId(const QByteArray& id)
{
	m_viewTypeId = id;
}


void CSingleDocumentTemplateBase::SetViewTypeName(const QString& name)
{
	m_viewTypeName = name;
}


void CSingleDocumentTemplateBase::SetDefaultDirectory(const QString& defaultDirectory)
{
	m_defaultDirectory = defaultDirectory;
}


// reimplemented (idoc::IDocumentTypesInfo)

bool CSingleDocumentTemplateBase::IsFeatureSupported(int featureFlags, const QByteArray& documentId) const
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


QString CSingleDocumentTemplateBase::GetDocumentTypeName(const QByteArray& documentTypeId) const
{
	if (documentTypeId == m_documentTypeId){
		if (!m_documentTypeName.isEmpty()){
			return m_documentTypeName;
		}
		else{
			return documentTypeId;
		}
	}
	else{
		return "";
	}
}


ifile::IFileTypeInfo* CSingleDocumentTemplateBase::GetDocumentFileTypeInfo(const QByteArray& documentTypeId) const
{
	return GetFileLoader(documentTypeId);
}


IDocumentTemplate::Ids CSingleDocumentTemplateBase::GetDocumentTypeIdsForFile(const QString& filePath) const
{
	IDocumentTemplate::Ids retVal;

	Ids docTypeIds = GetDocumentTypeIds();
	for (		Ids::const_iterator iter = docTypeIds.begin();
				iter != docTypeIds.end();
				++iter){
		const QByteArray& id = *iter;

		ifile::IFilePersistence* loaderPtr = GetFileLoader(*iter);
		if (loaderPtr->IsOperationSupported(NULL, &filePath)){
			retVal.push_back(id);
		}
	}

	return retVal;
}


QString CSingleDocumentTemplateBase::GetDefaultDirectory(const QString& sugestedDir, const QByteArray* documentTypeIdPtr) const
{
	if (sugestedDir.isEmpty()){
		if ((documentTypeIdPtr == NULL) || IsDocumentTypeSupported(*documentTypeIdPtr)){
			return m_defaultDirectory;
		}
		else{
			return QString();
		}
	}

	return sugestedDir;
}


// reimplemented (idoc::IDocumentTemplate)

IDocumentTemplate::Ids CSingleDocumentTemplateBase::GetViewTypeIds(const QByteArray& documentTypeId) const
{
	IDocumentTemplate::Ids retVal;

	if (documentTypeId == m_documentTypeId){
		retVal.push_back(m_viewTypeId);
	}

	return retVal;
}


QString CSingleDocumentTemplateBase::GetViewTypeName(
			const QByteArray& documentTypeId,
			const QByteArray& viewTypeId) const
{
	if ((documentTypeId == m_documentTypeId) && (viewTypeId == m_viewTypeId)){
		if (!m_viewTypeName.isEmpty()){
			return m_viewTypeName;
		}
		else{
			return m_viewTypeId;
		}
	}

	return QString();
}


} // namespace idoc


