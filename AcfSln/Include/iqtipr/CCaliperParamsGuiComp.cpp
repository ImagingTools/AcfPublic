/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#include "iqtipr/CCaliperParamsGuiComp.h"


// ACF includes
#include "istd/CChangeGroup.h"


namespace iqtipr
{


// reimplemented (imod::IModelEditor)

void CCaliperParamsGuiComp::UpdateModel() const
{
	Q_ASSERT(IsGuiCreated());

	iipr::ICaliperParams* objectPtr = GetObjectPtr();
	Q_ASSERT(objectPtr != NULL);

	istd::CChangeGroup changeGroup(objectPtr);
	Q_UNUSED(changeGroup);

	double threshold = ThresholdSB->value() * 0.01;
	if (qAbs(objectPtr->GetWeightThreshold() - threshold) > I_BIG_EPSILON){
		objectPtr->SetWeightThreshold(threshold);
	}

	int edgePolarity = EdgePolarityCB->currentIndex();
	if (objectPtr->GetPolarityMode() != edgePolarity){
		objectPtr->SetPolarityMode(edgePolarity);
	}

	int direction = DirectionCB->currentIndex();
	if (objectPtr->GetDirectionMode() != direction){
		objectPtr->SetDirectionMode(direction);
	}
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CCaliperParamsGuiComp::UpdateGui(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	Q_ASSERT(IsGuiCreated());

	iipr::ICaliperParams* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		double threshold = objectPtr->GetWeightThreshold();
		ThresholdSB->setValue(int(threshold * 100 + 0.5));

		int edgePolarity = objectPtr->GetPolarityMode();
		EdgePolarityCB->setCurrentIndex(edgePolarity);

		int direction = objectPtr->GetDirectionMode();
		DirectionCB->setCurrentIndex(direction);
	}
}


// reimplemented (iqtgui::CGuiComponentBase)

void CCaliperParamsGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	EdgePolarityCB->setHidden(*m_hideEdgePolarityAttrPtr);
	EdgePolarityLabel->setHidden(*m_hideEdgePolarityAttrPtr);

	DirectionCB->setHidden(*m_hideDirectionAttrPtr);
	DirectionLabel->setHidden(*m_hideDirectionAttrPtr);
}


// protected slots

void CCaliperParamsGuiComp::on_ThresholdSB_valueChanged(int /*value*/)
{
	DoUpdateModel();
}


void CCaliperParamsGuiComp::on_EdgePolarityCB_currentIndexChanged(int /*index*/)
{
	DoUpdateModel();
}


void CCaliperParamsGuiComp::on_DirectionCB_currentIndexChanged(int /*index*/)
{
	DoUpdateModel();
}


} // namespace iqtipr


