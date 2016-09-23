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


#include <imeas/CSamplesInfo.h>


// ACF includes
#include <istd/CChangeNotifier.h>

#include <iser/IArchive.h>
#include <iser/CArchiveTag.h>


namespace imeas
{


CSamplesInfo::CSamplesInfo(const istd::CRange& logicalSamplesRange)
:	m_logicalSamplesRange(logicalSamplesRange)
{
}


const istd::CRange& CSamplesInfo::GetLogicalSamplesRange() const
{
	return m_logicalSamplesRange;
}


void CSamplesInfo::SetLogicalSamplesRange(const istd::CRange& range)
{
	m_logicalSamplesRange = range;
}


// reimplemented (imeas::IDataSequenceInfo)

int CSamplesInfo::GetDefaultSamplesCount() const
{
	return -1;
}


int CSamplesInfo::GetDefaultChannelsCount() const
{
	return 1;
}


// reimplemented (iser::ISerializable)

bool CSamplesInfo::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag logicalRangeTag("LogicalSamplesRange", "Logical range of samples axis, e.g. sampled time span", iser::CArchiveTag::TT_GROUP);

	bool retVal = true;

	retVal = retVal && archive.BeginTag(logicalRangeTag);
	if (archive.IsStoring()){
		double minValue = m_logicalSamplesRange.GetMinValue();
		double maxValue = m_logicalSamplesRange.GetMaxValue();
		retVal = retVal && archive.Process(minValue);
		retVal = retVal && archive.Process(maxValue);
	}
	else{
		istd::CChangeNotifier notifier(this);
		Q_UNUSED(notifier);

		double minValue = 0;
		double maxValue = 0;
		retVal = retVal && archive.Process(minValue);
		retVal = retVal && archive.Process(maxValue);
		if (!retVal){
			return false;
		}

		m_logicalSamplesRange.SetMinValue(minValue);
		m_logicalSamplesRange.SetMaxValue(maxValue);
	}
	retVal = retVal && archive.EndTag(logicalRangeTag);

	return retVal;
}


} // namespace imeas


