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


#ifndef iipr_CCaliperFeature_included
#define iipr_CCaliperFeature_included


#include "imeas/CSimpleNumericValue.h"


namespace iipr
{


/**
	Implementation of INumericValue interface for caliper-extracted features.
*/
class CCaliperFeature: public imeas::CSimpleNumericValue
{
public:
	typedef imeas::CSimpleNumericValue BaseClass;

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
	double GetWeight() const;
	int GetEdgeMode() const;

	// reimplemented (imeas::INumericValue)
	virtual bool IsValueTypeSupported(ValueTypeId valueTypeId) const;
	virtual imath::CVarVector GetComponentValue(ValueTypeId valueTypeId) const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	double m_position;
	double m_weight;
	int m_edgeMode;
};


} // namespace iipr


#endif // !iipr_CCaliperFeature_included


