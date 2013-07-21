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


#include "iser/CMemoryReadArchive.h"


// STD includes
#include <cstring>


// ACF includes
#include "istd/TChangeNotifier.h"

#include "iser/ISerializable.h"
#include "iser/CMemoryWriteArchive.h"


namespace iser
{


CMemoryReadArchive::CMemoryReadArchive(
			const void* bufferPtr,
			int bufferSize,
			bool serializeHeader)
:	m_bufferPtr((const quint8*)bufferPtr),
	m_bufferSize(bufferSize),
	m_readPosition(0),
	m_isValid(true)
{
	if (serializeHeader){
		m_isValid = SerializeAcfHeader();
	}
}


CMemoryReadArchive::CMemoryReadArchive(
			const CMemoryWriteArchive& writeArchive,
			bool serializeHeader)
:	m_bufferPtr((const quint8*)writeArchive.GetBuffer()),
	m_bufferSize(writeArchive.GetBufferSize()),
	m_readPosition(0),
	m_isValid(true)
{
	if (serializeHeader){
		m_isValid = SerializeAcfHeader();
	}
}


void CMemoryReadArchive::ResetPosition()
{
	m_readPosition = 0;

	if (m_bufferSize > 0){
		m_isValid = true;
	}
}


bool CMemoryReadArchive::IsValid() const
{
	return m_isValid;
}


// reimplemented (iser::IArchive)

bool CMemoryReadArchive::ProcessData(void* data, int size)
{
	if (m_readPosition + size > m_bufferSize){
		m_isValid = false;
	}

	if (!m_isValid){
		return false;
	}

	std::memcpy(data, m_bufferPtr + m_readPosition, size);
	m_readPosition += size;

	return true;
}


// static methods

bool CMemoryReadArchive::CloneObjectByArchive(const ISerializable& source, ISerializable& result)
{
	bool retVal = true;
	CMemoryWriteArchive stored;
	retVal = retVal && const_cast<ISerializable&>(source).Serialize(stored);

	istd::CChangeNotifier notifier(&result);

	CMemoryReadArchive restore(stored);
	retVal = retVal && result.Serialize(restore);

	return retVal;
}


} // namespace iser


