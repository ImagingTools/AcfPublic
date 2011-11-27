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


#ifndef iqtprm_CComboParamsManagerGuiComp_included
#define iqtprm_CComboParamsManagerGuiComp_included


#include "iprm/IParamsManager.h"
#include "iprm/ISelectionParam.h"

#include "iqtgui/TDesignerGuiObserverCompBase.h"

#include "iqtprm/Generated/ui_CComboParamsManagerGuiComp.h"


namespace iqtprm
{


class CComboParamsManagerGuiComp: public iqtgui::TDesignerGuiObserverCompBase<
			Ui::CComboParamsManagerGuiComp,
			iprm::IParamsManager>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CComboParamsManagerGuiComp,
				iprm::IParamsManager> BaseClass;

	I_BEGIN_COMPONENT(CComboParamsManagerGuiComp);
		I_ASSIGN(m_paramsGuiCompPtr, "ParamsGui", "GUI object used to display parameters", false, "ParamsGui");
		I_ASSIGN(m_paramsObserverCompPtr, "ParamsGui", "GUI object used to display parameters", false, "ParamsGui");
		I_ASSIGN(m_selectionGuiCompPtr, "SelectionGui", "UI for selection change", false, "SelectionGui");
		I_ASSIGN_TO(m_selectionObserverCompPtr, m_selectionGuiCompPtr, false);
	I_END_COMPONENT;

	CComboParamsManagerGuiComp();

protected:
	void UpdateParamsView(int selectedIndex);
	void EnsureParamsGuiDetached();

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiModelAttached();
	virtual void OnGuiModelDetached();
	virtual void UpdateGui(int updateFlags = 0);

	// reimplemented (iqtgui::CComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiDestroyed();

private:
	I_REF(iqtgui::IGuiObject, m_paramsGuiCompPtr);
	I_REF(imod::IObserver, m_paramsObserverCompPtr);
	I_REF(iqtgui::IGuiObject, m_selectionGuiCompPtr);
	I_REF(imod::IObserver, m_selectionObserverCompPtr);
	
	imod::IModel* m_lastConnectedModelPtr;
};


} // namespace iqtprm


#endif // !iqtprm_CComboParamsManagerGuiComp_included


