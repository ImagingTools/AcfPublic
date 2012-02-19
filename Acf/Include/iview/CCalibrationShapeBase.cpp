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


#include "iview/CCalibrationShapeBase.h"


#include "iview/ICalibrated.h"


namespace iview
{


CCalibrationShapeBase::CCalibrationShapeBase()
{
	SetTransformMode(STM_SHAPE);
}


// reimplemented (iview::IInteractiveShape)

void CCalibrationShapeBase::BeginDrag(const i2d::CVector2d& reference)
{
	I_ASSERT(IsDisplayConnected());
	I_ASSERT(m_calibPtr != NULL);

	const iview::IIsomorphicCalibration& isomorphCalib = GetIsomorphCalib();
	const i2d::CAffine2d& transform = GetLogToViewTransform();

	i2d::CVector2d logPos;
	isomorphCalib.GetApplyToLog(transform.GetInvertedApply(reference), logPos);
	BeginLogDrag(logPos);
}



void CCalibrationShapeBase::SetDragPosition(const i2d::CVector2d& position)
{
	I_ASSERT(IsDisplayConnected());
	I_ASSERT(m_calibPtr != NULL);

	const iview::IIsomorphicCalibration& isomorphCalib = GetIsomorphCalib();
	const i2d::CAffine2d& transform = GetLogToViewTransform();

	i2d::CVector2d logPos;
	isomorphCalib.GetApplyToLog(transform.GetInvertedApply(position), logPos);
	SetLogDragPosition(logPos);
}



// reimplement (iview::IVisualizable)

bool CCalibrationShapeBase::IsDisplayAccepted(const iview::IDisplay& display) const
{
	return BaseClass::IsDisplayAccepted(display) && (FindCalib(display) != NULL);
}



void CCalibrationShapeBase::OnConnectDisplay(iview::IDisplay* displayPtr)
{
	BaseClass::OnConnectDisplay(displayPtr);
	m_calibPtr = FindCalib(*displayPtr);
	I_ASSERT(m_calibPtr != NULL);
}



void CCalibrationShapeBase::OnDisconnectDisplay(iview::IDisplay* displayPtr)
{
	BaseClass::OnDisconnectDisplay(displayPtr);
	m_calibPtr = NULL;
}


// protected static methods

const IIsomorphicCalibration* CCalibrationShapeBase::FindCalib(const iview::IDisplay& display)
{
	const iview::IDisplay* displayPtr = &display;
	while (displayPtr != NULL){
		const ICalibrated* calibratedPtr = dynamic_cast<const ICalibrated*>(displayPtr);
		if (calibratedPtr != NULL){
			const IIsomorphicCalibration* isomorphCalibPtr = dynamic_cast<const iview::IIsomorphicCalibration*>(&calibratedPtr->GetCalibration());
			if (isomorphCalibPtr != NULL){
				return isomorphCalibPtr;
			}
		}

		displayPtr = displayPtr->GetParentDisplayPtr();
	}

	return NULL;
}



} // namespace iview



