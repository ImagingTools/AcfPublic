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


#include "iqtproc/CDocumentProcessingCommandComp.h"


// ACF includes
#include "iqtgui/CGuiComponentDialog.h"


namespace iqtproc
{


// protected methods

// reimplemented (iqtproc::CDocumentProcessingManagerCompBase)

void CDocumentProcessingCommandComp::DoDocumentProcessing(const istd::IChangeable* inputDocumentPtr, const std::string& /*documentTypeId*/)
{
	if (!m_outputDataCompPtr.IsValid()){
		SendErrorMessage(0, "Processing result data model not set");

		return;
	}

	istd::CChangeNotifier changePtr(m_outputDataCompPtr.GetPtr());

	int retVal = m_processorCompPtr->DoProcessing(
				m_paramsSetCompPtr.GetPtr(),
				inputDocumentPtr,
				m_outputDataCompPtr.GetPtr(),
				m_progressManagerCompPtr.GetPtr());
	
	if (retVal != iproc::IProcessor::TS_OK){
		SendErrorMessage(0, "Processing was failed", "Document processing manager");

		return;
	}

	changePtr.Reset();

	// show results in the dialog:
	istd::TDelPtr<iqtgui::CGuiComponentDialog> dialogPtr;

	if (m_outputDataGuiCompPtr.IsValid()){
		dialogPtr.SetPtr(
					new iqtgui::CGuiComponentDialog(
								m_outputDataGuiCompPtr.GetPtr(),
								QDialogButtonBox::Ok,
								true));

		dialogPtr->exec();
	}
}


} // namespace iqtproc


