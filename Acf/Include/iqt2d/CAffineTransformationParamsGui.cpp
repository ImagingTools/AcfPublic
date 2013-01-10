/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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


#include "iqt2d/CAffineTransformationParamsGui.h"

namespace iqt2d
{

	
// public methods

// reimplemented (imod::IModelEditor)

void CAffineTransformationParamsGui::UpdateModel() const
{
	Q_ASSERT(IsGuiCreated());

	i2d::CAffineTransformation2d* objectPtr = GetObjectPtr();
	Q_ASSERT(objectPtr != NULL);

	i2d::CVector2d translation(TranslationSpinX->value(), TranslationSpinY->value());

	istd::CChangeNotifier notifier(NULL);

	if(objectPtr->GetTransformation().GetTranslation() != translation){
		notifier.SetPtr(objectPtr);
		objectPtr->Reset(translation);		
	}
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CAffineTransformationParamsGui::OnGuiModelAttached()
{
	BaseClass::OnGuiModelAttached();

	connect(TranslationSpinX, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	connect(TranslationSpinY, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));	
}


void CAffineTransformationParamsGui::OnGuiModelDetached()
{
	disconnect(TranslationSpinX, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	disconnect(TranslationSpinY, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));	

	BaseClass::OnGuiModelDetached();
}


void CAffineTransformationParamsGui::UpdateGui(int /*updateFlags*/)
{
	I_ASSERT(IsGuiCreated());

	i2d::CAffineTransformation2d* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		i2d::CVector2d translation = objectPtr->GetTransformation().GetTranslation();

		TranslationSpinX->setValue(translation.GetX());
		TranslationSpinY->setValue(translation.GetY());		

		UpdateAllViews();
	}
}


// protected slots

void CAffineTransformationParamsGui::OnParamsChanged(double /*value*/)
{
	DoUpdateModel();
}

}
