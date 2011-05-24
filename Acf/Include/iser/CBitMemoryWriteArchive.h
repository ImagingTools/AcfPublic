/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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


#ifndef iser_CBitMemoryWriteArchive_included
#define iser_CBitMemoryWriteArchive_included


// ACF includes
#include "iser/CMemoryWriteArchive.h"


namespace iser
{


/**
	This is an archive implementation which provides bitwise write of data.

	\ingroup Persistence
*/
class CBitMemoryWriteArchive: public CMemoryWriteArchive
{
public:
	typedef CMemoryWriteArchive BaseClass;

	CBitMemoryWriteArchive(const IVersionInfo* versionInfoPtr = NULL, bool serializeHeader = true);

	/**
		Pushes a value of the \c word bounding by N \c bits into the stream.
	*/
	void WriteValue(I_DWORD inputValue, int bits);

	// reimplemented (iser::IArchive)
	virtual bool ProcessData(void* data, int size);
	virtual bool ProcessBits(void* data, int bitsCount, int bytesCount);

protected:
	int m_bitPosition;
};



} // namespace iser


#endif // !iser_CBitMemoryWriteArchive_included

