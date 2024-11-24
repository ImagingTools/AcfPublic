/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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


#pragma once


// Qt includes
#include <QtCore/QMap>

// ACF includes
#include <iser/IVersionInfo.h>


namespace icomm
{


/**
	Implementation of version information common for different version informations.
	Common version is simple the lowest version for each ID.
*/
class CCommonVersionInfo: virtual public iser::IVersionInfo
{
public:
	CCommonVersionInfo();

	/**
		Set master version information.
	*/
	void SetMasterVersionInfo(const iser::IVersionInfo* versionInfoPtr);
	/**
		Reset version informations.
		If master version information is registered, the stored versions will be overtaken.
	*/
	void Reset();
	/**
		Merge current set of version informations with the other one.
		\param	versionInfo	version informations.
	*/
	void MergeVersions(const iser::IVersionInfo& versionInfo);

	// reimplemented (iser::IVersionInfo)
	virtual VersionIds GetVersionIds() const;
	virtual bool GetVersionNumber(int versionId, quint32& result) const;
	virtual QString GetVersionIdDescription(int versionId) const;
	virtual QString GetEncodedVersionName(int versionId, quint32 versionNumber) const;

protected:
	struct VersionIdElement
	{
		quint32 versionNumber;
		QString description;
	};

private:
	typedef QMap<int, VersionIdElement> VersionElements;
	VersionElements m_versionIdList;

	const iser::IVersionInfo* m_masterVersionInfoPtr;
};


} // namespace icomm


