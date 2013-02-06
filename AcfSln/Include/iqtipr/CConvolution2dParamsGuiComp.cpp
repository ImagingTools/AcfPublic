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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iqtipr/CConvolution2dParamsGuiComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"


namespace iqtipr
{


// reimplemented (imod::IModelEditor)

void CConvolution2dParamsGuiComp::UpdateModel() const
{
	Q_ASSERT(IsGuiCreated());

	UpdateKernelSize();
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CConvolution2dParamsGuiComp::UpdateGui(int /*updateFlags*/)
{
	Q_ASSERT(IsGuiCreated());

	iipr::IConvolutionKernel2d* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		UpdateTableSize();

		int rowCount = KernelTable->rowCount();
		int columnCount = KernelTable->columnCount();

		for (int y = 0; y < rowCount; y++){		
			for (int x = 0; x < columnCount; x++){
				double kernelElement = objectPtr->GetKernelElement(istd::CIndex2d(x, y));

				QTableWidgetItem* itemPtr = new QTableWidgetItem(QString::number(kernelElement));
				KernelTable->setItem(y, x, itemPtr); 
			}
		}
	}
}


// reimplemented (iqtgui::CGuiComponentBase)

void CConvolution2dParamsGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	KernelTable->verticalHeader()->setResizeMode(QHeaderView::Stretch);
	KernelTable->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
}


// protected slots

void CConvolution2dParamsGuiComp::on_KernelWidthSpin_valueChanged(int /*value*/)
{
	DoUpdateModel();

	UpdateGui();
}


void CConvolution2dParamsGuiComp::on_KernelHeightSpin_valueChanged(int /*value*/)
{
	DoUpdateModel();

	UpdateGui();
}


void CConvolution2dParamsGuiComp::on_KernelTable_itemChanged(QTableWidgetItem* item)
{
	if (!IsUpdateBlocked()){
		UpdateBlocker updateBlocker(this);

		int x = item->column();
		int y = item->row();

		iipr::IConvolutionKernel2d* objectPtr = GetObjectPtr();
		Q_ASSERT(objectPtr != NULL);

		if (objectPtr != NULL){
			bool isValid = false;
			double value = item->text().toDouble(&isValid);

			if (isValid){
				objectPtr->SetKernelElement(istd::CIndex2d(x, y), value);
			}
		}
	}
}



// private methods

void CConvolution2dParamsGuiComp::UpdateTableSize()
{
	Q_ASSERT(IsGuiCreated());

	int kernelWidth = KernelTable->columnCount();
	int kernelHeight = KernelTable->rowCount();
		
	iipr::IConvolutionKernel2d* objectPtr = GetObjectPtr();
	if (objectPtr != NULL && objectPtr->GetKernelSize() != istd::CIndex2d(kernelWidth, kernelHeight)){
		KernelTable->setRowCount(objectPtr->GetKernelSize().GetY());
		KernelTable->setColumnCount(objectPtr->GetKernelSize().GetX());
	}
	
	int rowCount = KernelTable->rowCount();
	int columnCount = KernelTable->columnCount();

	KernelWidthSpin->setValue(columnCount);
	KernelHeightSpin->setValue(rowCount);
}


void CConvolution2dParamsGuiComp::UpdateKernelSize() const
{
	iipr::IConvolutionKernel2d* objectPtr = GetObjectPtr();
	Q_ASSERT(objectPtr != NULL);

	int newKernelWidth = KernelWidthSpin->value();
	int newKernelHeight = KernelHeightSpin->value();

	if (objectPtr->GetKernelSize() != istd::CIndex2d(newKernelWidth, newKernelHeight)){
		objectPtr->SetKernelSize(istd::CIndex2d(newKernelWidth, newKernelHeight));
	}
}


} // namespace iqtipr


