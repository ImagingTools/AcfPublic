/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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


#include "iser/CPrimitiveTypesSerializer.h"


// Qt includes
#include <QtCore/QString>

// ACF includes
#include "iser/CArchiveTag.h"


namespace iser
{


// public static methods

bool CPrimitiveTypesSerializer::SerializeRange(iser::IArchive& archive, istd::CRange& range)
{
	static iser::CArchiveTag minValueTag("MinValue", "Minimal range value");
	static iser::CArchiveTag maxValueTag("MaxValue", "Maximal range value");

	bool retVal = true;

	retVal = retVal && archive.BeginTag(minValueTag);
	retVal = retVal && archive.Process(range.GetMinValueRef());
	retVal = retVal && archive.EndTag(minValueTag);

	retVal = retVal && archive.BeginTag(maxValueTag);
	retVal = retVal && archive.Process(range.GetMaxValueRef());
	retVal = retVal && archive.EndTag(maxValueTag);

	return retVal;
}


bool CPrimitiveTypesSerializer::SerializeIntRange(iser::IArchive& archive, istd::CIntRange& range)
{
	static iser::CArchiveTag minValueTag("MinValue", "Minimal range value");
	static iser::CArchiveTag maxValueTag("MaxValue", "Maximal range value");

	bool retVal = true;

	retVal = retVal && archive.BeginTag(minValueTag);
	retVal = retVal && archive.Process(range.GetMinValueRef());
	retVal = retVal && archive.EndTag(minValueTag);

	retVal = retVal && archive.BeginTag(maxValueTag);
	retVal = retVal && archive.Process(range.GetMaxValueRef());
	retVal = retVal && archive.EndTag(maxValueTag);

	return retVal;
}


bool CPrimitiveTypesSerializer::SerializeRanges(iser::IArchive& archive, istd::CRanges& ranges)
{
	static iser::CArchiveTag beginStateTag("BeginState", "Begin state");
	static iser::CArchiveTag switchPointsTag("SwitchPoints", "List of switch point positions");
	static iser::CArchiveTag positionTag("Position", "Switch point position");

	bool retVal = true;

	bool isStoring = archive.IsStoring();

	istd::CRanges::SwitchPoints& switchPoints = ranges.GetSwitchPointsRef();

	retVal = retVal && archive.BeginTag(beginStateTag);
	if (isStoring){
		bool beginState = ranges.GetBeginState();

		retVal = retVal && archive.Process(beginState);
	}
	else{
		bool beginState = false;

		retVal = retVal && archive.Process(beginState);

		ranges.SetBeginState(beginState);
	}

	retVal = retVal && archive.EndTag(beginStateTag);

	int pointsCount = int(switchPoints.size());

	retVal = retVal && archive.BeginMultiTag(switchPointsTag, positionTag, pointsCount);

	if (!retVal){
		return false;
	}

	if (isStoring){
		for (		istd::CRanges::SwitchPoints::iterator iter = switchPoints.begin();
					iter != switchPoints.end();
					++iter){
			retVal = retVal && archive.BeginTag(positionTag);

			double position = 0;
			retVal = retVal && archive.Process(position);
			switchPoints.insert(position);

			retVal = retVal && archive.EndTag(positionTag);
		}
	}
	else{
		switchPoints.clear();

		for (int i = 0; i < pointsCount; ++i){
			retVal = retVal && archive.BeginTag(positionTag);

			double position = 0;
			retVal = retVal && archive.Process(position);
			switchPoints.insert(position);

			retVal = retVal && archive.EndTag(positionTag);
		}
	}

	retVal = retVal && archive.EndTag(switchPointsTag);

	return retVal;
}


bool CPrimitiveTypesSerializer::SerializeIntRanges(iser::IArchive& archive, istd::CIntRanges& ranges)
{
	static iser::CArchiveTag beginStateTag("BeginState", "Begin state");
	static iser::CArchiveTag switchPointsTag("SwitchPoints", "List of switch point positions");
	static iser::CArchiveTag positionTag("Position", "Switch point position");

	bool retVal = true;

	bool isStoring = archive.IsStoring();

	istd::CIntRanges::SwitchPoints& switchPoints = ranges.GetSwitchPointsRef();

	retVal = retVal && archive.BeginTag(beginStateTag);
	if (isStoring){
		bool beginState = ranges.GetBeginState();

		retVal = retVal && archive.Process(beginState);
	}
	else{
		bool beginState = false;

		retVal = retVal && archive.Process(beginState);

		ranges.SetBeginState(beginState);
	}

	retVal = retVal && archive.EndTag(beginStateTag);

	int pointsCount = int(switchPoints.size());

	retVal = retVal && archive.BeginMultiTag(switchPointsTag, positionTag, pointsCount);

	if (!retVal){
		return false;
	}

	if (isStoring){
		for (		istd::CIntRanges::SwitchPoints::iterator iter = switchPoints.begin();
					iter != switchPoints.end();
					++iter){
			retVal = retVal && archive.BeginTag(positionTag);

			int position = 0;
			retVal = retVal && archive.Process(position);
			switchPoints.insert(position);

			retVal = retVal && archive.EndTag(positionTag);
		}
	}
	else{
		switchPoints.clear();

		for (int i = 0; i < pointsCount; ++i){
			retVal = retVal && archive.BeginTag(positionTag);

			int position = 0;
			retVal = retVal && archive.Process(position);
			switchPoints.insert(position);

			retVal = retVal && archive.EndTag(positionTag);
		}
	}

	retVal = retVal && archive.EndTag(switchPointsTag);

	return retVal;
}


bool CPrimitiveTypesSerializer::SerializeDateTime(iser::IArchive& archive, QDateTime& dateTime)
{
	const QString TimeFormat("yyyy-MM-dd hh-mm-ss zzz");

	if (archive.IsStoring()){
		QString dateTimeString = dateTime.toString(TimeFormat);

		return archive.Process(dateTimeString);
	}
	else{
		QString dateTimeString;

		if (archive.Process(dateTimeString)){
			dateTime = QDateTime::fromString(dateTimeString, TimeFormat);

			return true;
		}
	}

	return false;
}


} // namespace iser


