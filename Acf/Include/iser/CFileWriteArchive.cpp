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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iser/CFileWriteArchive.h"


// ACF includes
#include "istd/CString.h"


namespace iser
{


CFileWriteArchive::CFileWriteArchive(
			const istd::CString& filePath,
			const IVersionInfo* versionInfoPtr,
			bool supportTagSkipping,
			bool serializeHeader)
:	BaseClass(versionInfoPtr),
	BaseClass2(filePath),
	m_supportTagSkipping(supportTagSkipping)
{
	m_stream.open(filePath.ToString().c_str(), std::fstream::out | std::fstream::binary);

	if (serializeHeader){
		SerializeAcfHeader();
	}
}


void CFileWriteArchive::Flush()
{
	m_stream.flush();
}


// reimplemented (iser::IArchive)

bool CFileWriteArchive::IsTagSkippingSupported() const
{
	return m_supportTagSkipping;
}


bool CFileWriteArchive::BeginTag(const CArchiveTag& tag)
{
	bool retVal = BaseClass::BeginTag(tag);

	if (!retVal){
		return false;
	}

	m_tagStack.push_back(TagStackElement());
	TagStackElement& element = m_tagStack.back();

	element.tagBinaryId = tag.GetBinaryId();
	element.endFieldPosition = (tag.IsTagSkippingUsed() && m_supportTagSkipping)?
				I_DWORD(m_stream.tellp()):
				I_DWORD(0);

	I_DWORD dummyPos = 0;
	retVal = retVal && Process(dummyPos);

	return retVal;
}


bool CFileWriteArchive::EndTag(const CArchiveTag& tag)
{
	TagStackElement& element = m_tagStack.back();

	bool retVal = (element.tagBinaryId == tag.GetBinaryId());

	if (!retVal){
		I_CRITICAL();	// BeginTag and EndTag have to use the same tag

		return false;
	}

	if (element.endFieldPosition != 0){	// add position of the file tag end to the tag begin
		I_DWORD endPosition = m_stream.tellp();

		m_stream.seekp(element.endFieldPosition);

		retVal = retVal && Process(endPosition);

		m_stream.seekp(endPosition);
	}

	m_tagStack.pop_back();

	return retVal && BaseClass::EndTag(tag);
}


bool CFileWriteArchive::ProcessData(void* data, int size)
{
	if (size <= 0){
		return true;
	}

	if (data == NULL){
		return false;
	}

	m_stream.write((char*)data, size);

	return !m_stream.fail();
}


} // namespace iser

