/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include <ifile/CComposedFileMetaInfoProviderComp.h>


// Qt includes
#include <QtCore/QFileInfo>

// ACF includes
#include <ifile/IFileTypeInfo.h>


namespace ifile
{


// public methods

// reimplemented (ifile::IFileMetaInfoProvider)

ifile::IFileMetaInfoProvider::MetaInfoPtr CComposedFileMetaInfoProviderComp::GetFileMetaInfo(const QString& filePath) const
{
	QString fileExtension = QFileInfo(filePath).suffix();

	for (int i = 0; i < m_slaveInfoProvidersCompPtr.GetCount(); ++i){
		ifile::IFileMetaInfoProvider* providerPtr = m_slaveInfoProvidersCompPtr[i];

		ifile::IFileTypeInfo* fileTypeInfoPtr = dynamic_cast<ifile::IFileTypeInfo*>(providerPtr);
		if (fileTypeInfoPtr != NULL){
			QStringList supportedExtensions;
			if (fileTypeInfoPtr->GetFileExtensions(supportedExtensions)){
				if (!supportedExtensions.contains(fileExtension, Qt::CaseInsensitive)){
					continue;
				}
			}
		}

		if (providerPtr != NULL){
			MetaInfoPtr retVal = providerPtr->GetFileMetaInfo(filePath);
			if (retVal.IsValid()){
				return retVal;
			}
		}
	}

	return MetaInfoPtr();
}


} // namespace ifile


