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


#ifndef ifile_CFileTypeInfoComp_included
#define ifile_CFileTypeInfoComp_included


// ACF includes
#include "icomp/CComponentBase.h"
#include "ifile/IFileTypeInfo.h"


namespace ifile
{


/**
	Simple implementation of ifile::IFileTypeInfo using user defined extension list and descriptions.

	\ingroup Persistence
*/
class CFileTypeInfoComp:
			public icomp::CComponentBase,
			virtual public ifile::IFileTypeInfo
{
public:
	typedef icomp::CComponentBase BaseClass;

	enum MessageId
	{
		MI_BAD_EXTENSION = 0xac10,
		MI_UNSUPPORTED_VERSION
	};

	I_BEGIN_COMPONENT(CFileTypeInfoComp);
		I_REGISTER_INTERFACE(ifile::IFileTypeInfo);
		I_ASSIGN_MULTI_0(m_fileExtensionsAttrPtr, "FileExtensions", "List of supported file extensions", false);
		I_ASSIGN_MULTI_0(m_typeDescriptionsAttrPtr, "TypeDescriptions", "List of descriptions for each extension", false);
	I_END_COMPONENT;

	// reimplemented (ifile::IFileTypeInfo)
	virtual bool GetFileExtensions(QStringList& result, const istd::IChangeable* dataObjectPtr = NULL, int flags = -1, bool doAppend = false) const;
	virtual QString GetTypeDescription(const QString* extensionPtr = NULL) const;

private:
	I_MULTIATTR(QString, m_fileExtensionsAttrPtr);
	I_MULTIATTR(QString, m_typeDescriptionsAttrPtr);
};


} // namespace ifile


#endif // !ifile_CFileTypeInfoComp_included


