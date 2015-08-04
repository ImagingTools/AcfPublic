/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef icmpstr_CRegistryLoaderComp_included
#define icmpstr_CRegistryLoaderComp_included


// Qt includes
#include <QtCore/QObject>


// ACF includes
#include "ifile/CXmlFileReadArchive.h"
#include "ifile/CXmlFileWriteArchive.h"

#include "ifile/TFileSerializerComp.h"


namespace icmpstr
{


/**
	Special registry loader supporting of loading layout data.
*/
class CRegistryLoaderComp:
	public QObject,
	public ifile::TFileSerializerComp<ifile::CXmlFileReadArchive, ifile::CXmlFileWriteArchive>
{
	Q_OBJECT

public:
	typedef ifile::TFileSerializerComp<ifile::CXmlFileReadArchive, ifile::CXmlFileWriteArchive> BaseClass;

	I_BEGIN_COMPONENT(CRegistryLoaderComp);
	I_END_COMPONENT;

	enum MessageId
	{
		MI_LOAD_ERROR = 680,
		MI_CANNOT_READ_LAYOUT
	};

	// reimplemented (ifile::IFilePersistence)
	virtual int LoadFromFile(
				istd::IChangeable& data,
				const QString& filePath = QString(),
				ibase::IProgressManager* progressManagerPtr = NULL) const;
	virtual int SaveToFile(
				const istd::IChangeable& data,
				const QString& filePath = QString(),
				ibase::IProgressManager* progressManagerPtr = NULL) const;

	// reimplemented (ifile::IFileTypeInfo)
	virtual bool GetFileExtensions(QStringList& result, const istd::IChangeable* dataObjectPtr = NULL, int flags = -1, bool doAppend = false) const;
	virtual QString GetTypeDescription(const QString* extensionPtr = NULL) const;

protected:
	QString GetLayoutPath(const QString& registryPath) const;

	// reimplemented (ifile::TFileSerializerComp)
	virtual void OnReadError(
				const ifile::CXmlFileReadArchive& archive,
				const istd::IChangeable& data,
				const QString& filePath) const;

	using QObject::tr;
};


} // namespace icmpstr


#endif // !icmpstr_CRegistryLoaderComp_included


