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


#ifndef iser_CMemoryReadArchive_included
#define iser_CMemoryReadArchive_included


// ACF includes
#include "iser/CBinaryReadArchiveBase.h"


namespace iser
{


class ISerializable;
class CMemoryWriteArchive;


/**
	Implementation of archive using memory buffer to read the persistent objects.
	Internal format of this buffer is compatible with class \c iser::CMemoryWriteArchive.

	\ingroup Persistence
*/
class CMemoryReadArchive: public CBinaryReadArchiveBase
{
public:
	typedef CBinaryReadArchiveBase BaseClass;

	CMemoryReadArchive(
				const void* bufferPtr,
				int bufferSize,
				bool serializeHeader = true);
	CMemoryReadArchive(
				const CMemoryWriteArchive& writeArchive,
				bool serializeHeader = true);

	/**
		Seeks internal cursor to the begin of data.
	*/
	virtual void ResetPosition();

	/**
		Returns \c true if the archive is in valid state 
		and internal position cursor has not reached end of archive data
	*/
	virtual bool IsValid() const;

	// reimplemented (iser::IArchive)
	virtual bool ProcessData(void* data, int size);

	// static methods
	/**
		Clone serializable objects using \c iser::CMemoryWriteArchive and \c iser::CMemoryReadArchive archives.
	*/
	static bool CloneObjectByArchive(const ISerializable& source, ISerializable& result);
	
protected:
	const I_BYTE* m_bufferPtr;
	int m_bufferSize;
	int m_readPosition;
	bool m_isValid;
};


} // namespace iser


#endif // !iser_CMemoryReadArchive_included


