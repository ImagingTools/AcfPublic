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


#ifndef iqtgui_CModelDialogGuiComp_included
#define iqtgui_CModelDialogGuiComp_included


// ACF includes
#include "imod/IObserver.h"
#include "imod/IModel.h"

#include "iqtgui/CDialogGuiComp.h"


namespace iqtgui
{


/**
	Component for the dialog based model editing.
*/
class CModelDialogGuiComp: public iqtgui::CDialogGuiComp
{
public:
	typedef iqtgui::CDialogGuiComp BaseClass;

	I_BEGIN_COMPONENT(CModelDialogGuiComp)
		I_ASSIGN(m_editorCompPtr, "Gui", "Editor for the model data", true, "ModelObserver");
		I_ASSIGN(m_modelCompPtr, "Model", "Model data", true, "Model");
		I_ASSIGN(m_dataCompPtr, "Model", "Model data", true, "Model");
		I_ASSIGN(m_workingModelFactoryCompPtr, "WorkingDataFactory", "Model factory using to create the working model data", true, "WorkingModelFactory");		
		I_ASSIGN(m_workingDataFactoryCompPtr, "WorkingDataFactory", "Model factory using to create the working model data", true, "WorkingModelFactory");
	I_END_COMPONENT

	// reimplemented (iqtgui::IDialog)
	virtual void Execute();

private:
	I_REF(imod::IObserver, m_editorCompPtr);
	I_REF(imod::IModel, m_modelCompPtr);
	I_REF(istd::IChangeable, m_dataCompPtr);
	I_FACT(imod::IModel, m_workingModelFactoryCompPtr);
	I_FACT(istd::IChangeable, m_workingDataFactoryCompPtr);

	istd::TDelPtr<istd::IChangeable> m_workingDataPtr;
};


} // namespace iqtgui


#endif // !iqtgui_CModelDialogGuiComp_included

