/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#include <iqt2d/CRectangleParamsGuiComp.h>


// ACF includes
#include <istd/CChangeGroup.h>
#include <iqt/CSignalBlocker.h>


namespace iqt2d
{


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CRectangleParamsGuiComp::OnGuiModelAttached()
{
	BaseClass::OnGuiModelAttached();

	QObject::connect(LeftSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::connect(RightSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::connect(BottomSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::connect(TopSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
}


void CRectangleParamsGuiComp::OnGuiModelDetached()
{
	QObject::disconnect(LeftSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::disconnect(RightSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::disconnect(BottomSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));
	QObject::disconnect(TopSpin, SIGNAL(valueChanged(double)), this, SLOT(OnParamsChanged(double)));

	BaseClass::OnGuiModelDetached();
}


void CRectangleParamsGuiComp::UpdateModel() const
{
	Q_ASSERT(IsGuiCreated());

	i2d::CRectangle* objectPtr = GetObservedObject();
	Q_ASSERT(objectPtr != NULL);

	istd::CChangeGroup changeGroup(objectPtr);
	Q_UNUSED(changeGroup);

	double left = LeftSpin->value();
	double right = RightSpin->value();
	Q_ASSERT(left <= right);
	objectPtr->SetLeft(left);
	objectPtr->SetRight(right);

	double top = TopSpin->value();
	double bottom = BottomSpin->value();
	Q_ASSERT(top <= bottom);
	objectPtr->SetTop(top);
	objectPtr->SetBottom(bottom);
}


void CRectangleParamsGuiComp::UpdateGui(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	Q_ASSERT(IsGuiCreated());

	i2d::CRectangle* objectPtr = GetObservedObject();
	if (objectPtr != NULL){
		iqt::CSignalBlocker block(GetWidget(), true);

		double left = objectPtr->GetLeft();
		double right = objectPtr->GetRight();
		if (left > right) {
			std::swap(left, right);
		}
		LeftSpin->setMaximum(right);
		RightSpin->setMinimum(left);
		LeftSpin->setValue(left);
		RightSpin->setValue(right);

		double top = objectPtr->GetTop();
		double bottom = objectPtr->GetBottom();
		if (top > bottom) {
			std::swap(top, bottom);
		}
		TopSpin->setMaximum(bottom);
		BottomSpin->setMinimum(top);
		TopSpin->setValue(top);
		BottomSpin->setValue(bottom);

		UpdateAllViews();
	}
}


// reimplemented (iqtgui::CGuiComponentBase)

void CRectangleParamsGuiComp::OnGuiRetranslate()
{
	BaseClass::OnGuiRetranslate();

	QString unitName = GetUnitName();

	if (!unitName.isEmpty()){
		PositionUnitLabel->setText(unitName);
		PositionUnit2Label->setText(unitName);
		PositionUnitLabel->setVisible(true);
		PositionUnit2Label->setVisible(true);
	}
	else{
		PositionUnitLabel->setVisible(false);
		PositionUnit2Label->setVisible(false);
	}
}


// protected slots

void CRectangleParamsGuiComp::OnParamsChanged(double /*value*/)
{
	//Left <= Right
	LeftSpin->setMaximum(RightSpin->value());
	RightSpin->setMinimum(LeftSpin->value());

	//Top <= Bottom
	TopSpin->setMaximum(BottomSpin->value());
	BottomSpin->setMinimum(TopSpin->value());

	DoUpdateModel();
}


} // namespace iqt2d


