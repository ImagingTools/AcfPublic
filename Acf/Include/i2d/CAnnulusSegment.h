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


#ifndef i2d_CAnnulusSegment_included
#define i2d_CAnnulusSegment_included


#include "i2d/CAnnulus.h"


namespace i2d
{	


class CAnnulusSegment: public CAnnulus
{
public:
	typedef CAnnulus BaseClass;

	CAnnulusSegment();
	CAnnulusSegment(
				const i2d::CVector2d& center,
				double innerRadius,
				double outerRadius,
				double beginAngle,
				double endAngle);

	double GetBeginAngle() const;
	void SetBeginAngle(double angle);
	double GetEndAngle() const;
	void SetEndAngle(double angle);

	virtual CRectangle GetBoundingBox() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	istd::CRange m_angleRange;
};


} // namespace i2d


#endif // !i2d_CAnnulusSegment_included


