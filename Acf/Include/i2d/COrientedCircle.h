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


#ifndef i2d_COrientedCircle_included
#define i2d_COrientedCircle_included


#include "i2d/CCircle.h"


namespace i2d
{


/**
	Definition of an oriented graphical circle object.
	The circle can be oriented outside or inside.
	Interpretation what it means 'outside oriented' is user dependend.
*/
class COrientedCircle: public CCircle
{
public:
	typedef CCircle BaseClass;

	COrientedCircle();
	COrientedCircle(double radius, const CVector2d& center, bool orientedOutside);

	/**
		Check if this circle is oriented outside.
		Interpretation what it means 'outside oriented' is user dependend.
	*/
	bool IsOrientedOutside() const;
	/**
		Set this circle oriented outside or inside.
		Interpretation what it means 'outside oriented' is user dependend.
	*/
	void SetOrientedOutside(bool orientedOutside);

	bool operator==(const COrientedCircle& circle) const;
	bool operator!=(const COrientedCircle& circle) const;

	// reimplemented (istd::IChangeable)
	virtual int GetSupportedOperations() const;
	virtual bool CopyFrom(const IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS);
	virtual istd::IChangeable* CloneMe(CompatibilityMode mode = CM_WITHOUT_REFS) const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	bool m_orientedOutside;
};


// inline methods

inline bool COrientedCircle::IsOrientedOutside() const
{
	return m_orientedOutside;
}


} // namespace i2d


#endif // !i2d_COrientedCircle_included


