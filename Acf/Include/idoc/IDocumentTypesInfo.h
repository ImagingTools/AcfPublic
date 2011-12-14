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


#ifndef idoc_IDocumentTypesInfo_included
#define idoc_IDocumentTypesInfo_included


// ACF includes
#include "istd/IPolymorphic.h"
#include "istd/CString.h"

#include "iser/IFileTypeInfo.h"


namespace idoc
{


/**
	Provide information about different document types.
*/
class IDocumentTypesInfo: virtual public istd::IPolymorphic
{
public:
	typedef std::vector<std::string> Ids;

	/**
		Enumeration for supported types of operation with the document.
	*/
	enum SupportedFeatures
	{
		/**
			A new document can be created.
		*/
		SF_NEW_DOCUMENT = 0x0001,

		/**
			A document is editable.
		*/
		SF_EDIT_DOCUMENT = 0x0010,

		/**
			All features are supported.
		*/
		SF_DEFAULT = 0xffff
	};

	/**
		Return \c true, if the feature(s) is supported by this document template.
	*/
	virtual bool IsFeatureSupported(int featureFlags, const std::string& documentTypeId) const = 0;

	/**
		Get list of supported document ID's can be created for specified file.
	*/
	virtual Ids GetDocumentTypeIds() const = 0;

	/**
		Get human readable name of some document type ID.
		\param	documentTypeId	ID of document type as returned by \c GetDocumentTypeIds().
	*/
	virtual istd::CString GetDocumentTypeName(const std::string& documentTypeId) const = 0;

	/**
		Get file type information object for some selected document type.
		\param	documentTypeId	ID of document type as returned by \c GetDocumentTypeIds().
	*/
	virtual iser::IFileTypeInfo* GetDocumentFileTypeInfo(const std::string& documentTypeId) const = 0;

	/**
		Get list of supported document ID's can be created for specified file.
	*/
	virtual Ids GetDocumentTypeIdsForFile(const istd::CString& filePath) const = 0;

	/**
		Return default directory for specified document type.
		\param	sugestedDir			template directory sugested by user.
		\param	documentTypeIdPtr	optional ID of document type.
	*/
	virtual istd::CString GetDefaultDirectory(const istd::CString& sugestedDir = "", const std::string* documentTypeIdPtr = NULL) const = 0;
};


} // namespace idoc


#endif // !idoc_IDocumentTypesInfo_included


