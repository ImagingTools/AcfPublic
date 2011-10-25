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


#ifndef iipr_CFeatureBase_included
#define iipr_CFeatureBase_included


#include "iipr/IFeature.h"


namespace iipr
{


/**
	Base implementation of IFeature interface to reduce overhead by interface changes.
*/
class CFeatureBase: virtual public iipr::IFeature
{
public:
	CFeatureBase(double weight = 1.0);

	void SetWeight(double weight);

	// reimplemented (iipr::IFeature)
	virtual double GetWeight() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	double m_weight;
};


} // namespace iipr


#endif // !iipr_CFeatureBase_included


