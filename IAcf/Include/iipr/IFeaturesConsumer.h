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


#ifndef iipr_IFeaturesConsumer_included
#define iipr_IFeaturesConsumer_included


#include "istd/IChangeable.h"

#include "iipr/IFeature.h"


namespace iipr
{


/**
	Common interface for a features container consuming feature objects.
*/
class IFeaturesConsumer: virtual public istd::IChangeable
{
public:
	/**
		Remove all features from this container.
	*/
	virtual void ResetFeatures() = 0;

	/**
		Add new feature to the set of features.
		\param	featurePtr	instance of feature object.
							Please note, that the container takes controll over this object, 
							so you cannot destroy this object manually.
							It cannot be NULL.
		\param isFullPtr	If it isn't NULL this paramster is used to get info whether 
							the added feature satisfy search constraints and no additionally features should be added
		\return	true if the pushed feature is valid for this container and was inserted correctly.
	*/
	virtual bool AddFeature(const IFeature* featurePtr, bool* isFullPtr = NULL) = 0;
};


} // namespace iipr


#endif // !iipr_IFeaturesConsumer_included

