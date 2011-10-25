/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iipr/CFeatureBase.h"


// ACF includes
#include "istd/TChangeNotifier.h"
#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace iipr
{


// public methods

CFeatureBase::CFeatureBase(double weight)
:	m_weight(weight)
{
}


void CFeatureBase::SetWeight(double weight)
{
	if (weight != m_weight){
		istd::CChangeNotifier notifier(this);

		m_weight = weight;
	}
}


// reimplemented (iipr::IFeature)

double CFeatureBase::GetWeight() const
{
	return m_weight;
}


// reimplemented (iser::ISerializable)

bool CFeatureBase::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	static iser::CArchiveTag weightTag("Weight", "Weight of feature");
	retVal = retVal && archive.BeginTag(weightTag);
	retVal = retVal && archive.Process(m_weight);
	retVal = retVal && archive.EndTag(weightTag);

	return retVal;
}


} // namespace iipr

