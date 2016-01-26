/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include "ifileproc/CFileNamingParams.h"


// ACF includes
#include "istd/CChangeNotifier.h"
#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace ifileproc
{


// public methods

CFileNamingParams::CFileNamingParams()
	:m_overwriteStrategy(RM_NUMBERING)
{
}


// reimplemented (ifileproc::IFileNamingParams)

CFileNamingParams::OverwriteStrategy CFileNamingParams::GetOverwriteStrategy() const
{
	return m_overwriteStrategy;
}


void CFileNamingParams::SetOverwriteStrategy(OverwriteStrategy overwriteStrategy)
{
	if (m_overwriteStrategy != overwriteStrategy){
		istd::CChangeNotifier changePtr(this);

		m_overwriteStrategy = overwriteStrategy;
	}
}


QString CFileNamingParams::GetPrefix() const
{
	return m_prefix;
}


void CFileNamingParams::SetPrefix(const QString& prefix)
{
	if (m_prefix != prefix){
		istd::CChangeNotifier changePtr(this);

		m_prefix = prefix;
	}
}


QString CFileNamingParams::GetSuffix() const
{
	return m_suffix;
}


void CFileNamingParams::SetSuffix(const QString& suffix)
{
	if (m_suffix != suffix){
		istd::CChangeNotifier changePtr(this);

		m_suffix = suffix;
	}
}


QStringList CFileNamingParams::GetPatternsToRemove() const
{
	return m_patternsToRemove;
}


void CFileNamingParams::SetPatternsToRemove(const QStringList& patternsToRemove)
{
	if (m_patternsToRemove != patternsToRemove){
		istd::CChangeNotifier changePtr(this);

		m_patternsToRemove = patternsToRemove;
	}
}


// reimplemented (iser::ISerializable)

bool CFileNamingParams::Serialize(iser::IArchive& archive)
{		
	static iser::CArchiveTag overwriteStrategyTag("OverwriteStrategy", "Strategy for overwriting of existing files");
	static iser::CArchiveTag prefixTag("FilePrefix", "Prefix for the output file name");
	static iser::CArchiveTag suffixTag("FileSuffix", "Suffix for the output file name");

	istd::CChangeNotifier changePtr(!archive.IsStoring()? this : NULL);

	bool retVal = true;

	int overwriteMode = m_overwriteStrategy;

	retVal = retVal && archive.BeginTag(overwriteStrategyTag);
	retVal = retVal && archive.Process(overwriteMode);
	retVal = retVal && archive.EndTag(overwriteStrategyTag);

	if (retVal){
		m_overwriteStrategy = OverwriteStrategy(overwriteMode);
	}

	retVal = retVal && archive.BeginTag(prefixTag);
	retVal = retVal && archive.Process(m_prefix);
	retVal = retVal && archive.EndTag(prefixTag);

	retVal = retVal && archive.BeginTag(suffixTag);
	retVal = retVal && archive.Process(m_suffix);
	retVal = retVal && archive.EndTag(suffixTag);

	return retVal;
}


} // namespace ifileproc


