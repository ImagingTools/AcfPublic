/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqtprm/CRelativeFileNameParamComp.h"


// Qt includes
#include <QDir>


// ACF includes
#include "istd/TChangeNotifier.h"
#include "iser/IFileArchiveInfo.h"


namespace iqtprm
{


// reimplemented (iprm::IFileNameParam)

const istd::CString& CRelativeFileNameParamComp::GetPath() const
{
	const istd::CString& relativePath = BaseClass::GetPath();

	if (!relativePath.IsEmpty() && m_relativeToCompPtr.IsValid()){
		const istd::CString& basePath = m_relativeToCompPtr->GetPath();
		if (!basePath.IsEmpty()){
			QDir baseDir(iqt::GetQString(basePath));

			m_relativePath = iqt::GetCString(baseDir.absoluteFilePath(iqt::GetQString(relativePath)));

			return m_relativePath;
		}
	}

	return relativePath;
}


void CRelativeFileNameParamComp::SetPath(const istd::CString& path)
{
	if (!path.IsEmpty() && m_relativeToCompPtr.IsValid()){
		const istd::CString& basePath = m_relativeToCompPtr->GetPath();
		if (!basePath.IsEmpty()){
			QDir baseDir(iqt::GetQString(basePath));

			BaseClass::SetPath(iqt::GetCString(baseDir.relativeFilePath(iqt::GetQString(path))));

			return;
		}
	}

	BaseClass::SetPath(path);
}


// reimplemented (iser::ISerializable)

bool CRelativeFileNameParamComp::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	istd::CString documentPath;
	const iser::IFileArchiveInfo* fileArchiveInfoPtr = dynamic_cast<const iser::IFileArchiveInfo*>(&archive);
	if (fileArchiveInfoPtr != NULL){
		documentPath = fileArchiveInfoPtr->GetCurrentFilePath();
	}

	static iser::CArchiveTag pathTag("Path", "File path");

	if (archive.IsStoring()){
		istd::CString filePath = GetPath();

		if (!documentPath.IsEmpty()){
			QFileInfo docuInfo(iqt::GetQString(documentPath));

			filePath = iqt::GetCString(docuInfo.absoluteDir().relativeFilePath(iqt::GetQString(filePath)));
		}

		retVal = retVal && archive.BeginTag(pathTag);
		retVal = retVal && archive.Process(filePath);
		retVal = retVal && archive.EndTag(pathTag);
	}
	else{
		istd::CString filePath;

		retVal = retVal && archive.BeginTag(pathTag);
		retVal = retVal && archive.Process(filePath);
		retVal = retVal && archive.EndTag(pathTag);

		if (!retVal){
			return false;
		}

		if (!documentPath.IsEmpty()){
			QFileInfo docuInfo(iqt::GetQString(documentPath));

			filePath = iqt::GetCString(docuInfo.absoluteDir().absoluteFilePath(iqt::GetQString(filePath)));
		}

		if (filePath != GetPath()){
			istd::CChangeNotifier changePtr(this);

			SetPath(filePath);
		}
	}

	return retVal;
}


} // namespace iqtprm


