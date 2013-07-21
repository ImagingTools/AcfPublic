/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#include "iser/CBitMemoryWriteArchive.h"


namespace iser
{


// public methods

CBitMemoryWriteArchive::CBitMemoryWriteArchive(const IVersionInfo* versionInfoPtr, bool serializeHeader)
:	BaseClass(versionInfoPtr, serializeHeader)
{
	m_bitPosition = 0;
}


void CBitMemoryWriteArchive::WriteValue(quint32 inputValue, int bitsCount)
{
	Q_ASSERT(bitsCount >= 1);
	Q_ASSERT(bitsCount <= 32);

	int newBitPosition = m_bitPosition + bitsCount;
	int newSize = newBitPosition / 8 + ((newBitPosition % 8) != 0);
	m_dataBuffer.resize(newSize);

	for (int bitIndex = 0; bitIndex < bitsCount; bitIndex++){
		int localByteIndex = (m_bitPosition + bitIndex) / 8;
		int contextBitIndex = bitIndex % bitsCount;
		int globalBitIndex = (m_bitPosition + bitIndex) % 8;
		int contextMask = (1 << (bitsCount - contextBitIndex - 1));

		bool bitOn = (inputValue & contextMask) != 0;

		unsigned char& bufferValue = m_dataBuffer[localByteIndex];

		if (bitOn){
			bufferValue |= 1 << (8 - globalBitIndex - 1);
		}
	}

	m_bitPosition += bitsCount;
}


// reimplemented (iser::IArchive)

bool CBitMemoryWriteArchive::ProcessData(void* data, int size)
{
	bool retVal = BaseClass::ProcessData(data, size);
	if (retVal){
		m_bitPosition += size * 8;
	}

	return retVal;
}


bool CBitMemoryWriteArchive::ProcessBits(void* data, int bitsCount, int bytesCount)
{	
	Q_ASSERT(bitsCount <= bytesCount * 8); 

	if (bytesCount == int(sizeof(quint32))){
		WriteValue(*(quint32*)data, bitsCount);
	}

	return true;
}


} // namespace iser

