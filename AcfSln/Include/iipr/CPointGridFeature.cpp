/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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


#include <iipr/CPointGridFeature.h>


// ACF includes
#include <istd/TDelPtr.h>
#include <istd/CChangeNotifier.h>
#include <iser/IArchive.h>
#include <iser/CArchiveTag.h>


namespace iipr
{


// public methods

CPointGridFeature::CPointGridFeature()
	:BaseClass()
{
	m_charucoIds.clear();
}


bool CPointGridFeature::AddChaurcoIds(const std::vector<int>& ids)
{
	m_charucoIds = ids;
	return true;
}

const std::vector<int>& CPointGridFeature::GetCharucoIds() const
{
	return m_charucoIds;
}


// reimplemented (imeas::INumericValue)

bool CPointGridFeature::IsValueTypeSupported(CPointGridFeature::ValueTypeId valueTypeId) const
{
	switch (valueTypeId){
	case VTI_AUTO:
		return true;

	default:
		return false;
	}
}


imath::CVarVector CPointGridFeature::GetComponentValue(CPointGridFeature::ValueTypeId valueTypeId) const
{
	imath::CVarVector result;

	switch (valueTypeId){
	case VTI_AUTO:
		return BaseClass::GetComponentValue(VTI_AUTO);

	default:
		break;
	}

	return result;
}

// reimplemented (istd::IChangeable)

istd::IChangeableUniquePtr CPointGridFeature::CloneMe(CompatibilityMode mode) const
{
	istd::TDelPtr<CPointGridFeature> retVal(new CPointGridFeature);

	if (retVal->CopyFrom(*this, mode)){
		return retVal.PopPtr();
	}

	return NULL;
}


} // namespace iipr


