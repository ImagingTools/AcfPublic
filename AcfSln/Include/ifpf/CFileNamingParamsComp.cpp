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


// AcfSln includes
#include "ifpf/CFileNamingParamsComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"

#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace ifpf
{


CFileNamingParamsComp::CFileNamingParamsComp()
	:m_renamingMode(RM_NUMBERING)
{
}

// reimplemented (ifpf::IFileNamingParams)

int CFileNamingParamsComp::GetRenamingMode() const
{
	return m_renamingMode;
}


void CFileNamingParamsComp::SetRenamingMode(int renamingMode)
{
	if (m_renamingMode != renamingMode){
		istd::CChangeNotifier changePtr(this);

		m_renamingMode = renamingMode;
	}
}


QString CFileNamingParamsComp::GetPrefix() const
{
	return m_prefix;
}


void CFileNamingParamsComp::SetPrefix(const QString& prefix)
{
	if (m_prefix != prefix){
		istd::CChangeNotifier changePtr(this);

		m_prefix = prefix;
	}
}


QString CFileNamingParamsComp::GetSuffix() const
{
	return m_suffix;
}


void CFileNamingParamsComp::SetSuffix(const QString& suffix)
{
	if (m_suffix != suffix){
		istd::CChangeNotifier changePtr(this);

		m_suffix = suffix;
	}
}


// reimplemented (iser::ISerializable)

bool CFileNamingParamsComp::Serialize(iser::IArchive& archive)
{		
	bool retVal = true;

	static iser::CArchiveTag renamingModeTag("RenamingMode", "Mode for the file renaming");
	retVal = retVal && archive.BeginTag(renamingModeTag);
	retVal = retVal && archive.Process(m_renamingMode);
	retVal = retVal && archive.EndTag(renamingModeTag);

	static iser::CArchiveTag prefixTag("FilePrefix", "File prefix");
	retVal = retVal && archive.BeginTag(prefixTag);
	retVal = retVal && archive.Process(m_prefix);
	retVal = retVal && archive.EndTag(prefixTag);

	static iser::CArchiveTag suffixTag("FileSuffix", "FileSuffix");
	retVal = retVal && archive.BeginTag(suffixTag);
	retVal = retVal && archive.Process(m_suffix);
	retVal = retVal && archive.EndTag(suffixTag);

	return retVal;
}


} // namespace ifpf


