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


#ifndef i2d_COrientedCircle_included
#define i2d_COrientedCircle_included


#include "i2d/CCircle.h"


namespace i2d
{	


/**
	Definition of graphical circle object with orientatedOutside.
*/
class COrientedCircle: public CCircle
{
public:
	typedef CCircle BaseClass;

	COrientedCircle();
	COrientedCircle(double radius, const CVector2d& center, bool orientatedOutside);

	bool IsOrientedOutside() const;
	void SetOrientedOutside(bool orientatedOutside);

	bool operator==(const COrientedCircle& circle) const;
	bool operator!=(const COrientedCircle& circle) const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	bool m_orientatedOutside;
};


// inline methods

inline bool COrientedCircle::IsOrientedOutside() const
{
	return m_orientatedOutside;
}


} // namespace i2d


#endif // !i2d_COrientedCircle_included


