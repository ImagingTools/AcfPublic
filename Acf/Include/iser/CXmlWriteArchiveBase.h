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


#ifndef iser_CXmlWriteArchiveBase_included
#define iser_CXmlWriteArchiveBase_included


// ACF includes
#include <iser/CTextWriteArchiveBase.h>
#include <iser/CXmlDocumentInfoBase.h>


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
	virtual bool IsTagSkippingSupported() const override;
	virtual bool BeginTag(const CArchiveTag& tag) override;
	virtual bool BeginMultiTag(const CArchiveTag& tag, const CArchiveTag& subTag, int& count) override;
	virtual bool EndTag(const CArchiveTag& tag) override;
	virtual bool Process(QByteArray& value) override;
	virtual bool Process(QString& value) override;
	using BaseClass::Process;

protected:
	CXmlWriteArchiveBase(const IVersionInfo* versionInfoPtr, const CArchiveTag& rootTag);

	bool MakeIndent();

	/**
		Write XML header.
	*/
	bool WriteXmlHeader();
	/**
		Write XML footer.
	*/
	bool WriteXmlFooter();

	// reimplemented (iser::CTextWriteArchiveBase)
    bool WriteTextNode(const QByteArray& text) override;

	// abstract methods
	virtual bool WriteString(const QByteArray& value) = 0;

private:
	CArchiveTag m_rootTag;

	int m_indent;

	bool m_isSeparatorNeeded;
};


} // namespace iser


#endif // !iser_CXmlWriteArchiveBase_included


