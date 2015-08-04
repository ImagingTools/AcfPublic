/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef iser_CReaderVersionInfo_included
#define iser_CReaderVersionInfo_included


// Qt includes
#include <QtCore/QMap>

// ACF includes
#include "iser/IVersionInfo.h"


namespace iser
{


/**
	Implementation of version designed to be automaticaly created during reading of ACF header.
	\sa iser::CReadArchiveBase.

	\ingroup Persistence
*/
class CReaderVersionInfo: virtual public IVersionInfo
{
public:
	enum ChangeFlags
	{
		CF_VERSIONS_UPDATED = 0xb6eca0
	};

	/**
		Remove all stored version infos.
	*/
	void Reset();
	/**
		Insert new version id with its actual version number and its description.
		\sa iser::IVersionInfo.
		\param	versionId		ID of version info.
		\param	versionNumber	version number for specified version info ID.
		\param	description		description of role of specified version info.
	*/
	bool InsertVersionId(int versionId, quint32 versionNumber, const QString& description);
	/**
		Remove single version info.
		\param	versionId	ID of version info.
	*/
	bool RemoveVersionId(int versionId);

	// reimplemented (iser::IVersionInfo)
	virtual VersionIds GetVersionIds() const;
	virtual bool GetVersionNumber(int versionId, quint32& result) const;
	virtual QString GetVersionIdDescription(int versionId) const;
	virtual QString GetEncodedVersionName(int versionId, quint32 versionNumber) const;

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const istd::IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS);

protected:
	struct VersionIdElement
	{
		quint32 versionNumber;
		QString description;
	};

private:
	typedef QMap<int, VersionIdElement> VersionElements;

	VersionElements m_versionIdList;
};


} // namespace iser


#endif // !iser_CReaderVersionInfo_included


