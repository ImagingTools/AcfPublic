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


#ifndef iser_CReadArchiveBase_included
#define iser_CReadArchiveBase_included


// ACF includes
#include <iser/CArchiveBase.h>
#include <iser/CArchiveHeaderInfo.h>


namespace iser
{


/**
	Basic implementation of an abstract archive for data reading.
*/
class CReadArchiveBase: public CArchiveBase
{
public:
	// reimplemented (iser::IArchive)
	virtual bool IsStoring() const override;
	virtual const IVersionInfo& GetVersionInfo() const override;
	virtual bool ProcessBits(void* dataPtr, int bitsCount, int bytesCount) override;

protected:
	/**
		Serialize standard header.
		During serialization of header list of known versions will be loaded.
	*/
	bool SerializeAcfHeader();

private:
	CArchiveHeaderInfo m_versionInfo;
};


} // namespace iser


#endif // !iser_CReadArchiveBase_included


