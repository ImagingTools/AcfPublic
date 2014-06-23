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


#include "iqt2d/COrientedCircleEditorComp.h"

// ACF includes
#include "istd/CChangeGroup.h"


namespace iqt2d
{


// reimplemented (imod::IModelEditor)

void COrientedCircleEditorComp::UpdateModel() const
{
	Q_ASSERT(IsGuiCreated());

	i2d::COrientedCircle* objectPtr = GetObjectPtr();
	Q_ASSERT(objectPtr != NULL);

	istd::CChangeGroup changeGroup(objectPtr);

	i2d::CVector2d position(XSpin->value(), YSpin->value());

	objectPtr->SetPosition(position);

	double radius = RadiusSpin->value();
	objectPtr->SetRadius(radius);

	objectPtr->SetOrientedOutside(AxisOrientationCheckBox->checkState() == Qt::Checked);
}


// protected methods

void COrientedCircleEditorComp::UpdateGui(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	Q_ASSERT(IsGuiCreated());

	i2d::COrientedCircle* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		const i2d::CVector2d& center = objectPtr->GetCenter();

		XSpin->setValue(center.GetX());
		YSpin->setValue(center.GetY());

		RadiusSpin->setValue(objectPtr->GetRadius());

		AxisOrientationCheckBox->setCheckState(objectPtr->IsOrientedOutside() ? Qt::Checked : Qt::Unchecked);

		UpdateAllViews();
	}
}


// reimplemented (iqtgui::TGuiObserverWrap)

void COrientedCircleEditorComp::OnParamsChanged(double /*value*/)
{
	DoUpdateModel();
}


// reimplemented (iqtgui::CGuiComponentBase)

void COrientedCircleEditorComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	QObject::connect(XSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::connect(YSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::connect(RadiusSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
}


void COrientedCircleEditorComp::OnGuiDestroyed()
{
	QObject::disconnect(XSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::disconnect(YSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::disconnect(RadiusSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));

	BaseClass::OnGuiDestroyed();
}


void COrientedCircleEditorComp::OnGuiRetranslate()
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


void COrientedCircleEditorComp::on_AxisOrientationCheckBox_stateChanged(int /*state*/)
{
	DoUpdateModel();
}


} // namespace iqt2d


