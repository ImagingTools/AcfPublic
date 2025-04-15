/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#ifndef iipr_CCircleFinderParams_included
#define iipr_CCircleFinderParams_included


#include <iipr/ICircleFinderParams.h>


namespace iipr
{


class CCircleFinderParams: virtual public ICircleFinderParams
{
public:
	CCircleFinderParams();

	// reimplemented (iipr::ICircleFinderParams)
	virtual int GetCaliperMode() const override;
	virtual void SetCaliperMode(int caliperMode) override;
	virtual bool IsOutlierEliminationEnabled() const override;
	virtual void SetOutlierEliminationEnabled(bool isOutlierEliminationEnabled = true) override;
	virtual double GetMinOutlierDistance() const override;
	virtual void SetMinOutlierDistance(double minOutlierDistance) override;
	virtual const imath::IUnitInfo* GetDistanceUnitInfo() const override;
	virtual int GetRaysCount() const override;
	virtual void SetRaysCount(int raysCount) override;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive) override;

private:
	bool m_isOutlierEliminationEnabled;
	double m_minOutlierDistance;
	int m_raysCount;
	int m_caliperMode;
};


} // namespace iipr


#endif // !iipr_CCircleFinderParams_included


