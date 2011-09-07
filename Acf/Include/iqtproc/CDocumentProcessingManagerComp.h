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


#ifndef iqtproc_CDocumentProcessingManagerComp_included
#define iqtproc_CDocumentProcessingManagerComp_included


// ACF includes
#include "iqtproc/CDocumentProcessingManagerCompBase.h"


namespace iqtproc
{


/**
	Component to trigger document-to-document processing action.

	You can use \c m_inPlaceProcessingAttrPtr to define, 
	weither the new document is created for the processing result or the document is processed "in-place".
*/
class CDocumentProcessingManagerComp: public iqtproc::CDocumentProcessingManagerCompBase
{
public:
	typedef iqtproc::CDocumentProcessingManagerCompBase BaseClass;
	
	I_BEGIN_COMPONENT(CDocumentProcessingManagerComp);
		I_ASSIGN(m_inPlaceProcessingAttrPtr, "InPlaceProcessing", "If enabled, the input document will be the result of processing", false, false);
	I_END_COMPONENT;

protected:
	// reimplemented (iqtproc::CDocumentProcessingManagerCompBase)
	void DoDocumentProcessing(const istd::IChangeable* inputDocumentPtr, const std::string& documentTypeId);

private:
	void DoProcessingToOutput(const istd::IChangeable* inputDocumentPtr, const std::string& documentTypeId);
	void DoInPlaceProcessing(istd::IChangeable* inputDocumentPtr);

private:
	I_ATTR(bool, m_inPlaceProcessingAttrPtr);
};


} // namespace iproc


#endif // !iqtproc_CDocumentProcessingManagerComp_included
