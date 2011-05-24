/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
**
********************************************************************************/


#ifndef iipr_CFeaturesContainer_included
#define iipr_CFeaturesContainer_included


#include "istd/TPointerVector.h"
#include "istd/TChangeNotifier.h"

#include "iipr/IFeaturesContainer.h"


namespace iipr
{


/**
	Basic implementation of a features container.
*/
class CFeaturesContainer: public IFeaturesContainer
{
public:
	// reimplemented (iipr::IFeaturesConsumer)
	virtual void ResetFeatures();
	virtual bool AddFeature(const iipr::IFeature* featurePtr, bool* isFullPtr = NULL);

	// reimplemented (iipr::IFeaturesContainer)
	virtual Features GetFeatures() const;

private:
	typedef istd::TPointerVector<iipr::IFeature> FeaturesList;

	FeaturesList m_featuresList;
};


} // namespace iipr


#endif // !iipr_CFeaturesContainer_included

