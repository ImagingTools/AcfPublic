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


