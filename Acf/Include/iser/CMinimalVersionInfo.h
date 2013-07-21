/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#ifndef iser_CMinimalVersionInfo_included
#define iser_CMinimalVersionInfo_included


// Qt includes
#include <QtCore/QMap>

// ACF includes
#include "iser/IVersionInfo.h"


namespace iser
{


class ISerializable;


/**
	Implementation of interface iser::IVersionInfo using information about
	minimal needed version from interface iser::ISerializable.
	Please note, that list of ID's for version info must be separate created,
	becouse this information can not be retrived from iser::ISerializable.

	\ingroup Persistence
*/
class CMinimalVersionInfo: virtual public IVersionInfo
{
public:
	/**
		Constructor with initialization of reference to iser::ISerializable and registring of standard ID's.
		\param	serializablePtr	pointer to serializable parent object for which minimal needed version will be calculated.
		\param	addStandardIds	if it is true, standard ID will be registered.
	*/
	CMinimalVersionInfo(const ISerializable* serializablePtr, bool addStandardIds = true);

	/**
		Add new version ID.
		\param	versionId	ID of registered version.
		\param	description	description of this ID.
		\return				true, if success.
	*/
	bool AddId(int versionId, const QString& description = "");

	// reimplemented (iser::IVersionInfo)
	virtual bool GetVersionNumber(int versionId, quint32& result) const;
	virtual QString GetVersionIdDescription(int versionId) const;
	virtual VersionIds GetVersionIds() const;
	virtual QString GetEncodedVersionName(int versionId, quint32 versionNumber) const;

private:
	struct Info
	{
		mutable quint32 version;
		QString description;
	};

	typedef QMap<int, Info> Versions;

	Versions m_versions;

	const ISerializable& m_serializable;
};


} // namespace iser


#endif // !iser_CMinimalVersionInfo_included


