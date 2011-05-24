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


#ifndef ixln_CXmlReadArchiveBase_included
#define ixln_CXmlReadArchiveBase_included


#include <xercesc/util/XMLString.hpp>
#include <xercesc/sax/InputSource.hpp>

#include "iser/CTextReadArchiveBase.h"
#include "iser/CXmlDocumentInfoBase.h"

#include "ixln/CXercesBase.h"


namespace ixln
{


/**
	Base class for XML reading archives.
*/
class CXmlReadArchiveBase: public iser::CTextReadArchiveBase, public CXercesBase, public iser::CXmlDocumentInfoBase
{
public:
	typedef iser::CTextReadArchiveBase BaseClass;

    virtual ~CXmlReadArchiveBase();

	virtual bool IsValid() const;

	// reimplemented (iser::IArchive)
	virtual bool BeginTag(const iser::CArchiveTag& tag);
	virtual bool BeginMultiTag(const iser::CArchiveTag& tag, const iser::CArchiveTag& subTag, int& count);
	virtual bool EndTag(const iser::CArchiveTag& tag);
	virtual bool Process(std::string& data);
	virtual bool Process(istd::CString& data);

protected:
	CXmlReadArchiveBase(const iser::CArchiveTag& rootTag);

	void Init(xercesc::InputSource& inputSource);
    void Reset();

	bool CheckRootNode() const;

private:
	bool m_isValid;

    xercesc::DOMBuilder* m_builder;

	iser::CArchiveTag m_rootTag;
};


} // namespace ixln


#endif // !ixln_CXmlReadArchiveBase_included


