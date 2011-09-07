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


#include "idoc/CSerializedStateComparator.h"


#include "iser/ISerializable.h"


namespace idoc
{


void CSerializedStateComparator::StoreState(const istd::IChangeable& document)
{
	m_storedArchive.Reset();

	const iser::ISerializable* serializablePtr = dynamic_cast<const iser::ISerializable*>(&document);
	if (serializablePtr != NULL){
		const_cast<iser::ISerializable*>(serializablePtr)->Serialize(m_storedArchive);
	}
}


bool CSerializedStateComparator::CheckStateEquals(const istd::IChangeable& document) const
{
	iser::CMemoryWriteArchive compareArchive;

	const iser::ISerializable* serializablePtr = dynamic_cast<const iser::ISerializable*>(&document);
	if (serializablePtr != NULL){
		const_cast<iser::ISerializable*>(serializablePtr)->Serialize(compareArchive);
	}

	return compareArchive == m_storedArchive;
}


} // namespace idoc


