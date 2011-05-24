/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iser/TCopySerializedWrap.h"


// ACF includes
#include "iser/ISerializable.h"
#include "iser/CMemoryReadArchive.h"


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




} // namespace iser


