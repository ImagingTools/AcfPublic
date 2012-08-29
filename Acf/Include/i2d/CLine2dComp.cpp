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


#include "i2d/CLine2dComp.h"


namespace i2d
{		

// protected methods

// reimplemented (icomp::CComponentBase)

void CLine2dComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	I_ASSERT(m_x1AttrPtr.IsValid());
	I_ASSERT(m_y1AttrPtr.IsValid());
	I_ASSERT(m_x2AttrPtr.IsValid());
	I_ASSERT(m_y2AttrPtr.IsValid());

	SetPoint1(i2d::CVector2d(*m_x1AttrPtr, *m_y1AttrPtr));
	SetPoint2(i2d::CVector2d(*m_x2AttrPtr, *m_y2AttrPtr));
}


} // namespace i2d


