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


#include "iview/CShapeControl.h"


namespace iview
{


CShapeControl::CShapeControl()
{
	m_shapeTransformMode = STM_COMBINE;
	m_shapeTransform.Reset();
}


CShapeControl::CShapeControl(const CShapeControl& shapeControl)
{
	m_shapeTransform = shapeControl.m_shapeTransform;
	m_shapeTransformMode = shapeControl.m_shapeTransformMode;
}


void CShapeControl::SetTransformMode(ShapeTransformMode mode)
{
	if (m_shapeTransformMode != mode){
		m_shapeTransformMode = mode;

		Invalidate(CS_CONSOLE);
	}
}


// protected methods

void CShapeControl::CalcTransforms() const
{
	const IDisplay* displayPtr = GetDisplayPtr();
	I_ASSERT(displayPtr != NULL);

	if (m_shapeTransformMode == STM_SHAPE){
		displayPtr->GetTransform().GetApply(m_shapeTransform, m_logToScreenTransform);
		m_logToViewTransform = m_shapeTransform;
		m_areTransformsValid = true;

		return;
	}

	do{
		const ILogicalCoords* logicalPtr = dynamic_cast<const ILogicalCoords*>(displayPtr);

		if (logicalPtr != NULL){
			switch (m_shapeTransformMode){
			case STM_VIEW:
				m_logToScreenTransform = logicalPtr->GetLogToScreenTransform();
				m_logToViewTransform = logicalPtr->GetLogToViewTransform();
				break;

			case STM_COMBINE:
				logicalPtr->GetLogToScreenTransform().GetApply(m_shapeTransform, m_logToScreenTransform);
				logicalPtr->GetLogToViewTransform().GetApply(m_shapeTransform, m_logToViewTransform);
				break;

			default:
				I_CRITICAL();	// Other modes not implemented.
			}
			m_areTransformsValid = true;
			return;
		}
		displayPtr = displayPtr->GetParentDisplayPtr();
	} while (displayPtr != NULL);

	switch (m_shapeTransformMode){
	case STM_VIEW:
		m_logToScreenTransform = displayPtr->GetTransform();
		m_logToViewTransform = i2d::CAffine2d::GetIdentity();
		break;

	case STM_SHAPE:
	case STM_COMBINE:
		displayPtr->GetTransform().GetApply(m_shapeTransform, m_logToScreenTransform);
		m_logToViewTransform = m_shapeTransform;
		break;

	default:
		I_CRITICAL();	// Other modes not implemented.
	}

	m_areTransformsValid = true;
}


} // namespace iview



