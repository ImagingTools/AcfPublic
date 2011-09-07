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


#ifndef iipr_CSingleFeatureConsumer_included
#define iipr_CSingleFeatureConsumer_included


#include "istd/TDelPtr.h"

#include "iipr/IFeaturesContainer.h"


namespace iipr
{


/**
	Feature consumer implmentation storing one feature only.
*/
class CSingleFeatureConsumer: virtual public IFeaturesContainer
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

	const IFeature* GetFeature() const;

	// reimplemented (iipr::IFeaturesConsumer)
	virtual void ResetFeatures();
	virtual bool AddFeature(const IFeature* featurePtr, bool* isFullPtr = NULL);

	// reimplemented (iipr::IFeaturesContainer)
	virtual Features GetFeatures() const;

private:
	istd::TDelPtr<const IFeature> m_featurePtr;

	int m_featurePolicy;
};


} // namespace iipr


#endif // !iipr_CSingleFeatureConsumer_included


