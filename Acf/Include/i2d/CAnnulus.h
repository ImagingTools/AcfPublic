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


#ifndef i2d_CAnnulus_included
#define i2d_CAnnulus_included


#include "i2d/CPosition2d.h"
#include "i2d/CCircle.h"
#include "i2d/CRectangle.h"


namespace i2d
{	


/**
	Definition of graphical annulus object.
	Annulus is area between two concentrical circles.
	This object is stored using center position and two radii.
*/
class CAnnulus: public i2d::CPosition2d
{
public:
	typedef i2d::CPosition2d BaseClass;

	CAnnulus();
	CAnnulus(const i2d::CVector2d& center, double innerRadius, double outerRadius);

	bool IsAnnulusValid() const;

	double GetInnerRadius() const;
	void SetInnerRadius(double innerRadius);

	double GetOuterRadius() const;
	void SetOuterRadius(double outerRadius);

	CCircle GetInnerCircle() const;
	CCircle GetOuterCircle() const;

	virtual CRectangle GetBoundingBox() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	istd::CRange m_radiusRange;
};


} // namespace i2d


#endif // !i2d_CAnnulus_included


