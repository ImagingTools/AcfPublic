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


#ifndef i2d_CTransform_included
#define i2d_CTransform_included


#include "i2d/CVector2d.h"
#include "i2d/CLine2d.h"


namespace i2d
{	


class CTransform
{
public:
	CTransform();
	CTransform(const CVector2d& translation, const CVector2d& scale, double angle);

	CVector2d ApplyTo(const CVector2d& point) const;
	CLine2d ApplyTo(const CLine2d& line) const;

	CTransform& Rotate(double angle);
	CTransform& Scale(const CVector2d& scale);
	CTransform& Scale(double sx, double sy);
	CTransform& Translate(const CVector2d& translation);
	CTransform& Translate(double dx, double dy);

	CTransform GetRotated(double angle) const;
	CTransform GetScaled(const CVector2d& scale) const;
	CTransform GetScaled(double sx, double sy) const;
	CTransform GetTranslated(const CVector2d& translation) const;
	CTransform GetTranslated(double dx, double dy) const;

private:
	double m_m11;
	double m_m12;
	double m_m21;
	double m_m22;
	double m_dx;
	double m_dy;
};


} // namespace i2d


#endif // i2d_CTransform_included

