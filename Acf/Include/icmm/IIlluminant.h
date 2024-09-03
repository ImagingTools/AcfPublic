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
#include <icmm/IWhitePointProvider.h>


namespace icmm
{


class IIlluminant: virtual public IWhitePointProvider
{
public:
	virtual void SetWhitePoint(const icmm::CVarColor& whitePoint) = 0;
	virtual QString GetIllumninantName() const = 0;
	virtual void SetIllumninantName(const QString& illuminantName) = 0;
	virtual StandardIlluminant GetIllumninantType() const = 0;
	virtual void SetIllumninantType(const StandardIlluminant& illuminantType) = 0;
};


} // namespace icmm


