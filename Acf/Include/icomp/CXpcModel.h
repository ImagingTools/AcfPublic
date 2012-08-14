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


#ifndef icomp_CXpcModel_included
#define icomp_CXpcModel_included


// Qt includes
#include <QtCore/QStringList>

// ACF includes
#include "iser/ISerializable.h"


namespace icomp
{


/**
	Data model for ACF package loader configuration.
*/
class CXpcModel: virtual public iser::ISerializable
{
public:
	// gui interface (for editing)
	const QStringList& GetConfFilesList() const;
	void SetConfFilesList(const QStringList& list);
	const QStringList& GetPackageDirsList() const;
	void SetPackageDirsList(const QStringList& list);
	const QStringList& GetPackagesList() const;
	void SetPackagesList(const QStringList& list);

	// program interface (for loading XPC files)
	virtual int GetNumConfFiles() const;
	virtual int GetNumPackageDirs() const;
	virtual int GetNumPackages() const;
	virtual QString GetConfFile(int) const;
	virtual QString GetPackageDir(int) const;
	virtual QString GetPackage(int) const;
	virtual void AddConfFile(const QString& path);
	virtual void AddPackageDir(const QString& path);
	virtual void AddPackage(const QString& path);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	QStringList m_confFiles;
	QStringList m_packageDirs;
	QStringList m_packages;
};


} // namespace icomp


#endif // !icomp_CXpcModel_included


