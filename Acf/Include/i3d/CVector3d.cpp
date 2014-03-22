/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#include "i3d/CVector3d.h"


#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace i3d
{


CVector3d CVector3d::GetCrossProduct(const imath::TVector<3>& vector) const
{
	return CVector3d(
				GetY() * vector[2] - GetZ() * vector[1],
				GetZ() * vector[0] - GetX() * vector[2],
				GetX() * vector[1] - GetY() * vector[0]);
}


CVector3d CVector3d::GetNormalized(double length) const
{
	CVector3d retVal;

	if (GetNormalized(retVal, length)){
		return retVal;
	}

	return CVector3d(length, 0.0, 0.0);
}


} // namespace i3d


