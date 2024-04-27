/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#include <ilog/CTracingConfiguration.h>


// ACF includes
#include <iser/IArchive.h>
#include <iser/CArchiveTag.h>
#include <istd/CChangeNotifier.h>


namespace ilog
{

// public methods

CTracingConfiguration::CTracingConfiguration(): m_tracingLevel(-1)
{

}


// reimplemented (ilog::ITracingConfiguration)
int CTracingConfiguration::GetTracingLevel() const
{
	return m_tracingLevel;
}


void CTracingConfiguration::SetTracingLevel(int tracingLevel)
{
	m_tracingLevel = tracingLevel;
}


// reimplemented (iser::ISerializable)
bool CTracingConfiguration::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag tacingLevelTag("TacingLevel", "Level of tracing messages", iser::CArchiveTag::TT_LEAF);

	istd::CChangeNotifier notifier(archive.IsStoring()? NULL: this);
	Q_UNUSED(notifier);

	bool retVal = true;

	retVal = retVal && archive.BeginTag(tacingLevelTag);
	retVal = retVal && archive.Process(m_tracingLevel);
	retVal = retVal && archive.EndTag(tacingLevelTag);

	return retVal;
}

// protected methods
// reimplemented (icomp::CComponentBase)
void CTracingConfiguration::OnComponentCreated()
{
	if (m_defaultTracingLevel.IsValid()){
		m_tracingLevel = *m_defaultTracingLevel;
	}
}



} // namespace ilog

