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


#include "ifile/CFileNameParamComp.h"


// ACF includes
#include "istd/CChangeNotifier.h"

#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace ifile
{


// reimplemented (ifile::IFileNameParam)

int CFileNameParamComp::GetPathType() const
{
	Q_ASSERT(m_pathTypeAttrPtr.IsValid());

	return *m_pathTypeAttrPtr;
}


const QString& CFileNameParamComp::GetPath() const
{
	return m_path;
}


void CFileNameParamComp::SetPath(const QString& path)
{
	if (path != m_path){
		istd::CChangeNotifier notifier(this);

		m_path = path;
	}
}


// reimplemented (iser::ISerializable)

bool CFileNameParamComp::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	QString filePath = m_path;

	static iser::CArchiveTag pathTag("Path", "File path", iser::CArchiveTag::TT_LEAF);
	retVal = retVal && archive.BeginTag(pathTag);
	retVal = retVal && archive.Process(filePath);
	retVal = retVal && archive.EndTag(pathTag);

	if (!archive.IsStoring() && (filePath != m_path)){
		istd::CChangeNotifier notifier(this, &GetAllChanges());
		Q_UNUSED(notifier);

		m_path = filePath;
	}

	return retVal;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CFileNameParamComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_defaultDirAttrPtr.IsValid()){
		m_path = *m_defaultDirAttrPtr;
	}
}


} // namespace ifile


