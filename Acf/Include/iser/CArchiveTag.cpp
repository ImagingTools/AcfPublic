/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#include <iser/CArchiveTag.h>


namespace iser
{


CArchiveTag::CArchiveTag()
:	m_binaryId(0),
	m_tagType(TT_UNKNOWN),
	m_parentPtr(NULL),
	m_isTagSkippingUsed(false)
{
}


CArchiveTag::CArchiveTag(
			const QByteArray& id,
			const QByteArray& comment,
			TagType tagType,
			const CArchiveTag* parentPtr,
			bool isTagSkippingUsed)
:	m_id(id),
	m_binaryId(0),
	m_comment(comment),
	m_tagType(tagType),
	m_parentPtr(parentPtr),
	m_isTagSkippingUsed(isTagSkippingUsed)
{
	int idSize = int(m_id.size());

	for (int i = 0; i < idSize; ++i){
		int character = m_id[i];
		int character2 = character * character;
		m_binaryId += (character << i) ^ (character2 >> i);
	}
}


const QByteArray& CArchiveTag::GetId() const
{
	return m_id;
}


quint32 CArchiveTag::GetBinaryId() const
{
	return m_binaryId;
}


const QByteArray& CArchiveTag::GetComment() const
{
	return m_comment;
}


CArchiveTag::TagType CArchiveTag::GetTagType() const
{
	return m_tagType;
}


const CArchiveTag* CArchiveTag::GetParentTag() const
{
	return m_parentPtr;
}


} // namespace iser


