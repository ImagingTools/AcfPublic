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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iprm/CLinearAdjustParamsComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"
#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace iprm
{


CLinearAdjustParamsComp::CLinearAdjustParamsComp()
:	m_scale(1.0),
	m_offset(0)
{
}


// reimplemented (iprm::ILinearAdjustParams)

const ILinearAdjustConstraints* CLinearAdjustParamsComp::GetAdjustConstraints() const
{
	return m_constraintsCompPtr.GetPtr();
}


double CLinearAdjustParamsComp::GetScaleFactor() const
{
	return m_scale;
}


void CLinearAdjustParamsComp::SetScaleFactor(double scale)
{
	if (scale != m_scale){
		istd::CChangeNotifier notifier(this);

		m_scale = scale;
	}
}


double CLinearAdjustParamsComp::GetOffsetFactor() const
{
	return m_offset;
}


void CLinearAdjustParamsComp::SetOffsetFactor(double offset)
{
	if (offset != m_offset){
		istd::CChangeNotifier notifier(this);

		m_offset = offset;
	}
}


// reimplemented (iser::ISerializable)

bool CLinearAdjustParamsComp::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	static iser::CArchiveTag scaleTag("ScaleFactor", "Scale factor of linear adjust");
	retVal = retVal && archive.BeginTag(scaleTag);
	retVal = retVal && archive.Process(m_scale);
	retVal = retVal && archive.EndTag(scaleTag);

	static iser::CArchiveTag offsetTag("OffsetFactor", "Offset factor of linear adjust");
	retVal = retVal && archive.BeginTag(offsetTag);
	retVal = retVal && archive.Process(m_offset);
	retVal = retVal && archive.EndTag(offsetTag);

	return retVal;
}


} // namespace iprm


