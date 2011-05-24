/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef ixln_CXmlWriteArchiveBase_included
#define ixln_CXmlWriteArchiveBase_included


#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/framework/XMLFormatter.hpp>

#include "istd/TDelPtr.h"

#include "iser/CTextWriteArchiveBase.h"
#include "iser/CXmlDocumentInfoBase.h"

#include "ixln/CXercesBase.h"


namespace ixln
{


/**
	Base class for XERCES based write archive.
*/
class CXmlWriteArchiveBase: public iser::CTextWriteArchiveBase, public CXercesBase, public iser::CXmlDocumentInfoBase
{
public:
	typedef iser::CTextWriteArchiveBase BaseClass;

	virtual ~CXmlWriteArchiveBase();

	bool IsValid();
	bool Flush();

	// reimplemented (iser::IArchive)
	virtual bool BeginTag(const iser::CArchiveTag& tag);
	virtual bool BeginMultiTag(const iser::CArchiveTag& tag, const iser::CArchiveTag& subTag, int& count);
	virtual bool EndTag(const iser::CArchiveTag& tag);
	virtual bool Process(std::string& data);
	virtual bool Process(istd::CString& data);

protected:
	CXmlWriteArchiveBase(const iser::IVersionInfo* versionInfoPtr, const iser::CArchiveTag& rootTag);

	void Init(xercesc::XMLFormatTarget* formTarget);
	void Reset();

private:
	bool m_isFlushed;
	bool m_isFirstParamInTag;

	xercesc::DOMWriter* m_writerPtr;
	istd::TDelPtr<xercesc::XMLFormatTarget> m_formTargetPtr;

	iser::CArchiveTag m_rootTag;
};


} // namespace ixln


#endif // !ixln_CXmlWriteArchiveBase_included


