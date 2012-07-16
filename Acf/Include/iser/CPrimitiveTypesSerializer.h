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


#ifndef iser_CPrimitiveTypesSerializer_included
#define iser_CPrimitiveTypesSerializer_included


// Qt includes
#include <QtCore/QDateTime>

// ACF includes
#include "istd/TRange.h"
#include "istd/TRanges.h"
#include "istd/TIndex.h"
#include "iser/IArchive.h"


namespace iser
{


/**
	Implementation range serializer.

	\ingroup Main
*/
class CPrimitiveTypesSerializer
{
public:
	static bool SerializeRange(iser::IArchive& archive, istd::CRange& range);
	static bool SerializeIntRange(iser::IArchive& archive, istd::CIntRange& range);
	static bool SerializeRanges(iser::IArchive& archive, istd::CRanges& ranges);
	static bool SerializeIntRanges(iser::IArchive& archive, istd::CIntRanges& ranges);
	static bool SerializeDateTime(iser::IArchive& archive, QDateTime& dateTime);

	template <int Dimensions>
	static bool SerializeIndex(iser::IArchive& archive, istd::TIndex<Dimensions>& index);
};


// public template methods

template <int Dimensions>
bool CPrimitiveTypesSerializer::SerializeIndex(iser::IArchive& archive, istd::TIndex<Dimensions>& index)
{
	bool retVal = true;

	for (int i = 0; i < Dimensions; ++i){
		retVal = retVal && archive.Process(index[i]);
	}

	return retVal;
}


} // namespace iser


#endif // !iser_CPrimitiveTypesSerializer_included

