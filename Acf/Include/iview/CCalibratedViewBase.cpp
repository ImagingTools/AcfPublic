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


#include "iview/CCalibratedViewBase.h"


// Qt includes
#include <QPainter>


// ACF includes
#include "i2d/CRectangle.h"

#include "iview/IViewRulersAccessor.h"
#include "iview/IColorShema.h"
#include "iview/IVisualizable.h"


namespace iview
{


CCalibratedViewBase::CCalibratedViewBase()
	:   m_calibrationPtr(&CNoneCalibration::GetInstance()),
		m_isGridVisible(false),
		m_isGridInMm(true),
		m_minGridDistance(10)
{
	m_calibrationLayerIndex = -1;
}


void CCalibratedViewBase::ConnectCalibrationShape(iview::IShape* shapePtr)
{
	I_ASSERT(shapePtr != NULL);
	if (GetLayersCount() <= 0){
		InsertDefaultLayers();
	}
	I_ASSERT(m_calibrationLayerIndex >= 0);

	iview::ILayer& layer = GetLayer(m_calibrationLayerIndex);
	layer.ConnectShape(shapePtr);
}


// reimplemented (iview::CViewBase)

void CCalibratedViewBase::UpdateAllShapes(int changeFlag)
{
	if ((changeFlag & iview::CF_TRANSFORM) != 0){
		SetBackgroundBufferValid(false);
	}

	BaseClass::UpdateAllShapes(changeFlag);
}


void CCalibratedViewBase::InsertDefaultLayers()
{
	BaseClass::InsertDefaultLayers();

	int layerIndex = InsertLayer(&m_calibrationLayer, 1, LT_CALIBRATION);
	SetLastBackgroundLayerIndex(layerIndex);
}


// reimplemented (iview::IShapeView)

int CCalibratedViewBase::InsertLayer(iview::ILayer* layerPtr, int index, int layerType)
{
	int result = BaseClass::InsertLayer(layerPtr, index, layerType);

	if ((layerType & LT_CALIBRATION) != 0){
		m_calibrationLayerIndex = result;
	}
	else if (m_calibrationLayerIndex >= result){
		m_calibrationLayerIndex++;
	}

	return result;
}


void CCalibratedViewBase::RemoveLayer(int index)
{
	BaseClass::RemoveLayer(index);

	if (m_calibrationLayerIndex >= index){
		if (m_calibrationLayerIndex == index){
			m_calibrationLayerIndex = -1;
		}
		else{
			m_calibrationLayerIndex--;
		}
	}
}


} // namespace iview


