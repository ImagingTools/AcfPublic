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


#include "iqt2d/CPolylineParamsGuiComp.h"


namespace iqt2d
{


CPolylineParamsGuiComp::CPolylineParamsGuiComp()
:	m_openCloseAction(QIcon(":/Icons/OpenCloseLine"), "", this)
{
}


// reimplemented (imod::IModelEditor)

void CPolylineParamsGuiComp::UpdateModel() const
{
	Q_ASSERT(BaseClass::IsGuiCreated());
}


// protected slots

void CPolylineParamsGuiComp::OnParamsChanged()
{
	DoUpdateModel();
}


void CPolylineParamsGuiComp::on_InsertButton_clicked()
{
	OnInsertNode();
}


void CPolylineParamsGuiComp::on_RemoveButton_clicked()
{
	OnRemoveNode();
}


void CPolylineParamsGuiComp::on_CopyButton_clicked()
{
	OnCopyData();
}


void CPolylineParamsGuiComp::on_PasteButton_clicked()
{
	OnPasteData();
}


// reimplemented from TPolygonBasedParamsGuiComp

bool CPolylineParamsGuiComp::PopulateActions(CActionAdapter& host, imod::IModel* modelPtr)
{
	if (BaseClass::PopulateActions(host, modelPtr)){
		host.AddAction(m_openCloseAction);

		return true;
	}

	return false;
}


// reimplemented (iqt2d::TShapeParamsGuiCompBase)

iview::CInteractiveShapeBase* CPolylineParamsGuiComp::CreateShapeInstance() const
{
	iview::CPolylineShape* shapePtr = new iview::CPolylineShape();

	if (*m_showOrientationAttrPtr){
		shapePtr->SetOrientationVisible(true);
	}

	return shapePtr;
}


// reimplemented (iqtgui::CGuiComponentBase)

void CPolylineParamsGuiComp::OnGuiRetranslate()
{
	BaseClass::OnGuiRetranslate();

	m_openCloseAction.setText(QCoreApplication::translate("iqt2d", "Open/close line"));
}


// pseudo slots

void CPolylineParamsGuiComp::OnActionTriggered(QAction* actionPtr)
{
	if (actionPtr == &m_openCloseAction){
		i2d::CPolyline* polylinePtr = GetObjectPtr();
		if (polylinePtr){
			polylinePtr->SetClosed(!polylinePtr->IsClosed());
		}

		return;
	}

	BaseClass::OnActionTriggered(actionPtr);
}


} // namespace iqt2d
