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


#ifndef iser_CMemoryWriteArchive_included
#define iser_CMemoryWriteArchive_included


// Qt includes
#include <QtCore/QVector>

// ACF includes
#include "iser/CBinaryWriteArchiveBase.h"


namespace iser
{


/**
	Implementation of archive using memory buffer to store the persistent objects.
	Internal format of this buffer is compatible with class \c iser::CMemoryReadArchive.

	\ingroup Persistence
*/
class CMemoryWriteArchive: public CBinaryWriteArchiveBase
{
public:
	typedef CBinaryWriteArchiveBase BaseClass;

	CMemoryWriteArchive(
				const IVersionInfo* versionInfoPtr = NULL,
				bool serializeHeader = true);

	const void* GetBuffer() const;
	int GetBufferSize() const;

	/**
		Reset internal buffer.
	*/
	void Reset();

	bool operator==(const CMemoryWriteArchive& archive) const;
	bool operator!=(const CMemoryWriteArchive& archive) const;

	// reimplemented (iser::IArchive)
	virtual bool ProcessData(void* data, int size);
	
protected:
	typedef QVector<unsigned char> DataBuffer;

	DataBuffer m_dataBuffer;

	bool m_serializeHeader;
};


// inline methods

inline bool CMemoryWriteArchive::operator==(const CMemoryWriteArchive& archive) const
{
	return m_dataBuffer == archive.m_dataBuffer;
}


inline bool CMemoryWriteArchive::operator!=(const CMemoryWriteArchive& archive) const
{
	return m_dataBuffer != archive.m_dataBuffer;
}


} // namespace iser


#endif // !iser_CMemoryWriteArchive_included


