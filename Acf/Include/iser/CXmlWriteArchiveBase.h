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


#ifndef iser_CXmlWriteArchiveBase_included
#define iser_CXmlWriteArchiveBase_included


// ACF includes
#include "iser/CTextWriteArchiveBase.h"
#include "iser/CXmlDocumentInfoBase.h"


namespace iser
{


/**
	Base class for XML storing archives.
*/
class CXmlWriteArchiveBase: public CTextWriteArchiveBase, public CXmlDocumentInfoBase
{
public:
	typedef CTextWriteArchiveBase BaseClass;

	// reimplemented (iser::IArchive)
	virtual bool IsTagSkippingSupported() const;
	virtual bool BeginTag(const CArchiveTag& tag);
	virtual bool BeginMultiTag(const CArchiveTag& tag, const CArchiveTag& subTag, int& count);
	virtual bool EndTag(const CArchiveTag& tag);
	virtual bool Process(std::string& value);
	virtual bool Process(istd::CString& value);
	using BaseClass::Process;

protected:
	CXmlWriteArchiveBase(const IVersionInfo* versionInfoPtr, const CArchiveTag& rootTag);

	bool Flush();
	bool MakeIndent();

	bool SerializeXmlHeader();

	// abstract methods
	virtual bool WriteString(const std::string& value) = 0;

private:
	CArchiveTag m_rootTag;

	int m_indent;
	bool m_isHeaderSerialized;

	bool m_isSeparatorNeeded;
};


} // namespace iser


#endif // !iser_CXmlWriteArchiveBase_included


