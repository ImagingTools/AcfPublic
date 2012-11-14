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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "i2d/COrientedCircle.h"


// ACF includes
#include "istd/TChangeNotifier.h"

#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace i2d
{	


COrientedCircle::COrientedCircle()
:	m_orientatedOutside(false)
{
}


COrientedCircle::COrientedCircle(double radius, const CVector2d& center, bool orientatedOutside)
:	BaseClass(radius, center), m_orientatedOutside(orientatedOutside)
{
}


void COrientedCircle::SetOrientedOutside(bool orientatedOutside)
{
	if (orientatedOutside != m_orientatedOutside){
		istd::CChangeNotifier notifier(this);

		m_orientatedOutside = orientatedOutside;
	}
}


bool COrientedCircle::operator==(const COrientedCircle& ref) const
{
	return BaseClass::operator==(ref) && (ref.m_orientatedOutside == m_orientatedOutside);
}


bool COrientedCircle::operator!=(const COrientedCircle& ref) const
{
	return BaseClass::operator!=(ref) || (ref.m_orientatedOutside != m_orientatedOutside);
}


// reimplemented (iser::ISerializable)

bool COrientedCircle::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag orientatedOutsideTag("IsOrientedOutside", "Flag if this circle is oriented inside or outside");

	istd::CChangeNotifier notifier(archive.IsStoring()? NULL: this, CF_OBJECT_POSITION | CF_MODEL);

	bool retVal = true;

	retVal = retVal && BaseClass::Serialize(archive);

	retVal = retVal && archive.BeginTag(orientatedOutsideTag);
	retVal = retVal && archive.Process(m_orientatedOutside);
	retVal = retVal && archive.EndTag(orientatedOutsideTag);

	return retVal;
}


} // namespace i2d

