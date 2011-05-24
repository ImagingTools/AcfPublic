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


#ifndef ixln_CXercesBase_included
#define ixln_CXercesBase_included


#include <xercesc/dom/DOM.hpp>

#include "iser/CArchiveTag.h"


namespace ixln
{


/**
	Base class for implementations using XERCES library.
*/
class CXercesBase
{
public:
	explicit CXercesBase();

    virtual ~CXercesBase();

protected:
	static void AddXercescRef();
	static void RemXercescRef();

	xercesc::DOMNode* m_nodePtr;
	xercesc::DOMDocument* m_documentPtr;

	typedef std::basic_string<XMLCh> XmlString;
	static const XmlString s_text;

private:
	static int s_xercescInstanceCount;
};


} // namespace ixln


#endif // !ixln_CXercesBase_included


