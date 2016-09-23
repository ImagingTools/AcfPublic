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


#include <iqt2d/CArcParamsGuiComp.h>


// ACF includes
#include <istd/CChangeGroup.h>


namespace iqt2d
{


// public methods

// reimplemented (imod::IModelEditor)

void CArcParamsGuiComp::UpdateModel() const
{
	Q_ASSERT(IsGuiCreated());

	i2d::CArc* objectPtr = GetObservedObject();
	Q_ASSERT(objectPtr != NULL);

	istd::CChangeGroup changeGroup(objectPtr);
	Q_UNUSED(changeGroup);

	objectPtr->SetPosition(i2d::CVector2d(XSpin->value(), YSpin->value()));
	objectPtr->SetRadius(RadiusSpin->value());
	objectPtr->SetStartAngle(StartAngleSpin->value());
	objectPtr->SetEndAngle(EndAngleSpin->value());
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CArcParamsGuiComp::UpdateGui(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	Q_ASSERT(IsGuiCreated());

	i2d::CArc* objectPtr = GetObservedObject();
	if (objectPtr != NULL){
		const i2d::CVector2d& center = objectPtr->GetCenter();

		XSpin->setValue(center.GetX());
		YSpin->setValue(center.GetY());

		RadiusSpin->setValue(objectPtr->GetRadius());

		StartAngleSpin->setValue(objectPtr->GetStartAngle());

		EndAngleSpin->setValue(objectPtr->GetEndAngle());

		UpdateAllViews();
	}
}


// reimplemented (iqtgui::CGuiComponentBase)

void CArcParamsGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	QObject::connect(XSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::connect(YSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::connect(RadiusSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::connect(StartAngleSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::connect(EndAngleSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
}


void CArcParamsGuiComp::OnGuiDestroyed()
{
	QObject::disconnect(XSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::disconnect(YSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::disconnect(RadiusSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::disconnect(StartAngleSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::disconnect(EndAngleSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));

	BaseClass::OnGuiDestroyed();
}


void CArcParamsGuiComp::OnGuiRetranslate()
{
	BaseClass::OnGuiRetranslate();

	QString unitName = GetUnitName();

	if (!unitName.isEmpty()){
		PositionUnitLabel->setVisible(true);
		RadiusUnitLabel->setText(unitName);
	}
	else{
		PositionUnitLabel->setVisible(false);
		RadiusUnitLabel->setVisible(false);
	}
}


// protected slots

void CArcParamsGuiComp::OnParamsChanged(double /*value*/)
{
	DoUpdateModel();
}


} // namespace iqt2d


