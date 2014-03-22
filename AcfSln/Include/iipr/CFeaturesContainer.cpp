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


#include "iipr/CFeaturesContainer.h"


// ACF includes
#include "istd/TChangeNotifier.h"


namespace iipr
{


void CFeaturesContainer::RemoveFeature(int featureIndex)
{
	m_featuresList.RemoveAt(featureIndex);
}


imeas::INumericValue& CFeaturesContainer::GetFeatureRef(int index)
{
	Q_ASSERT(index >= 0);
	Q_ASSERT(index < GetValuesCount());

	imeas::INumericValue* featurePtr = m_featuresList.GetAt(index);
	Q_ASSERT(featurePtr != NULL);

	return *featurePtr;
}


// reimplemented (iipr::IFeaturesConsumer)

void CFeaturesContainer::ResetFeatures()
{
	istd::CChangeNotifier changePtr(this);

	m_featuresList.Reset();
}


bool CFeaturesContainer::AddFeature(const imeas::INumericValue* featurePtr, bool* /*isFullPtr*/)
{
	if (featurePtr != NULL){
		istd::CChangeNotifier changePtr(this);

		m_featuresList.PushBack(const_cast<imeas::INumericValue*>(featurePtr));
		
		return true;
	}

	return false;
}



// reimplemented (imeas::INumericValueProvider)

int CFeaturesContainer::GetValuesCount() const
{
	return m_featuresList.GetCount();
}


const imeas::INumericValue& CFeaturesContainer::GetNumericValue(int index) const
{
	Q_ASSERT(index >= 0);
	Q_ASSERT(index < GetValuesCount());

	const imeas::INumericValue* featurePtr = m_featuresList.GetAt(index);
	Q_ASSERT(featurePtr != NULL);

	return *featurePtr;
}


} // namespace iipr


