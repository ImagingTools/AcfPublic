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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
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
	bool retVal = true;

	static iser::CArchiveTag minValueTag("MinValue", "Minimal range value");
	retVal = retVal && archive.BeginTag(minValueTag);
	retVal = retVal && archive.Process(range.GetMinValueRef());
	retVal = retVal && archive.EndTag(minValueTag);

	static iser::CArchiveTag maxValueTag("MaxValue", "Maximal range value");
	retVal = retVal && archive.BeginTag(maxValueTag);
	retVal = retVal && archive.Process(range.GetMaxValueRef());
	retVal = retVal && archive.EndTag(maxValueTag);

	return retVal;
}


bool CPrimitiveTypesSerializer::SerializeDateTime(iser::IArchive& archive, QDateTime& dateTime)
{
	if (archive.IsStoring()){
		QString dateTimeString = dateTime.toString(Qt::ISODate);

		return archive.Process(dateTimeString);
	}
	else{
		QString dateTimeString;

		if (archive.Process(dateTimeString)){
			dateTime = QDateTime::fromString(dateTimeString, Qt::ISODate);;
		}
	}

	return false;
}


} // namespace iser


