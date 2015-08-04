/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef iipr_CFeaturesContainer_included
#define iipr_CFeaturesContainer_included


#include "istd/TPointerVector.h"

#include "iipr/IFeaturesConsumer.h"
#include "imeas/INumericValueProvider.h"


namespace iipr
{


/**
	Basic implementation of a features container.
*/
class CFeaturesContainer:
			virtual public IFeaturesConsumer,
			virtual public imeas::INumericValueProvider
{
public:
	/**
		Remove feature at selected index.
		The following elements will be shift, size of this container will be decreased.
	*/
	void RemoveFeature(int featureIndex);
	/**
		Get access to stored feature.
	*/
	imeas::INumericValue& GetFeatureRef(int index);

	// reimplemented (iipr::IFeaturesConsumer)
	virtual void ResetFeatures();
	virtual bool AddFeature(const imeas::INumericValue* featurePtr, bool* isFullPtr = NULL);

	// reimplemented (imeas::INumericValueProvider)
	virtual int GetValuesCount() const;
	virtual const imeas::INumericValue& GetNumericValue(int index) const;

private:
	typedef istd::TPointerVector<imeas::INumericValue> FeaturesList;

	FeaturesList m_featuresList;
};


} // namespace iipr


#endif // !iipr_CFeaturesContainer_included

