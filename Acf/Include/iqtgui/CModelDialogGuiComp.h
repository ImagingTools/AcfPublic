/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqtgui_CModelDialogGuiComp_included
#define iqtgui_CModelDialogGuiComp_included


// ACF includes
#include "imod/IObserver.h"
#include "imod/IModel.h"
#include "imod/TSingleModelObserverBase.h"

#include "iqtgui/CDialogGuiComp.h"


namespace iqtgui
{


/**
	Component for the dialog based model editing.
	You can use it on two ways: connection it to edited model by model/observer concept (\sa imod::IModel)
	or you can set optional reference "Model".
*/
class CModelDialogGuiComp:
			public iqtgui::CDialogGuiComp,
			public imod::TSingleModelObserverBase<istd::IChangeable>
{
public:
	typedef iqtgui::CDialogGuiComp BaseClass;
	typedef imod::TSingleModelObserverBase<istd::IChangeable> BaseClass2;

	I_BEGIN_COMPONENT(CModelDialogGuiComp);
		I_REGISTER_INTERFACE(imod::IObserver);
		I_ASSIGN(m_editorCompPtr, "Gui", "Editor for the model data", true, "ModelObserver");
		I_ASSIGN(m_dataCompPtr, "Model", "Model data", false, "Model");
		I_ASSIGN(m_workingModelFactoryCompPtr, "WorkingDataFactory", "Model factory using to create the working model data", true, "WorkingModelFactory");		
		I_ASSIGN_TO(m_workingDataFactoryCompPtr, m_workingModelFactoryCompPtr, true);
	I_END_COMPONENT;

	// reimplemented (iqtgui::IDialog)
	virtual int ExecuteDialog(IGuiObject* parentPtr);

private:
	I_REF(imod::IObserver, m_editorCompPtr);
	I_REF(istd::IChangeable, m_dataCompPtr);
	I_FACT(imod::IModel, m_workingModelFactoryCompPtr);
	I_FACT(istd::IChangeable, m_workingDataFactoryCompPtr);

	istd::TDelPtr<icomp::IComponent> m_workingObjectPtr;
};


} // namespace iqtgui


#endif // !iqtgui_CModelDialogGuiComp_included

