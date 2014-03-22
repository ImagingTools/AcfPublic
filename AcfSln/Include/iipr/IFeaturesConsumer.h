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


#ifndef iipr_IFeaturesConsumer_included
#define iipr_IFeaturesConsumer_included


#include "istd/IChangeable.h"

#include "imeas/INumericValue.h"


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
	virtual bool AddFeature(const imeas::INumericValue* featurePtr, bool* isFullPtr = NULL) = 0;
};


} // namespace iipr


#endif // !iipr_IFeaturesConsumer_included

