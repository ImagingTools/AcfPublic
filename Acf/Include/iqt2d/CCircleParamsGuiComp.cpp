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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqt2d/CCircleParamsGuiComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"

#include "iqt/CSignalBlocker.h"


namespace iqt2d
{


// public methods

// reimplemented (imod::IModelEditor)

void CCircleParamsGuiComp::UpdateModel() const
{
	I_ASSERT(IsGuiCreated());

	i2d::CCircle* objectPtr = GetObjectPtr();
	I_ASSERT(objectPtr != NULL);

	istd::CChangeNotifier notifier(NULL);

	i2d::CVector2d postion(XSpin->value(), YSpin->value());
	if (objectPtr->GetCenter() != postion){
		notifier.SetPtr(objectPtr);
		objectPtr->SetPosition(postion);
	}

	double radius = RadiusSpin->value();
	if (objectPtr->GetRadius() != radius){
		notifier.SetPtr(objectPtr);
		objectPtr->SetRadius(radius);
	}
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CCircleParamsGuiComp::OnGuiModelAttached()
{
	BaseClass::OnGuiModelAttached();

	QObject::connect(XSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::connect(YSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::connect(RadiusSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));

	if (m_unitNameAttrPtr.IsValid()){
		PositionUnitLabel->setVisible(true);
		RadiusUnitLabel->setText(iqt::GetQString(*m_unitNameAttrPtr));
	}
	else{
		PositionUnitLabel->setVisible(false);
		RadiusUnitLabel->setVisible(false);
	}
}


void CCircleParamsGuiComp::OnGuiModelDetached()
{
	QObject::disconnect(XSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::disconnect(YSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::disconnect(RadiusSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));

	BaseClass::OnGuiModelDetached();
}


void CCircleParamsGuiComp::UpdateGui(int /*updateFlags*/)
{
	I_ASSERT(IsGuiCreated());

	i2d::CCircle* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		const i2d::CVector2d& center = objectPtr->GetCenter();

		XSpin->setValue(center.GetX());
		YSpin->setValue(center.GetY());

		RadiusSpin->setValue(objectPtr->GetRadius());
	}
}


// protected slots

void CCircleParamsGuiComp::OnParamsChanged(double /*value*/)
{
	if (!IsUpdateBlocked()){
		UpdateBlocker updateBlocker(this);

		UpdateModel();
	}
}


} // namespace iqt2d


