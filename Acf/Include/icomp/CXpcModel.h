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


#ifndef icomp_CXpcModel_included
#define icomp_CXpcModel_included


// Qt includes
#include <QtCore/QStringList>

// ACF includes
#include <iser/ISerializable.h>


namespace icomp
{

/**
	Data model for registry configuration files (XPC).
*/
class CXpcModel : public iser::ISerializable
{
public:
	// gui interface (for editing)
	const QStringList& GetConfFilesList() const;
	void SetConfFilesList(const QStringList& list);
	const QStringList& GetPackageDirsList() const;
	void SetPackageDirsList(const QStringList& list);
	const QStringList& GetPackagesList() const;
	void SetPackagesList(const QStringList& list);
	const QStringList& GetRegistryFilesList() const;
	void SetRegistryFilesList(const QStringList& list);

	// program interface (for loading XPC files)
	int GetConfigFilesCount() const;
	QString GetConfFile(int) const;
	void AddConfFile(const QString& path);
	int GetPackageDirsCount() const;
	QString GetPackageDir(int) const;
	void AddPackageDir(const QString& path);
	int GetPackagesCount() const;
	QString GetPackage(int) const;
	void AddPackage(const QString& path);
	int GetRegistryFilesCount() const;
	QString GetRegistryFile(int) const;
	void AddRegistryFile(const QString& path);

	// iser::ISerializable interface
	bool Serialize(iser::IArchive& archive);

private:
	QStringList m_confFiles;
	QStringList m_packageDirs;
	QStringList m_packages;
	QStringList m_registryFiles;
};


} // namespace icomp


#endif // !icomp_CXpcModel_included


