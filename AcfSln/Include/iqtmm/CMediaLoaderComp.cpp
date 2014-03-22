/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iqtmm/CMediaLoaderComp.h"


// Qt includes
#include <QtCore/QFileInfo>


// ACF includes
#include "imm/IMediaController.h"


namespace iqtmm
{


// public methods


// reimplemented (ifile::IFilePersistence)

bool CMediaLoaderComp::IsOperationSupported(
			const istd::IChangeable* dataObjectPtr,
			const QString* filePathPtr,
			int flags,
			bool beQuiet) const
{
	if ((dataObjectPtr != NULL) && (dynamic_cast<const imm::IMediaController*>(dataObjectPtr) == NULL)){
		if (!beQuiet){
			SendInfoMessage(MI_BAD_OBJECT_TYPE, tr("Object is not a valid"));
		}

		return false;
	}

	if (filePathPtr != NULL){
		QFileInfo info(*filePathPtr);

		QStringList extensions;
		if (GetFileExtensions(extensions, flags)){
			QStringList extensionsList = (extensions);

			if (!extensionsList.contains(info.suffix(), Qt::CaseInsensitive)){
				if (!beQuiet){
					SendInfoMessage(MI_BAD_EXTENSION, tr("Bad multimedia file extension %1").arg(info.suffix()));
				}

				return false;
			}
		}
	}

	return ((flags & (QF_FILE | QF_DIRECTORY)) != 0) && ((flags & QF_LOAD) != 0);
}


int CMediaLoaderComp::LoadFromFile(istd::IChangeable& data, const QString& filePath) const
{
	if (IsOperationSupported(&data, &filePath, QF_LOAD | QF_FILE | QF_DIRECTORY, false)){
		imm::IMediaController* controllerPtr = dynamic_cast<imm::IMediaController*>(&data);
		if (controllerPtr != NULL){
			if (controllerPtr->OpenMediumUrl(filePath, *m_autoPlayAttrPtr)){
				return OS_OK;
			}
			else{
				SendInfoMessage(MI_CANNOT_LOAD, tr("Cannot open media '%1'").arg(filePath));
			}
		}
		else{
			SendWarningMessage(MI_BAD_OBJECT_TYPE, tr("Wrong object type"));
		}
	}

	return OS_FAILED;
}


int CMediaLoaderComp::SaveToFile(const istd::IChangeable&/* data*/, const QString&/* filePath*/) const
{
	return OS_FAILED;
}


// reimplemented (ifile::IFileTypeInfo)

bool CMediaLoaderComp::GetFileExtensions(QStringList& result, int flags, bool doAppend) const
{
	if (!doAppend){
		result.clear();
	}

	if ((flags & QF_LOAD) != 0){
		result.push_back("mpg");
		result.push_back("mpeg");
		result.push_back("mov");
		result.push_back("wmv");
		result.push_back("avi");
		result.push_back("m2p");
		result.push_back("mp4");
	}

	return true;
}


QString CMediaLoaderComp::GetTypeDescription(const QString* extensionPtr) const
{
	bool isKnown = (extensionPtr == NULL);

	if (!isKnown){
		QStringList extensions;
		QStringList extensionsList = (extensions);

		if (!extensionsList.contains(*extensionPtr, Qt::CaseInsensitive)){
			isKnown = true;
		}
	}

	if (isKnown){
		return tr("Multimedia");
	}

	return "";
}


} // namespace iqtmm


