/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef iprocgui_CDocumentProcessingManagerComp_included
#define iprocgui_CDocumentProcessingManagerComp_included


// ACF includes
#include <iprocgui/CDocumentProcessingManagerCompBase.h>


namespace iprocgui
{


/**
	Component to trigger document-to-document processing action.

	You can use \c m_inPlaceProcessingAttrPtr to define, 
	weither the new document is created for the processing result or the document is processed "in-place".
*/
class CDocumentProcessingManagerComp: public iprocgui::CDocumentProcessingManagerCompBase
{
public:
	typedef iprocgui::CDocumentProcessingManagerCompBase BaseClass;
	
	I_BEGIN_COMPONENT(CDocumentProcessingManagerComp);
		I_ASSIGN(m_inPlaceProcessingAttrPtr, "InPlaceProcessing", "If enabled, the input document will be the result of processing", false, false);
	I_END_COMPONENT;

protected:
	// reimplemented (iprocgui::CDocumentProcessingManagerCompBase)
	void DoDocumentProcessing(const istd::IChangeable* inputDocumentPtr, const QByteArray& documentTypeId);

private:
	void DoProcessingToOutput(const istd::IChangeable* inputDocumentPtr, const QByteArray& documentTypeId);
	void DoInPlaceProcessing(istd::IChangeable* inputDocumentPtr);

private:
	I_ATTR(bool, m_inPlaceProcessingAttrPtr);
};


} // namespace iproc


#endif // !iprocgui_CDocumentProcessingManagerComp_included
