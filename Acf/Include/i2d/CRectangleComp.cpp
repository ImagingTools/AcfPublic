/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "i2d/CRectangleComp.h"


namespace i2d
{


// protected methods

// reimplemented (icomp::CComponentBase)

void CRectangleComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	Q_ASSERT(m_leftAttrPtr.IsValid());
	Q_ASSERT(m_topAttrPtr.IsValid());
	Q_ASSERT(m_widthAttrPtr.IsValid());
	Q_ASSERT(m_heightAttrPtr.IsValid());

	SetLeft(*m_leftAttrPtr);
	SetTop(*m_topAttrPtr);
	SetRight(*m_leftAttrPtr + *m_widthAttrPtr);
	SetBottom(*m_topAttrPtr + *m_heightAttrPtr);
}


} // namespace i2d


