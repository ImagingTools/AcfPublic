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
#include <icmm/CCmyColorModel.h>


namespace icmm
{


class CCmykColorModel: public CCmyColorModel
{
public:
	typedef CCmyColorModel BaseClass;

	// reimplemented (icmm::IColorantList)
	virtual QByteArrayList GetColorantIds() const override;
	icmm::ColorantUsage GetColorantUsage(const QByteArray& colorantId) const override;
};


// public methods

// reimplemented (icmm::IColorantList)

inline QByteArrayList CCmykColorModel::GetColorantIds() const
{
	return {"Cyan", "Magenta", "Yellow", "Black"};
}


icmm::ColorantUsage CCmykColorModel::GetColorantUsage(const QByteArray& colorantId) const
{
	Q_ASSERT(GetColorantIds().contains(colorantId));

	if (colorantId == "Cyan"){
		return CU_CYAN;
	}
	else if (colorantId == "Magenta"){
		return CU_MAGENTA;
	}
	else if (colorantId == "Yellow"){
		return CU_YELLOW;
	}

	else if (colorantId == "Black"){
		return CU_BLACK;
	}

	return CU_NONE;
}


} // namespace icmm


