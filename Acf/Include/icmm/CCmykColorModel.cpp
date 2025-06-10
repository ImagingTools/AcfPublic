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


#include <icmm/CCmykColorModel.h>
#include <icmm/CSubstractiveColorModel.h>
#include <imod/TModelWrap.h>


namespace icmm
{


// static public methods

IColorantList::ColorantId CCmykColorModel::GetBlack()
{
	return "Black";
}


// public methods

// reimplemented (icmm::IColorantList)

IColorantList::ColorantIds CCmykColorModel::GetColorantIds() const
{
	ColorantIds retVal = BaseClass::GetColorantIds();

	retVal += GetBlack();

	return retVal;
}


icmm::ColorantUsage CCmykColorModel::GetColorantUsage(const ColorantId& colorantId) const
{
	Q_ASSERT(GetColorantIds().contains(colorantId));

	if (colorantId == GetBlack()){
		return CU_BLACK;
	}

	return BaseClass::GetColorantUsage(colorantId);
}


std::unique_ptr<ISubstractiveColorModel> CCmykColorModel::CreateSubspaceModel(const QStringList& colorantIds) const
{
	auto subModel = std::make_unique<imod::TModelWrap<CCmyColorModel>>();

	if (colorantIds == subModel->GetColorantIds()) {
		subModel->SetPreviewSpec(GetPreviewSpec());
		for (const auto& id: subModel->GetColorantIds()) {
			icmm::CCieLabColor cieLab(nullptr);
			if (GetColorantVisualInfo(id, cieLab)) {
				subModel->SetColorantPreview(id, cieLab.GetLab());
			}
		}
		return subModel;
	}

	return CSubstractiveColorModel::CreateSubspaceModelFrom(*this, colorantIds);
}


} // namespace icmm


