/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "CEdgeLinesSupplierGuiComp.h"


// Qt includes
#include <QtGui/QMessageBox>

// ACF includes
#include "imath/CVarVector.h"
#include "iproc/IElapsedTimeProvider.h"

// ACF-Solutions includes
#include "iedge/IEdgeLinesProvider.h"
#include "iedge/CEdgeLine.h"

#include "iedgegui/CEdgeLineContainerShape.h"


namespace iedgegui
{


// protected slots

void CEdgeLinesSupplierGuiComp::on_TestButton_clicked()
{
	DoTest();
}


void CEdgeLinesSupplierGuiComp::on_LoadParamsButton_clicked()
{
	LoadParams();
}


void CEdgeLinesSupplierGuiComp::on_SaveParamsButton_clicked()
{
	SaveParams();
}


// protected methods

// reimplemented (iqtinsp::TSupplierGuiCompBase)

QWidget* CEdgeLinesSupplierGuiComp::GetParamsWidget() const
{
	I_ASSERT(IsGuiCreated());

	return ParamsFrame;
}


void CEdgeLinesSupplierGuiComp::OnSupplierParamsChanged()
{
	if (IsGuiCreated() && AutoUpdateButton->isChecked()){
		DoTest();
	}
}


// reimplemented (iqt2d::TViewExtenderCompBase)

void CEdgeLinesSupplierGuiComp::CreateShapes(int /*sceneId*/, Shapes& result)
{
	iedgegui::CEdgeLineContainerShape* shapePtr = new iedgegui::CEdgeLineContainerShape(); 

	if (shapePtr != NULL){
		shapePtr->AssignToLayer(iview::IViewLayer::LT_INACTIVE);

		m_foundModel.AttachObserver(shapePtr);

		result.PushBack(shapePtr);
	}	
}


// reimplemented (iqtgui::TGuiObserverWrap)

void CEdgeLinesSupplierGuiComp::OnGuiModelAttached()
{
	BaseClass::OnGuiModelAttached();

	ParamsGB->setVisible(AreParamsEditable() || IsLoadParamsSupported());
	LoadParamsButton->setVisible(IsLoadParamsSupported());
	SaveParamsButton->setVisible(IsSaveParamsSupported());
}


void CEdgeLinesSupplierGuiComp::UpdateGui(int updateFlags)
{
	BaseClass::UpdateGui(updateFlags);

	I_ASSERT(IsGuiCreated());

	iproc::ISupplier* supplierPtr = GetObjectPtr();
	if (supplierPtr != NULL){
		int workStatus = supplierPtr->GetWorkStatus();
		if (workStatus == iproc::ISupplier::WS_OK){
			iedge::IEdgeLinesProvider* providerPtr = dynamic_cast<iedge::IEdgeLinesProvider*>(supplierPtr);
			if (providerPtr != NULL ){
				const iedge::CEdgeLine::Container* resultContainerPtr = providerPtr->GetEdgesContainer();	

				if ((resultContainerPtr == NULL) || ! m_foundModel.CopyFrom(*resultContainerPtr)){
					m_foundModel.Reset();
				}
			}
		}
	}

	iproc::IElapsedTimeProvider* processingTimeProviderPtr = dynamic_cast<iproc::IElapsedTimeProvider*>(supplierPtr);
	if (processingTimeProviderPtr != NULL){
		ProcessingTimeLabel->setText(QString(tr("Edges found in %1 ms").arg(processingTimeProviderPtr->GetElapsedTime() * 1000, 1, 'f', 1)));
	}
		
	UpdateAllViews();
}


// reimplemented (iqtgui::IGuiObject)

void CEdgeLinesSupplierGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	if (m_intermediateResultsGuiCompPtr.IsValid()){
		m_intermediateResultsGuiCompPtr->CreateGui(IntResultsFrame);

		IntResultsFrame->setVisible(true);
	}
	else{
		IntResultsFrame->setVisible(false);
	}
}


void CEdgeLinesSupplierGuiComp::OnGuiDestroyed()
{
	if (m_intermediateResultsGuiCompPtr.IsValid()){
		m_intermediateResultsGuiCompPtr->DestroyGui();
	}
	
	BaseClass::OnGuiDestroyed();
}


}//Namespace iedgegui





