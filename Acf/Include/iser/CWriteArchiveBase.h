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


#ifndef iser_CWriteArchiveBase_included
#define iser_CWriteArchiveBase_included


// ACF includes
#include "iser/IVersionInfo.h"
#include "iser/CArchiveBase.h"


namespace iser
{


/**
	Basic implementation of an abstract archive for data writting.

	\ingroup Persistence
*/
class CWriteArchiveBase: public CArchiveBase
{
public:
	// reimplemented (iser::IArchive)
	virtual bool IsStoring() const;
	virtual const IVersionInfo& GetVersionInfo() const;
	virtual bool ProcessBits(void* dataPtr, int bitsCount, int bytesCount);

protected:
	/**
		Constructor.
		\note Please note no header will be serialized during contruction.
		You have to explicite call method SerializeAcfHeader in your derrived implementation.
	*/
	CWriteArchiveBase(const IVersionInfo* versionInfoPtr);

	/**
		Serialize standard header.
		During serialization of header list of known versions will be loaded.
	*/
	virtual bool SerializeAcfHeader();

	class EmptyVersionInfo: virtual public IVersionInfo
	{
	public:
		// reimplemented (iser::IVersionInfo)
		virtual bool GetVersionNumber(int versionId, quint32& result) const;
		virtual QString GetVersionIdDescription(int versionId) const;
		virtual VersionIds GetVersionIds() const;
		virtual QString GetEncodedVersionName(int versionId, quint32 versionNumber) const;
	};

private:
	const IVersionInfo* m_versionInfoPtr;

	// static attributes
	static EmptyVersionInfo s_emptyVersionInfo;
};


} // namespace iser


#endif // !iser_CWriteArchiveBase_included


