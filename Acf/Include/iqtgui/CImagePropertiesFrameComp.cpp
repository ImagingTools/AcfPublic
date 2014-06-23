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


#include "iqtgui/CImagePropertiesFrameComp.h"


// ACF includes
#include "i2d/ICalibration2d.h"
#include "i2d/ICalibrationProvider.h"
#include "i2d/CAffine2d.h"


namespace iqtgui
{


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CImagePropertiesFrameComp::UpdateGui(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	Q_ASSERT(IsGuiCreated());

	iimg::IBitmap* bitmapPtr = GetObjectPtr();
	if (bitmapPtr != NULL && IsGuiCreated()){
		SizeLabel->setText(QString("%1x%2").arg(bitmapPtr->GetImageSize().GetX()).arg(bitmapPtr->GetImageSize().GetY()));
		DepthLabel->setText(QString("%1 bits").arg(bitmapPtr->GetComponentBitsCount() * bitmapPtr->GetComponentsCount()));

		const i2d::ICalibration2d* calibrationPtr = NULL;
		i2d::ICalibrationProvider* calibrationProviderPtr = dynamic_cast<i2d::ICalibrationProvider*>(bitmapPtr);
		if (calibrationProviderPtr != NULL){
			calibrationPtr = calibrationProviderPtr->GetCalibration();
		}

		if (calibrationPtr != NULL){
			i2d::CAffine2d transform;
			
			if (calibrationPtr->GetLocalTransform(i2d::CVector2d(0,0), transform)){
				double scale = transform.GetDeformMatrix().GetApproxScale();
				ResolutionLabel->setText(QString(tr("%1 px/mm")).arg(scale, 1, 'f', 1));
			}
		}
		else{
			ResolutionLabel->setVisible(false);
		}
	}
}


void CImagePropertiesFrameComp::OnGuiModelDetached()
{
	SizeLabel->clear();
	DepthLabel->clear();
	ResolutionLabel->clear();

	BaseClass::OnGuiModelDetached();
}

} // namespace iqtgui


