/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqtproc_CDocumentProcessingCommandComp_included
#define iqtproc_CDocumentProcessingCommandComp_included


// ACF includes
#include "iqtproc/CDocumentProcessingManagerCompBase.h"


namespace iqtproc
{


/**
	Component to trigger some processing action for the current document.
*/
class CDocumentProcessingCommandComp: public iqtproc::CDocumentProcessingManagerCompBase
{
public:
	typedef iqtproc::CDocumentProcessingManagerCompBase BaseClass;
	
	I_BEGIN_COMPONENT(CDocumentProcessingCommandComp);
		I_ASSIGN(m_outputDataCompPtr, "OutputData", "Result of document processing", true, "OutputData");
		I_ASSIGN(m_outputDataGuiCompPtr, "OutputDataGui", "UI to show the output data object", false, "OutputDataGui");
	I_END_COMPONENT;

protected:
	// reimplemented (iqtproc::CDocumentProcessingManagerCompBase)
	void DoDocumentProcessing(const istd::IChangeable* inputDocumentPtr, const std::string& documentTypeId);

private:
	I_REF(istd::IChangeable, m_outputDataCompPtr);
	I_REF(iqtgui::IGuiObject, m_outputDataGuiCompPtr);
};


} // namespace iproc


#endif // !iqtproc_CDocumentProcessingCommandComp_included
