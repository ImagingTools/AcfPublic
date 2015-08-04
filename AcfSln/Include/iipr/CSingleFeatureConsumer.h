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


#ifndef iipr_CSingleFeatureConsumer_included
#define iipr_CSingleFeatureConsumer_included


#include "istd/TDelPtr.h"

#include "iipr/IFeaturesConsumer.h"
#include "imeas/INumericValueProvider.h"


namespace iipr
{


/**
	Feature consumer implmentation storing one feature only.
*/
class CSingleFeatureConsumer:
			virtual public IFeaturesConsumer,
			virtual public imeas::INumericValueProvider
{
public:

	/**
		Control storing of the features in the container.
	*/
	enum FeaturePolicy
	{
		/**
			Only first feature is stored in the container.
		*/
		FP_FIRST,

		/**
			Only last feature is stored in the container.
		*/
		FP_LAST,

		/**
			Only heaviest feature is stored in the container
		*/
		FP_HEAVIEST
	};

	CSingleFeatureConsumer(int featurePolicy = FP_FIRST);

	/**
		Get feature adding policy.
		\sa FeaturePolicy
	*/
	int GetFeaturePolicy() const;

	/**
		Set feature adding policy. 
		\note Call of this function removes the current feature.
	*/
	void SetFeaturePolicy(int featurePolicy);

	// reimplemented (iipr::IFeaturesConsumer)
	virtual void ResetFeatures();
	virtual bool AddFeature(const imeas::INumericValue* featurePtr, bool* isFullPtr = NULL);

	// reimplemented (imeas::INumericValueProvider)
	virtual int GetValuesCount() const;
	virtual const imeas::INumericValue& GetNumericValue(int index) const;

private:
	istd::TDelPtr<const imeas::INumericValue> m_featurePtr;

	int m_featurePolicy;
};


} // namespace iipr


#endif // !iipr_CSingleFeatureConsumer_included


