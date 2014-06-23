/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iipr/CImageInterpolationParams.h"


// ACF includes
#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


#include "istd/CChangeNotifier.h"


namespace iipr
{


// public methods

CImageInterpolationParams::CImageInterpolationParams()
	:m_interpolationMode(IM_NO_INTERPOLATION)
{
}


// reimplemented (iipr::IImageInterpolationParams)

int CImageInterpolationParams::GetInterpolationMode() const
{
	return m_interpolationMode;
}


void CImageInterpolationParams::SetInterpolationMode(int interpolationMode)
{
	if (m_interpolationMode != interpolationMode){
		istd::CChangeNotifier changePtr(this);

		m_interpolationMode = interpolationMode;
	}
}
	

// reimplemented (iser::ISerializable)

bool CImageInterpolationParams::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag interpolationModeTag("InterpolationMode", "Interpolation mode");

	istd::CChangeNotifier notifier(archive.IsStoring()? NULL: this);

	bool retVal = true;

	retVal = retVal && archive.BeginTag(interpolationModeTag);
	retVal = retVal && archive.Process(m_interpolationMode);
	retVal = retVal && archive.EndTag(interpolationModeTag);

	return retVal;
}


} // namespace iipr


