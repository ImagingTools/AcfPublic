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


#include "iqt2d/CSceneControllerGuiComp.h"


// Qt includes
#include <QGraphicsView>


// ACF includes
#include "istd/TChangeNotifier.h"

#include "iqt2d/ISceneProvider.h"


namespace iqt2d
{


// public methods


// protected methods

// reimplemented (iqtgui::CGuiComponentBase)

void CSceneControllerGuiComp::OnGuiCreated()
{
	connect(ZoomInButton, SIGNAL(clicked()), this, SLOT(OnZoomIncrement()));
	connect(ZoomOutButton, SIGNAL(clicked()), this, SLOT(OnZoomDecrement()));
	connect(ResetViewButton, SIGNAL(clicked()), this, SLOT(OnResetView()));
	connect(RotateRightButton, SIGNAL(clicked()), this, SLOT(OnRotateRight()));
	connect(RotateLeftButton, SIGNAL(clicked()), this, SLOT(OnRotateLeft()));

	BaseClass::OnGuiCreated();
}


void CSceneControllerGuiComp::OnGuiDestroyed()
{
	BaseClass::OnGuiDestroyed();
}


// protected slots

void CSceneControllerGuiComp::OnZoomIncrement()
{
	I_ASSERT(m_sceneProviderCompPtr.IsValid());
	if (!m_sceneProviderCompPtr.IsValid()){
		return;
	}

	if (		m_sceneRestrictionsCompPtr.IsValid() && 
				m_sceneRestrictionsCompPtr->GetSceneRestrictionFlags() & i2d::ISceneController::SR_SCALE){
			return;
	}

	QGraphicsScene* scenePtr = m_sceneProviderCompPtr->GetScene();
	if (scenePtr != NULL){
		QGraphicsView* viewPtr = scenePtr->views().at(0);

		QMatrix sceneMatrix = viewPtr->matrix();
		double scaleFactor = pow((double)2, 0.5);
		sceneMatrix.scale(scaleFactor, scaleFactor);

		viewPtr->setMatrix(sceneMatrix);
	}
}


void CSceneControllerGuiComp::OnZoomDecrement()
{
	I_ASSERT(m_sceneProviderCompPtr.IsValid());
	if (!m_sceneProviderCompPtr.IsValid()){
		return;
	}

	if (		m_sceneRestrictionsCompPtr.IsValid() && 
				m_sceneRestrictionsCompPtr->GetSceneRestrictionFlags() & i2d::ISceneController::SR_SCALE){
			return;
	}

	QGraphicsScene* scenePtr = m_sceneProviderCompPtr->GetScene();
	if (scenePtr != NULL){
		QGraphicsView* viewPtr = scenePtr->views().at(0);

		QMatrix sceneMatrix = viewPtr->matrix();
		double scaleFactor = pow((double)2, -0.5);
		sceneMatrix.scale(scaleFactor, scaleFactor);

		viewPtr->setMatrix(sceneMatrix);
	}
}


void CSceneControllerGuiComp::OnResetView()
{
	I_ASSERT(m_sceneProviderCompPtr.IsValid());
	if (!m_sceneProviderCompPtr.IsValid()){
		return;
	}
	
	if (		m_sceneRestrictionsCompPtr.IsValid() && 
				m_sceneRestrictionsCompPtr->GetSceneRestrictionFlags() != i2d::ISceneController::SR_NONE){
			return;
	}

	QGraphicsScene* scenePtr = m_sceneProviderCompPtr->GetScene();
	if (scenePtr != NULL){
		QGraphicsView* viewPtr = scenePtr->views().at(0);
		viewPtr->resetMatrix();
	}
}


void CSceneControllerGuiComp::OnRotateRight()
{
	I_ASSERT(m_sceneProviderCompPtr.IsValid());
	if (!m_sceneProviderCompPtr.IsValid()){
		return;
	}

	if (		m_sceneRestrictionsCompPtr.IsValid() && 
				m_sceneRestrictionsCompPtr->GetSceneRestrictionFlags() & i2d::ISceneController::SR_ROTATE){
			return;
	}

	QGraphicsScene* scenePtr = m_sceneProviderCompPtr->GetScene();
	if (scenePtr != NULL){
		QGraphicsView* viewPtr = scenePtr->views().at(0);

		QMatrix sceneMatrix = viewPtr->matrix();
		sceneMatrix.rotate(2);

		viewPtr->setMatrix(sceneMatrix);
	}
}


void CSceneControllerGuiComp::OnRotateLeft()
{
	I_ASSERT(m_sceneProviderCompPtr.IsValid());
	if (!m_sceneProviderCompPtr.IsValid()){
		return;
	}

	if (		m_sceneRestrictionsCompPtr.IsValid() && 
				m_sceneRestrictionsCompPtr->GetSceneRestrictionFlags() & i2d::ISceneController::SR_ROTATE){
			return;
	}

	QGraphicsScene* scenePtr = m_sceneProviderCompPtr->GetScene();
	if (scenePtr != NULL){
		QGraphicsView* viewPtr = scenePtr->views().at(0);

		QMatrix sceneMatrix = viewPtr->matrix();
		sceneMatrix.rotate(-2);

		viewPtr->setMatrix(sceneMatrix);
	}
}


} // namespace iqt2d


