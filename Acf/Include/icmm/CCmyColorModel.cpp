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


#include <icmm/CCmyColorModel.h>
#include <icmm/CSubstractiveColorModel.h>


namespace icmm
{


// public static methods

IColorantList::ColorantId CCmyColorModel::GetCyan()
{
	return "Cyan";
}


IColorantList::ColorantId CCmyColorModel::GetMagenta()
{
	return "Magenta";
}


IColorantList::ColorantId CCmyColorModel::GetYellow()
{
	return "Yellow";
}


// public methods

// reimplemented (icmm::IColorantList)

IColorantList::ColorantIds CCmyColorModel::GetColorantIds() const
{
	return {GetCyan(), GetMagenta(), GetYellow()};
}


icmm::ColorantUsage CCmyColorModel::GetColorantUsage(const ColorantId& colorantId) const
{
	Q_ASSERT(GetColorantIds().contains(colorantId));

	if (colorantId == GetCyan()){
		return CU_CYAN;
	}
	else if (colorantId == GetMagenta()){
		return CU_MAGENTA;
	}
	else if (colorantId == GetYellow()){
		return CU_YELLOW;
	}

	return CU_NONE;
}

std::unique_ptr<ISubstractiveColorModel> CCmyColorModel::CreateSubspaceModel(const QStringList& colorantIds) const
{
	return CSubstractiveColorModel::CreateSubspaceModelFrom(*this, colorantIds);
}


} // namespace icmm


