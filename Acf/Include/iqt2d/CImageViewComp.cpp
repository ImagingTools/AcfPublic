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


#include "iqt2d/CImageViewComp.h"


// ACF includes
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsSceneWheelEvent>
#include <QKeyEvent>
#include <QMenu>


namespace iqt2d
{


// public methods

// reimplemented (imod::IObserver)

bool CImageViewComp::OnDetached(imod::IModel* modelPtr)
{
	if (BaseClass::OnDetached(modelPtr)){
		QGraphicsScene* scenePtr = GetScene();
		if (scenePtr != NULL){
			scenePtr->update();
		}

		return true;
	}

	return false;
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CImageViewComp::UpdateGui(int /*updateFlags*/)
{
	I_ASSERT(IsGuiCreated());

	istd::CIndex2d imageSize = GetSize();
	if (imageSize == istd::CIndex2d::GetZero() || imageSize == istd::CIndex2d::GetInvalid()){
		QGraphicsScene* scenePtr = GetScene();
		if (scenePtr != NULL){
			scenePtr->update();
		}

		return;
	}

	QGraphicsScene* scenePtr = GetScene();
	if (scenePtr != NULL){
		scenePtr->setSceneRect(boundingRect());

		if (m_fitToViewOnChangeAttrPtr.IsValid() && *m_fitToViewOnChangeAttrPtr){
			OnFitToView();
		}

		SetFittedScale(GetFitMode());
	}
}


// reimplemented (iqtgui::CGuiComponentBase)

void CImageViewComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	SetFrameVisible(*m_isFrameVisibleAttrPtr);
	SetPositionMode(*m_imagePositionModeAttrPtr);

	QGraphicsScene* scenePtr = GetScene();
	if (scenePtr != NULL){
		scenePtr->addItem(this);
	}
}


void CImageViewComp::OnGuiDestroyed()
{
	QGraphicsScene* scenePtr = GetScene();
	if (scenePtr != NULL){
		scenePtr->removeItem(this);
	}

	BaseClass::OnGuiDestroyed();
}


} // namespace iqt2d

