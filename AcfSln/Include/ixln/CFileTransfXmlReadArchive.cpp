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


#include "ixln/CFileTransfXmlReadArchive.h"


#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMImplementation.hpp>

#include <xalanc/XalanTransformer/XalanTransformer.hpp>
#include <xalanc/XercesParserLiaison/FormatterToXercesDOM.hpp>


XALAN_USING_XERCES(DOMDocument)
XALAN_USING_XERCES(DOMImplementation)

XALAN_USING_XALAN(XalanTransformer)
XALAN_USING_XALAN(FormatterToXercesDOM)


namespace ixln
{


CFileTransfXmlReadArchive::CFileTransfXmlReadArchive(
			const istd::CString& filePath,
			const istd::CString& transfFilePath,
			bool serializeHeader,
			const iser::CArchiveTag& rootTag)
:	BaseClass(rootTag)
{
	DOMDocument* documentPtr = DOMImplementation::getImplementation()->createDocument();    
	if (documentPtr != NULL){
		FormatterToXercesDOM formatter(documentPtr, NULL);

		// Now do the transform as normal
		XalanTransformer transformer;

		if (transformer.transform(
					filePath.ToString().c_str(), 
					transfFilePath.ToString().c_str(), 
					formatter) == 0){
			m_documentPtr = documentPtr;

			m_nodePtr = m_documentPtr->getFirstChild();

			if (!CheckRootNode()){
				m_documentPtr->release();
				m_documentPtr = NULL;
				m_nodePtr = NULL;
			}

			if (serializeHeader){
				SerializeAcfHeader();
			}
		}
	}
}


} // namespace ixln


