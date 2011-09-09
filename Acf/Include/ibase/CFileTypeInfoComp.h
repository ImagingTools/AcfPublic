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


#ifndef ibase_CFileTypeInfoComp_included
#define ibase_CFileTypeInfoComp_included


#include "iser/IFileTypeInfo.h"

#include "icomp/CComponentBase.h"


namespace ibase
{


/**
	Simple implementation of iser::IFileTypeInfo using user defined extension list and descriptions.
*/
class CFileTypeInfoComp:
			public icomp::CComponentBase,
			virtual public iser::IFileTypeInfo
{
public:
	typedef icomp::CComponentBase BaseClass;

	enum MessageId
	{
		MI_BAD_EXTENSION = 0xac10,
		MI_UNSUPPORTED_VERSION
	};

	I_BEGIN_COMPONENT(CFileTypeInfoComp);
		I_REGISTER_INTERFACE(iser::IFileTypeInfo);
		I_ASSIGN_MULTI_0(m_fileExtensionsAttrPtr, "FileExtensions", "List of supported file extensions", false);
		I_ASSIGN_MULTI_0(m_typeDescriptionsAttrPtr, "TypeDescriptions", "List of descriptions for each extension", false);
	I_END_COMPONENT;

	// reimplemented (iser::IFileTypeInfo)
	virtual bool GetFileExtensions(istd::CStringList& result, int flags = -1, bool doAppend = false) const;
	virtual istd::CString GetTypeDescription(const istd::CString* extensionPtr = NULL) const;

private:
	I_MULTIATTR(istd::CString, m_fileExtensionsAttrPtr);
	I_MULTIATTR(istd::CString, m_typeDescriptionsAttrPtr);
};


} // namespace ibase


#endif // !ibase_CFileTypeInfoComp_included


