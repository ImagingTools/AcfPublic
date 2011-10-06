/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iqtmm/CMediaLoaderComp.h"


// Qt includes
#include <QFileInfo>


// ACF includes
#include "imm/IMediaController.h"


namespace iqtmm
{


// public methods


// reimplemented (iser::IFileLoader)

bool CMediaLoaderComp::IsOperationSupported(
			const istd::IChangeable* dataObjectPtr,
			const istd::CString* filePathPtr,
			int flags,
			bool beQuiet) const
{
	if ((dataObjectPtr != NULL) && (dynamic_cast<const imm::IMediaController*>(dataObjectPtr) == NULL)){
		if (!beQuiet){
			SendInfoMessage(MI_BAD_OBJECT_TYPE, iqt::GetCString(tr("Object is not a valid")));
		}

		return false;
	}

	if (filePathPtr != NULL){
		QString qtFilePath = iqt::GetQString(*filePathPtr);
		QFileInfo info(qtFilePath);

		istd::CStringList extensions;
		if (GetFileExtensions(extensions, flags)){
			QStringList extensionsList = iqt::GetQStringList(extensions);

			if (!extensionsList.contains(info.suffix(), Qt::CaseInsensitive)){
				if (!beQuiet){
					SendInfoMessage(MI_BAD_EXTENSION, iqt::GetCString(tr("Bad multimedia file extension %1").arg(info.suffix())));
				}

				return false;
			}
		}
	}

	return ((flags & (QF_FILE | QF_DIRECTORY)) != 0) && ((flags & QF_LOAD) != 0);
}


int CMediaLoaderComp::LoadFromFile(istd::IChangeable& data, const istd::CString& filePath) const
{
	if (IsOperationSupported(&data, &filePath, QF_LOAD | QF_FILE | QF_DIRECTORY, false)){
		imm::IMediaController* controllerPtr = dynamic_cast<imm::IMediaController*>(&data);
		if (controllerPtr != NULL){
			if (controllerPtr->OpenMediumUrl(filePath, *m_autoPlayAttrPtr)){
				return StateOk;
			}
			else{
				SendInfoMessage(MI_CANNOT_LOAD, iqt::GetCString(tr("Cannot open media '%1'").arg(iqt::GetQString(filePath))));
			}
		}
		else{
			SendWarningMessage(MI_BAD_OBJECT_TYPE, iqt::GetCString(tr("Wrong object type")));
		}
	}

	return StateFailed;
}


int CMediaLoaderComp::SaveToFile(const istd::IChangeable&/* data*/, const istd::CString&/* filePath*/) const
{
	return StateFailed;
}


// reimplemented (iser::IFileTypeInfo)

bool CMediaLoaderComp::GetFileExtensions(istd::CStringList& result, int flags, bool doAppend) const
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


istd::CString CMediaLoaderComp::GetTypeDescription(const istd::CString* extensionPtr) const
{
	bool isKnown = (extensionPtr == NULL);

	if (!isKnown){
		istd::CStringList extensions;
		QStringList extensionsList = iqt::GetQStringList(extensions);

		if (!extensionsList.contains(iqt::GetQString(*extensionPtr), Qt::CaseInsensitive)){
			isKnown = true;
		}
	}

	if (isKnown){
		return iqt::GetCString(tr("Multimedia"));
	}

	return "";
}


} // namespace iqtmm


