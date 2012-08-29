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


#include "iqtsig/CSamplingParamsGuiComp.h"


#include "istd/TChangeNotifier.h"

#include "isig/ISamplingConstraints.h"


namespace iqtsig
{


// reimplemented (iqtgui::TGuiObserverWrap)

void CSamplingParamsGuiComp::OnGuiModelAttached()
{
	I_ASSERT(IsGuiCreated());
	isig::ISamplingParams* objectPtr = GetObjectPtr();
	I_ASSERT(objectPtr != NULL);

	istd::CRange range(0, 0.1);

	const isig::ISamplingConstraints* constraintsPtr = objectPtr->GetSamplingConstraints();
	if (constraintsPtr != NULL){
		range = constraintsPtr->GetIntervalRange();
	}

	IntervalSB->setMinimum(range.GetMinValue() * 1000);
	IntervalSB->setMaximum(range.GetMaxValue() * 1000);
}


void CSamplingParamsGuiComp::UpdateGui(int /*updateFlags*/)
{
	I_ASSERT(IsGuiCreated());

	isig::ISamplingParams* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		IntervalSB->setValue(objectPtr->GetInterval() * 1000);
		ModeCB->setCurrentIndex(objectPtr->GetSamplingMode());
	}
}


// protected slots

void CSamplingParamsGuiComp::on_IntervalSB_valueChanged(double value)
{
	isig::ISamplingParams* objectPtr = GetObjectPtr();
	if (IsGuiCreated() && (objectPtr != NULL)){
		double interval = value * 0.001;
		if (qAbs(interval - objectPtr->GetInterval()) > I_EPSILON){
			istd::CChangeNotifier notifier(objectPtr);

			objectPtr->SetInterval(interval);
		}
	}
}


void CSamplingParamsGuiComp::on_ModeCB_currentIndexChanged(int index)
{
	isig::ISamplingParams* objectPtr = GetObjectPtr();
	if (!IsGuiCreated() || (objectPtr == NULL)){
		return;
	}

	if (index != objectPtr->GetSamplingMode()){
		const isig::ISamplingConstraints* constraintsPtr = objectPtr->GetSamplingConstraints();
		if (constraintsPtr != NULL){
			if (!constraintsPtr->IsSamplingModeSupported(index)){
				return;
			}
		}

		istd::CChangeNotifier notifier(objectPtr);

		objectPtr->SetSamplingMode(index);
	}
}


} // namespace iqtsig


