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


#ifndef iipr_CCircleFinderParams_included
#define iipr_CCircleFinderParams_included


#include "iipr/ICircleFinderParams.h"


namespace iipr
{


class CCircleFinderParams: virtual public ICircleFinderParams
{
public:
	CCircleFinderParams();

	// reimplemented (iipr::ICircleFinderParams)
	virtual int GetCaliperMode() const;
	virtual void SetCaliperMode(int caliperMode);
	virtual bool IsOutlierEliminationEnabled() const;
	virtual void SetOutlierEliminationEnabled(bool isOutlierEliminationEnabled = true);
	virtual double GetMinOutlierDistance() const;
	virtual void SetMinOutlierDistance(double minOutlierDistance);
	virtual int GetRaysCount() const;
	virtual void SetRaysCount(int raysCount);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	bool m_isOutlierEliminationEnabled;
	double m_minOutlierDistance;
	int m_raysCount;
	int m_caliperMode;
};


} // namespace iipr


#endif // !iipr_CCircleFinderParams_included


