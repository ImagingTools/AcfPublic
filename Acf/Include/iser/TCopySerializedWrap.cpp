/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#include <iser/TCopySerializedWrap.h>


// ACF includes
#include <iser/ISerializable.h>
#include <iser/CMemoryReadArchive.h>
#include <iser/CMemoryWriteArchive.h>


namespace iser
{


bool CopyByArchive(const istd::IChangeable& object, istd::IChangeable& result)
{
	const ISerializable* sourcePtr = dynamic_cast<const ISerializable*>(&object);
	if (sourcePtr == NULL){
		return false;
	}

	ISerializable* resultPtr = dynamic_cast<ISerializable*>(&result);
	if (resultPtr == NULL){
		return false;
	}

	return CMemoryReadArchive::CloneObjectByArchive(*sourcePtr, *resultPtr);
}


bool CompareByArchive(const istd::IChangeable& object1, const istd::IChangeable& object2)
{
	const ISerializable* object1Ptr = dynamic_cast<const ISerializable*>(&object1);
	if (object1Ptr == NULL){
		return false;
	}

	const ISerializable* object2Ptr = dynamic_cast<const ISerializable*>(&object2);
	if (object2Ptr == NULL){
		return false;
	}

	bool retVal = true;
	CMemoryWriteArchive archive1;
	retVal = retVal && const_cast<ISerializable*>(object1Ptr)->Serialize(archive1);

	CMemoryWriteArchive archive2;
	retVal = retVal && const_cast<ISerializable*>(object2Ptr)->Serialize(archive2);

	return (archive1 == archive2);
}



} // namespace iser


