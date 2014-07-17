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


#ifndef idoc_CTextFileLoaderComp_included
#define idoc_CTextFileLoaderComp_included


// ACF includes
#include "ifile/IFilePersistence.h"
#include "icomp/CComponentBase.h"


namespace idoc
{


/**
	Persistence component for the files contains plain text.
*/
class CTextFileLoaderComp: public icomp::CComponentBase, public ifile::IFilePersistence
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CTextFileLoaderComp);
		I_REGISTER_INTERFACE(ifile::IFileTypeInfo);
		I_REGISTER_INTERFACE(ifile::IFilePersistence);
		I_ASSIGN_MULTI_1(m_fileExtensionsAttrPtr, "FileExtensions", "List of possible file extensions", true, "txt");
		I_ASSIGN_MULTI_1(m_typeDescriptionsAttrPtr, "TypeDescriptions", "List of descriptions for each extension", true, "Text file");
	I_END_COMPONENT;

	// reimplemented (ifile::IFilePersistence)
	virtual bool IsOperationSupported(
				const istd::IChangeable* dataObjectPtr,
				const QString* filePathPtr = NULL,
				int flags = -1,
				bool beQuiet = true) const;
	virtual int LoadFromFile(
				istd::IChangeable& data,
				const QString& filePath = QString(),
				ibase::IProgressManager* progressManagerPtr = NULL) const;
	virtual int SaveToFile(
				const istd::IChangeable& data,
				const QString& filePath = QString(),
				ibase::IProgressManager* progressManagerPtr = NULL) const;

	// reimplemented (ifile::IFileTypeInfo)
	virtual bool GetFileExtensions(QStringList& result, int flags = -1, bool doAppend = false) const;
	virtual QString GetTypeDescription(const QString* extensionPtr = NULL) const;

private:
	I_MULTIATTR(QString, m_fileExtensionsAttrPtr);
	I_MULTIATTR(QString, m_typeDescriptionsAttrPtr);
};


} // namespace idoc


#endif // !idoc_CTextFileLoaderComp_included


