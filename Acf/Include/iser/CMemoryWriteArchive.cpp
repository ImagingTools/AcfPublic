/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#include "iser/CMemoryWriteArchive.h"


// STL includes
#include <cstring>


namespace iser
{


CMemoryWriteArchive::CMemoryWriteArchive(
			const IVersionInfo* versionInfoPtr,
			bool serializeHeader)
:	BaseClass(versionInfoPtr), m_serializeHeader(serializeHeader)
{
	Reset();
}


const void* CMemoryWriteArchive::GetBuffer() const
{
	return m_dataBuffer.constData();
}


int CMemoryWriteArchive::GetBufferSize() const
{
	return int(m_dataBuffer.size());
}


void CMemoryWriteArchive::Reset()
{
	m_dataBuffer.clear();

	if (m_serializeHeader){
		SerializeAcfHeader();
	}
}


// reimplemented (iser::IArchive)

bool CMemoryWriteArchive::ProcessData(void* data, int size)
{
	if (size <= 0){
		return true;
	}

	if (data == NULL){
		return false;
	}

	int previousSize = m_dataBuffer.size();

	m_dataBuffer.resize(previousSize + size);

	std::memcpy(m_dataBuffer.data() + previousSize, data, size);

	return true;
}


} // namespace iser


