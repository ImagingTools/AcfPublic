/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#include "iqt2d/CAnnulusSegmentParamsGuiComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"


namespace iqt2d
{


// public methods

// reimplemented (imod::IModelEditor)

void CAnnulusSegmentParamsGuiComp::UpdateModel() const
{
	Q_ASSERT(IsGuiCreated());

	i2d::CAnnulusSegment* objectPtr = GetObjectPtr();
	Q_ASSERT(objectPtr != NULL);

	istd::CChangeNotifier notifier(NULL);

	i2d::CVector2d postion(XSpin->value(), YSpin->value());
	if (objectPtr->GetCenter() != postion){
		notifier.SetPtr(objectPtr);
		objectPtr->SetPosition(postion);
	}

	double innerRadius = InnerRadiusSpin->value();
	if (objectPtr->GetInnerRadius() != innerRadius){
		notifier.SetPtr(objectPtr);
		objectPtr->SetInnerRadius(innerRadius);
	}

	double outerRadius = OuterRadiusSpin->value();
	if (objectPtr->GetOuterRadius() != outerRadius){
		notifier.SetPtr(objectPtr);
		objectPtr->SetOuterRadius(outerRadius);
	}

	double beginAngle = imath::GetRadianFromDegree(BeginAngleSB->value());
	double prec = qPow(0.1, BeginAngleSB->decimals() + 1);
	if (beginAngle - objectPtr->GetBeginAngle() > prec){
		notifier.SetPtr(objectPtr);
		objectPtr->SetBeginAngle(beginAngle);
	}

	double endAngle = imath::GetRadianFromDegree(EndAngleSB->value());
	prec = qPow(0.1, EndAngleSB->decimals() + 1);
	if (endAngle - objectPtr->GetEndAngle() > prec){
		notifier.SetPtr(objectPtr);
		objectPtr->SetEndAngle(endAngle);
	}
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CAnnulusSegmentParamsGuiComp::UpdateGui(int /*updateFlags*/)
{
	Q_ASSERT(IsGuiCreated());

	i2d::CAnnulusSegment* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		const i2d::CVector2d& center = objectPtr->GetCenter();
		XSpin->setValue(center.GetX());
		YSpin->setValue(center.GetY());

		InnerRadiusSpin->setValue(objectPtr->GetInnerRadius());
		OuterRadiusSpin->setValue(objectPtr->GetOuterRadius());

		BeginAngleSB->setValue(imath::GetDegreeFromRadian(objectPtr->GetBeginAngle()));
		EndAngleSB->setValue(imath::GetDegreeFromRadian(objectPtr->GetEndAngle()));

		UpdateAllViews();
	}
}


// reimplemented (iqtgui::CGuiComponentBase)

void CAnnulusSegmentParamsGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	QObject::connect(XSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::connect(YSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::connect(InnerRadiusSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::connect(OuterRadiusSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::connect(BeginAngleSB, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::connect(EndAngleSB, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
}


void CAnnulusSegmentParamsGuiComp::OnGuiDestroyed()
{
	QObject::disconnect(XSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::disconnect(YSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::disconnect(InnerRadiusSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::disconnect(OuterRadiusSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::disconnect(BeginAngleSB, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::disconnect(EndAngleSB, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));

	BaseClass::OnGuiDestroyed();
}


void CAnnulusSegmentParamsGuiComp::OnGuiRetranslate()
{
	BaseClass::OnGuiRetranslate();

	QString unitName = GetUnitName();

	if (!unitName.isEmpty()){
		PositionUnitLabel->setText(unitName);
		RadiusUnitLabel->setText(unitName);
		PositionUnitLabel->setVisible(true);
		RadiusUnitLabel->setVisible(true);
	}
	else{
		PositionUnitLabel->setVisible(false);
		RadiusUnitLabel->setVisible(false);
	}
}


// protected slots

void CAnnulusSegmentParamsGuiComp::OnParamsChanged(double /*value*/)
{
	DoUpdateModel();
}


} // namespace iqt2d


