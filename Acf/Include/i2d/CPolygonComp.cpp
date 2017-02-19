/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#include <i2d/CPolygonComp.h>


namespace i2d
{


// protected methods

// reimplemented (icomp::CComponentBase)

void CPolygonComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	Q_ASSERT(m_xAttrPtr.IsValid());
	Q_ASSERT(m_yAttrPtr.IsValid());

	int count = qMin(m_xAttrPtr.GetCount(), m_yAttrPtr.GetCount());
	for (int i = 0; i < count; i++){
		BaseClass2::InsertNode(i2d::CVector2d(m_xAttrPtr[i], m_yAttrPtr[i]));
	}
}


} // namespace i2d
