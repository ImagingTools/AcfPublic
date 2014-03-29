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


#include "iqt2d/CSceneConnectorGuiComp.h"


// ACF includes
#include "iview/IShapeView.h"


namespace iqt2d
{


// reimplemented (ibase::ICommandsProvider)

const ibase::IHierarchicalCommand* CSceneConnectorGuiComp::GetCommands() const
{
	return &m_commands;
}


// protected methods

// reimplemented (iqtgui::CGuiComponentBase)

void CSceneConnectorGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	if (m_sceneGuiCompPtr.IsValid()){
		m_sceneGuiCompPtr->CreateGui(ImageViewFrame);
	}

	if (m_extenderGuiCompPtr.IsValid()){
		if (m_extenderGuiCompPtr->CreateGui(ParamsFrame)){
			QWidget* widgetPtr = m_extenderGuiCompPtr->GetWidget();
			Q_ASSERT(widgetPtr != NULL);	// GUI was created correctly

			QSizePolicy policy = widgetPtr->sizePolicy();

			if ((policy.verticalPolicy() & QSizePolicy::ExpandFlag) == 0){
				QLayout* layoutPtr = ExternFrame->layout();
				if (layoutPtr != NULL){
					QSpacerItem* spacerPtr = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
					layoutPtr->addItem(spacerPtr);
				}
			}
		}
	}

	if (m_sceneProviderCompPtr.IsValid() && m_extenderCompPtr.IsValid()){
		m_extenderCompPtr->AddItemsToScene(m_sceneProviderCompPtr.GetPtr(), IViewExtender::SF_DIRECT);

		iview::IShapeView* viewPtr = m_sceneProviderCompPtr->GetView();
		if (viewPtr != NULL){
			viewPtr->Update();
		}
	}
}


void CSceneConnectorGuiComp::OnGuiDestroyed()
{
	if (m_sceneProviderCompPtr.IsValid() && m_extenderCompPtr.IsValid()){
		m_extenderCompPtr->RemoveItemsFromScene(m_sceneProviderCompPtr.GetPtr());
		iview::IShapeView* viewPtr = m_sceneProviderCompPtr->GetView();
		if (viewPtr != NULL){
			viewPtr->Update();
		}
	}

	if (m_extenderGuiCompPtr.IsValid()){
		m_extenderGuiCompPtr->DestroyGui();
	}

	if (m_sceneGuiCompPtr.IsValid() && m_sceneGuiCompPtr->IsGuiCreated()){
		m_sceneGuiCompPtr->DestroyGui();
	}

	BaseClass::OnGuiDestroyed();
}


// reimplemented (icomp::CComponentBase)

void CSceneConnectorGuiComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	istd::CChangeNotifier changePtr(this, ibase::ICommandsProvider::CF_COMMANDS | istd::IChangeable::CF_MODEL);

	if (m_sceneCommandsCompPtr.IsValid()){
		const ibase::IHierarchicalCommand* commandPtr = m_sceneCommandsCompPtr->GetCommands();
		if (commandPtr != NULL){
			m_commands.JoinLinkFrom(commandPtr);
		}
	}

	if (m_extenderCommandsCompPtr.IsValid()){
		const ibase::IHierarchicalCommand* commandPtr = m_extenderCommandsCompPtr->GetCommands();
		if (commandPtr != NULL){
			m_commands.JoinLinkFrom(commandPtr);
		}
	}
}


void CSceneConnectorGuiComp::OnComponentDestroyed()
{
	istd::CChangeNotifier changePtr(this, ibase::ICommandsProvider::CF_COMMANDS | istd::IChangeable::CF_MODEL);

	m_commands.ResetChilds();

	BaseClass::OnComponentDestroyed();
}


} // namespace iqt2d


