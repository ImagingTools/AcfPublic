/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#include "iipr/CFeaturesContainer.h"


namespace iipr
{


// reimplemented (iipr::IFeaturesConsumer)

void CFeaturesContainer::ResetFeatures()
{
	istd::CChangeNotifier changePtr(this);

	m_featuresList.Reset();
}


bool CFeaturesContainer::AddFeature(const iipr::IFeature* featurePtr, bool* /*isFullPtr*/)
{
	if (featurePtr != NULL){
		istd::CChangeNotifier changePtr(this);

		m_featuresList.PushBack(const_cast<iipr::IFeature*>(featurePtr));
		
		return true;
	}

	return false;
}


// reimplemented (iipr::IFeaturesContainer)

iipr::IFeaturesContainer::Features CFeaturesContainer::GetFeatures() const
{
	iipr::IFeaturesContainer::Features featuresList;
	
	for (int index = 0; index < m_featuresList.GetCount(); index++){
		featuresList.push_back(m_featuresList.GetAt(index));
	}

	return featuresList;
}


} // namespace iipr


