/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqtgui_CModelEditorGuiComp_included
#define iqtgui_CModelEditorGuiComp_included


// ACF includes
#include "imod/IModel.h"
#include "imod/IModelEditor.h"
#include "imod/IObserver.h"

#include "icomp/CComponentBase.h"

#include "iqtgui/IGuiObject.h"


namespace iqtgui
{


/**
	Component realizing static connection between GUI and model components.
	It allows to use boundle of model and GUI-observer components as simple GUI object.
*/
class CModelEditorGuiComp:
			public icomp::CComponentBase,
			virtual public iqtgui::IGuiObject,
			virtual public imod::IModelEditor
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CModelEditorGuiComp);
		I_REGISTER_INTERFACE(iqtgui::IGuiObject);
		I_REGISTER_INTERFACE(imod::IModelEditor);
		I_ASSIGN(m_slaveEditorCompPtr, "SlaveEditorGui", "Slave GUI object will be connected to model", true, "SlaveEditor");
		I_ASSIGN_TO(m_slaveGuiCompPtr, m_slaveEditorCompPtr, true);
		I_ASSIGN_TO(m_slaveObserverCompPtr, m_slaveEditorCompPtr, false);
		I_ASSIGN(m_modelCompPtr, "Model", "Model will be observed and modify using editor", true, "Model");
	I_END_COMPONENT;

	CModelEditorGuiComp();

	// reimplemented (iqtgui::IGuiObject)
	virtual bool IsGuiCreated() const;
	virtual bool CreateGui(QWidget* parentPtr);
	virtual bool DestroyGui();
	virtual QWidget* GetWidget() const;
	virtual void OnTryClose(bool* ignoredPtr = NULL);

	// reimplemented (imod::IModelEditor)
	virtual void UpdateEditor(const istd::IChangeable::ChangeSet& changeSet);
	virtual void UpdateModel() const;
	virtual bool IsReadOnly() const;
	virtual void SetReadOnly(bool state);

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_REF(iqtgui::IGuiObject, m_slaveGuiCompPtr);
	I_REF(imod::IObserver, m_slaveObserverCompPtr);
	I_REF(imod::IModelEditor, m_slaveEditorCompPtr);
	I_REF(imod::IModel, m_modelCompPtr);

	bool m_isConnected;
};


} // namespace iqtgui


#endif // !iqtgui_CModelEditorGuiComp_included


