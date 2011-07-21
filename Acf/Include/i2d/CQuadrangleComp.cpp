/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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


#include "i2d/CQuadrangleComp.h"


namespace i2d
{		

// protected methods

// reimplemented (icomp::CComponentBase)

void CQuadrangleComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	I_ASSERT(m_diag1X1AttrPtr.IsValid());
	I_ASSERT(m_diag1Y1AttrPtr.IsValid());
	I_ASSERT(m_diag1X2AttrPtr.IsValid());
	I_ASSERT(m_diag1Y2AttrPtr.IsValid());
	I_ASSERT(m_diag2X1AttrPtr.IsValid());
	I_ASSERT(m_diag2Y1AttrPtr.IsValid());
	I_ASSERT(m_diag2X2AttrPtr.IsValid());
	I_ASSERT(m_diag2Y2AttrPtr.IsValid());

	i2d::CLine2d firstDiagonal(
				i2d::CVector2d(*m_diag1X1AttrPtr, *m_diag1Y1AttrPtr),
				i2d::CVector2d(*m_diag1X2AttrPtr, *m_diag1Y2AttrPtr));

	i2d::CLine2d secondDiagonal(
				i2d::CVector2d(*m_diag2X1AttrPtr, *m_diag2Y1AttrPtr),
				i2d::CVector2d(*m_diag2X2AttrPtr, *m_diag2Y2AttrPtr));

	SetFirstDiagonal(firstDiagonal);
	SetSecondDiagonal(firstDiagonal);
}


} // namespace i2d


