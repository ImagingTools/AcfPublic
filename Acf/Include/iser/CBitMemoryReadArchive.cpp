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


#include "iser/CBitMemoryReadArchive.h"


// STL includes
#include <cstring>


namespace iser
{


// public methods

CBitMemoryReadArchive::CBitMemoryReadArchive(const QVector<quint8>& data, bool serializeHeader)
:	BaseClass(&data[0], data.size(), serializeHeader)	
{
	m_bitPosition = 0;
}


CBitMemoryReadArchive::CBitMemoryReadArchive(const void* bufferPtr, int bufferSize, bool serializeHeader)
	:BaseClass(bufferPtr, bufferSize, serializeHeader)	
{
	m_bitPosition = 0;
}


CBitMemoryReadArchive::CBitMemoryReadArchive(const CMemoryWriteArchive& writeArchive, bool serializeHeader)
	:BaseClass(writeArchive, serializeHeader)	
{
	m_bitPosition = 0;
}


quint32 CBitMemoryReadArchive::ReadValue(int bits)
{
	if (!IsValid()){
		return 0;
	}

	quint32 retVal = 0;

	for (int bitIndex = m_bitPosition, localBitIndex = 0; bitIndex < m_bitPosition + bits; bitIndex++, localBitIndex++){
		int localByteIndex = bitIndex / 8;
		int contextBitIndex = bitIndex % 8;
		int contextMask = 1 << ((8 - contextBitIndex) - 1);

		bool bitOn = (*(m_bufferPtr + localByteIndex) & contextMask) != 0;
		if (bitOn){
			retVal |= 1 << (bits - localBitIndex - 1);
		}
	}

	m_bitPosition += bits;

	return retVal;
}


// reimplemented (iser::IArchive)

bool CBitMemoryReadArchive::ProcessData(void* data, int size)
{
	bool retVal = BaseClass::ProcessData(data, size);
	if (retVal){
		m_bitPosition += size * 8;
	}

	return retVal;
}


bool CBitMemoryReadArchive::ProcessBits(void* dataPtr, int bitsCount, int bytesCount)
{
	I_ASSERT(bytesCount >= 1);

	if (bytesCount > 4){
		return false;
	}

	quint32 retVal = ReadValue(bitsCount);
	
	std::memcpy(dataPtr, &retVal, bytesCount);

	return true;
}


// reimplemented (iser::CMemoryReadArchive)

void CBitMemoryReadArchive::ResetPosition()
{
	m_bitPosition = 0;

	BaseClass::ResetPosition();
}


bool CBitMemoryReadArchive::IsValid() const
{
	int bytePosition = m_bitPosition / 8;

	return bytePosition < m_bufferSize;
}


} // namespace iser

