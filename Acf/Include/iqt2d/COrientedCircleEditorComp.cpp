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


#include <iqt2d/COrientedCircleEditorComp.h>


namespace iqt2d
{


COrientedCircleEditorComp::COrientedCircleEditorComp()
:	m_reversePolarityAction(QIcon(":/Icons/Reverse"), "", this)
{

}


// protected methods

// reimplemented (iqt2d::TCircleBasedParamsGuiComp)

bool COrientedCircleEditorComp::PopulateActions(QWidget& host, imod::IModel* modelPtr)
{
	if (!BaseClass::PopulateActions(host, modelPtr)){
		return false;
	}

	i2d::COrientedCircle* circlePtr = dynamic_cast<i2d::COrientedCircle*>(modelPtr);
	if (circlePtr != NULL){
		host.addAction(&m_reversePolarityAction);
	}

	return true;
}


// reimplemented (iqtgui::CGuiComponentBase)

void COrientedCircleEditorComp::OnGuiRetranslate()
{
	BaseClass::OnGuiRetranslate();

	m_reversePolarityAction.setText(QCoreApplication::translate("iqt2d", "Reverse orientation"));
}


// protected slots

void COrientedCircleEditorComp::OnParamsChanged(double /*value*/)
{
	DoUpdateModel();
}


void COrientedCircleEditorComp::OnActionTriggered(QAction* actionPtr)
{
	if (actionPtr == &m_reversePolarityAction){
		i2d::COrientedCircle* circlePtr = dynamic_cast<i2d::COrientedCircle*>(BaseClass::GetObservedModel());
		if (circlePtr){
			circlePtr->SetOrientedOutside(!circlePtr->IsOrientedOutside());
		}

		return;
	}

	BaseClass::OnActionTriggered(actionPtr);
}


} // namespace iqt2d


