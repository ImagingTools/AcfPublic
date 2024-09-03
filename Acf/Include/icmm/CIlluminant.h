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


#pragma once


// ACF includes
#include <icmm/IIlluminant.h>


namespace icmm
{


class CIlluminant: virtual public IIlluminant
{
public:
	CIlluminant(
				StandardIlluminant illuminantType = StandardIlluminant::D65,
				const QString& illuminantName = "D65",
				const icmm::CVarColor& whitePoint = icmm::CVarColor());
	CIlluminant(const CIlluminant& other);

	// reimplemented (IWhitePointProvider)
	virtual icmm::CVarColor GetWhitePoint() const;

	// reimplemented (IIluminant)
	virtual void SetWhitePoint(const icmm::CVarColor& whitePoint) override;
	virtual QString GetIllumninantName() const override;
	virtual void SetIllumninantName(const QString& illuminantName) override;
	virtual StandardIlluminant GetIllumninantType() const override;
	virtual void SetIllumninantType(const StandardIlluminant& illuminantType) override;

private:
	StandardIlluminant m_illuminantType = StandardIlluminant::D65;
	QString m_illuminantName = "D65";
	icmm::CVarColor m_whitePoint;
};


} // namespace icmm


