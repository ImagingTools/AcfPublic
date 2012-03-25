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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqt2d/CRectangleParamsGuiComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"

#include "iqt/CSignalBlocker.h"


namespace iqt2d
{


// public methods

// reimplemented (imod::IModelEditor)

void CRectangleParamsGuiComp::UpdateModel() const
{
	I_ASSERT(IsGuiCreated());

	i2d::CRectangle* objectPtr = GetObjectPtr();
	I_ASSERT(objectPtr != NULL);

	istd::CChangeNotifier notifier(NULL);

	if (objectPtr->GetLeft() != LeftSpin->value()){
		notifier.SetPtr(objectPtr);
		objectPtr->SetLeft(LeftSpin->value());
	}

	if (objectPtr->GetRight() != RightSpin->value()){
		notifier.SetPtr(objectPtr);
		objectPtr->SetRight(RightSpin->value());
	}

	if (objectPtr->GetTop() != TopSpin->value()){
		notifier.SetPtr(objectPtr);
		objectPtr->SetTop(TopSpin->value());
	}

	if (objectPtr->GetBottom() != BottomSpin->value()){
		notifier.SetPtr(objectPtr);
		objectPtr->SetBottom(BottomSpin->value());
	}
}


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


void CRectangleParamsGuiComp::UpdateGui(int /*updateFlags*/)
{
	I_ASSERT(IsGuiCreated());

	i2d::CRectangle* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		iqt::CSignalBlocker block(LeftSpin);
		LeftSpin->setValue(objectPtr->GetLeft());

		iqt::CSignalBlocker block2(RightSpin);
		RightSpin->setValue(objectPtr->GetRight());

		iqt::CSignalBlocker block3(BottomSpin);
		BottomSpin->setValue(objectPtr->GetBottom());

		iqt::CSignalBlocker block4(TopSpin);
		TopSpin->setValue(objectPtr->GetTop());

		UpdateAllViews();
	}
}


// protected slots

void CRectangleParamsGuiComp::OnParamsChanged(double /*value*/)
{
	if (!IsUpdateBlocked()){
		UpdateBlocker updateBlocker(this);

		UpdateModel();

		UpdateShapeView();
	}
}


} // namespace iqt2d


