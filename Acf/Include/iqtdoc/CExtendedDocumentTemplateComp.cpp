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


#include "iqtdoc/CExtendedDocumentTemplateComp.h"


// Qt includes
#include <QtCore/QFileInfo>


namespace iqtdoc
{


// reimplemented (idoc::IDocumentTemplate)

idoc::IDocumentTemplate::Ids CExtendedDocumentTemplateComp::GetDocumentTypeIdsForFile(const QString& filePath) const
{
	idoc::IDocumentTemplate::Ids retVal;

	idoc::IDocumentTemplate::Ids allIds = GetDocumentTypeIds();

	QFileInfo fileInfo(filePath);

	for (		IDocumentTemplate::Ids::const_iterator documentIdIter = allIds.begin();
				documentIdIter != allIds.end();
				++documentIdIter){
		const QByteArray& id = *documentIdIter;

		QStringList extensions;
		ifile::IFilePersistence* loaderPtr = GetFileLoader(id);
		if ((loaderPtr != NULL) && loaderPtr->GetFileExtensions(extensions)){
			for (		QStringList::const_iterator extensionIter = extensions.begin();
						extensionIter != extensions.end();
						++extensionIter){
				QString extension = *extensionIter;

				if (fileInfo.suffix().compare(extension, Qt::CaseInsensitive) == 0){
					retVal.push_back(id);

					break;
				}
			}
		}
	}

	return retVal;
}


// protected methods

// reimplemented (idoc::CSingleDocumentTemplateComp)

istd::IPolymorphic* CExtendedDocumentTemplateComp::ExtractViewInterface(icomp::IComponent* componentPtr) const
{
	return m_viewGuiCompFact.ExtractInterface(componentPtr);
}


} // namespace iqtdoc


