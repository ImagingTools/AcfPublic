/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include "iqtmeas/CDataSequenceSupplierResultsViewComp.h"


namespace iqtmeas
{


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CDataSequenceSupplierResultsViewComp::UpdateGui(const istd::IChangeable::ChangeSet& changeSet)
{
	if (changeSet.Contains(iinsp::ISupplier::CF_SUPPLIER_RESULTS)){
		imeas::IDataSequenceProvider* providerPtr = dynamic_cast<imeas::IDataSequenceProvider*>(GetObservedModel());
		if (providerPtr != NULL){
			const imod::IModel* productModelPtr = dynamic_cast<const imod::IModel*>(providerPtr->GetDataSequence());
			if ((productModelPtr != NULL) && m_resultsObserverCompPtr.IsValid()){
				if (!productModelPtr->IsAttached(m_resultsObserverCompPtr.GetPtr())){
					(const_cast<imod::IModel*>(productModelPtr))->AttachObserver(m_resultsObserverCompPtr.GetPtr());
				}
			}
		}
	}
}


// reimplemented (icomp::CComponentBase)

void CDataSequenceSupplierResultsViewComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	QWidget* widgetPtr = GetWidget();

	QVBoxLayout* layoutPtr = new QVBoxLayout(widgetPtr);
	layoutPtr->setMargin(0);

	if (m_resultsGuiCompPtr.IsValid() && m_resultsObserverCompPtr.IsValid()){
		m_resultsGuiCompPtr->CreateGui(widgetPtr);
	}
}


void CDataSequenceSupplierResultsViewComp::OnGuiDestroyed()
{
	if (m_resultsGuiCompPtr.IsValid()){
		m_resultsGuiCompPtr->DestroyGui();
	}

	BaseClass::OnGuiDestroyed();
}


} // namespace iqtmeas


