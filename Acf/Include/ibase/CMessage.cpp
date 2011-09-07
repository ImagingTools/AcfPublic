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


#include "ibase/CMessage.h"


#include "isys/IDateTime.h"

#include "iser/IArchive.h"


namespace ibase
{		


CMessage::CMessage()
{
	m_time.SetCurrentTime();
}


CMessage::CMessage(
			istd::ILogger::MessageCategory category,
			int id,
			const istd::CString& text,
			const istd::CString& source,
			int flags)
:	m_category(category),
	m_id(id),
	m_text(text),
	m_source(source),
	m_flags(flags)
{
	m_time.SetCurrentTime();
}


void CMessage::SetCategory(istd::ILogger::MessageCategory category)
{
	m_category = category;
}


void CMessage::SetText(const istd::CString& text)
{
	m_text = text;
}


void CMessage::SetSource(const istd::CString& source)
{
	m_source = source;
}


// reimplemented (iser::ISerializable)

bool CMessage::Serialize(iser::IArchive& archive)
{
	int category = m_category;

	static iser::CArchiveTag categoryTag("Category", "Message category");
	bool retVal = archive.BeginTag(categoryTag);
	retVal = retVal && archive.Process(category);
	retVal = retVal && archive.EndTag(categoryTag);

	if (!archive.IsStoring()){
		m_category = istd::ILogger::MessageCategory(category);
	}

	static iser::CArchiveTag textTag("Text", "Message text");
	retVal = retVal && archive.BeginTag(textTag);
	retVal = retVal && archive.Process(m_text);
	retVal = retVal && archive.EndTag(textTag);

	static iser::CArchiveTag sourceTag("Source", "Message source");
	retVal = retVal && archive.BeginTag(sourceTag);
	retVal = retVal && archive.Process(m_source);
	retVal = retVal && archive.EndTag(sourceTag);

	static iser::CArchiveTag timeStampTag("Timestamp", "Message time stamp");
	retVal = retVal && archive.BeginTag(timeStampTag);
	retVal = retVal && m_time.Serialize(archive);
	retVal = retVal && archive.EndTag(timeStampTag);

	return retVal;
}


} // namespace ibase

