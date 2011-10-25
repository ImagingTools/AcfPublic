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


#ifndef iipr_CCaliperFeature_included
#define iipr_CCaliperFeature_included


#include "iipr/CFeatureBase.h"


namespace iipr
{


/**
	Implementation of IFeature interface for caliper-extracted features.
*/
class CCaliperFeature: public CFeatureBase
{
public:
	typedef CFeatureBase BaseClass;

	enum EdgeMode
	{
		EM_FALLING,
		EM_RISING
	};

	CCaliperFeature(
				double weight,
				double position,
				int edgeMode);

	double GetPosition() const;
	int GetEdgeMode() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	double m_position;
	int m_edgeMode;
};


} // namespace iipr


#endif // !iipr_CCaliperFeature_included


