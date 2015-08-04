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


#include "i2d/CArcComp.h"


namespace i2d
{


// protected methods

// reimplemented (icomp::CComponentBase)

void CArcComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	Q_ASSERT(m_centerXAttrPtr.IsValid());
	Q_ASSERT(m_centerYAttrPtr.IsValid());
	Q_ASSERT(m_radiusAttrPtr.IsValid());
	Q_ASSERT(m_startAngleAttrPtr.IsValid());
	Q_ASSERT(m_endAngleAttrPtr.IsValid());

	SetPosition(i2d::CVector2d(*m_centerXAttrPtr, *m_centerXAttrPtr));
	SetRadius(*m_radiusAttrPtr);
	SetStartAngle(*m_startAngleAttrPtr);
	SetEndAngle(*m_endAngleAttrPtr);
}

} // namespace i2d
