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


#include "iser/CFileReadArchive.h"


// Qt includes
#include <QtCore/QString>


// ACF includes
#include "iser/CArchiveTag.h"


namespace iser
{


CFileReadArchive::CFileReadArchive(const QString& filePath, bool supportTagSkipping, bool serializeHeader)
:	BaseClass2(filePath),
	m_file(filePath),
	m_supportTagSkipping(supportTagSkipping)
{
	m_file.open(QIODevice::ReadOnly);

	if (serializeHeader){
		SerializeAcfHeader();
	}
}


bool CFileReadArchive::IsTagSkippingSupported() const
{
	return m_supportTagSkipping;
}


bool CFileReadArchive::BeginTag(const CArchiveTag& tag)
{
	bool retVal = BaseClass::BeginTag(tag);

	if (!retVal){
		return false;
	}

	m_tagStack.push_back(TagStackElement());
	TagStackElement& element = m_tagStack.back();

	element.tagBinaryId = tag.GetBinaryId();

	retVal = retVal && Process(element.endPosition);
	element.useTagSkipping = tag.IsTagSkippingUsed() && m_supportTagSkipping;

	return retVal;
}


bool CFileReadArchive::EndTag(const CArchiveTag& tag)
{
	TagStackElement& element = m_tagStack.back();

	bool retVal = (element.tagBinaryId == tag.GetBinaryId());

	if (!retVal){
		I_CRITICAL();	// BeginTag and EndTag have to use the same tag

		return false;
	}

	if (element.useTagSkipping && (element.endPosition != 0)){
		retVal = retVal && m_file.seek(element.endPosition);
	}

	m_tagStack.pop_back();

	return BaseClass::EndTag(tag);
}


bool CFileReadArchive::ProcessData(void* data, int size)
{
	if (size <= 0){
		return true;
	}

	if (data == NULL){
		return false;
	}

	m_file.read((char*)data, size);

	return m_file.error() == QFile::NoError;
}


// protected methods

// reimplemented (istd::ILogger)

void CFileReadArchive::DecorateMessage(
			istd::IInformation::InformationCategory /*category*/,
			int /*id*/,
			int /*flags*/,
			QString& message,
			QString& /*messageSource*/) const
{
	message = m_filePath + " : " + message;
}


} // namespace iser


