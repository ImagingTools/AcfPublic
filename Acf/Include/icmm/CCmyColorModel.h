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
#include <icmm/CSubstractiveColorModel.h>


namespace icmm
{


class CCmyColorModel: public CSubstractiveColorModel
{
public:
	// reimplemented (icmm::IColorantList)
	virtual QByteArrayList GetColorantIds() const override;
	virtual QString GetColorantName(const QByteArray& colorantId) const override;
	virtual ColorantUsage GetColorantUsage(const QByteArray& colorantId) const override;
};


// public methods

// reimplemented (icmm::IColorantList)

QByteArrayList CCmyColorModel::GetColorantIds() const
{
	return {"Cyan", "Magenta", "Yellow"};
}


QString CCmyColorModel::GetColorantName(const QByteArray& colorantId) const
{
	QByteArrayList colorantIds = CCmyColorModel::GetColorantIds();
	if (colorantIds.contains(colorantId)) {
		return QString(colorantId);
	}

	return QString();
}


icmm::ColorantUsage CCmyColorModel::GetColorantUsage(const QByteArray& colorantId) const
{
	Q_ASSERT(GetColorantIds().contains(colorantId));

	return CU_NONE;
}


} // namespace icmm


