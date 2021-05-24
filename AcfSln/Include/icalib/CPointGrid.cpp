/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#include <icalib/CPointGrid.h>


// ACF includes
#include <istd/TDelPtr.h>
#include <istd/CChangeNotifier.h>
#include <iser/IArchive.h>
#include <iser/CArchiveTag.h>


namespace icalib
{


const CPointGrid::Elements& CPointGrid::GetElements() const
{
	return m_elements;
}


// reimplemented (iser::ISerializable)

bool CPointGrid::Serialize(iser::IArchive& archive)
{
	istd::CChangeNotifier notifier(archive.IsStoring() ? NULL : this);
	Q_UNUSED(notifier);

	static iser::CArchiveTag sizeTag("Size", "Size of array", iser::CArchiveTag::TT_GROUP);
	static iser::CArchiveTag cellsTag("Cells", "Values of array cells", iser::CArchiveTag::TT_GROUP);

	bool retVal = true;

	retVal = retVal && archive.BeginTag(sizeTag);
	if (archive.IsStoring()) {
		istd::CIndex2d size = GetSizes();

		retVal = retVal && archive.Process(size[0]);
		retVal = retVal && archive.Process(size[1]);
	}
	else {
		istd::CIndex2d size;

		retVal = retVal && archive.Process(size[0]);
		retVal = retVal && archive.Process(size[1]);

		if (!retVal) {
			return false;
		}

		SetSizes(size);
	}
	retVal = retVal && archive.EndTag(sizeTag);

	retVal = retVal && archive.BeginTag(cellsTag);
	for (Iterator iter = Begin(); iter != End(); ++iter){
		retVal = retVal && iter->Serialize(archive);
	}
	retVal = retVal && archive.EndTag(cellsTag);

	return retVal;
}


// reimplemented (istd::IChangeable)

istd::IChangeable* CPointGrid::CloneMe(CompatibilityMode mode) const
{
	istd::TDelPtr<CPointGrid> retVal(new CPointGrid);

	if (retVal->CopyFrom(*this, mode)){
		return retVal.PopPtr();
	}

	return NULL;
}


bool CPointGrid::CopyFrom(const IChangeable& object, CompatibilityMode /*mode*/)
{
	const CPointGrid* objectPtr = dynamic_cast<const CPointGrid*>(&object);
	if (objectPtr != NULL){
		m_elements = objectPtr->m_elements;

		m_sizes = objectPtr->GetSizes();

		return true;
	}

	return false;
}


} // namespace icalib


