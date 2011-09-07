/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#include "icntl/CMultiLineParamsComp.h"


#include "icntl/CLineParamsComp.h"


namespace icntl
{


// reimplemented (icntl::IMultiLineParams)

int CMultiLineParamsComp::GetLinesCount() const
{
	return m_linesCompPtr.GetCount();
}


ILineParams& CMultiLineParamsComp::GetLineParams(int lineIndex) const
{
	ILineParams* lineParamsPtr = m_linesCompPtr[lineIndex];
	if (lineParamsPtr != NULL){
		return *lineParamsPtr;
	}

	static CLineParamsComp dummyLine;

	return dummyLine;
}


// reimplemented (iser::ISerializable)

bool CMultiLineParamsComp::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	retVal = retVal && SerializeName(archive);

	static iser::CArchiveTag linesTag("Lines", "List of line parameter");
	static iser::CArchiveTag lineTag("Line", "Single light barrier position");

	int barriersCount = GetLinesCount();
	retVal = retVal && archive.BeginMultiTag(linesTag, lineTag, barriersCount);
	if (barriersCount != GetLinesCount()){
		return false;
	}

	for (int lineIndex = 0; lineIndex < barriersCount; ++lineIndex){
		retVal = retVal && archive.BeginTag(lineTag);
		ILineParams& lineParams = GetLineParams(lineIndex);
		retVal = retVal && lineParams.Serialize(archive);
		retVal = retVal && archive.EndTag(lineTag);
	}

	retVal = retVal && archive.EndTag(linesTag);

	return retVal;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CMultiLineParamsComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	SetName(*m_nameAttrPtr);
}


} // namespace icntl


