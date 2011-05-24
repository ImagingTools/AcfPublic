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


#ifndef iipr_CSearchParams_included
#define iipr_CSearchParams_included


#include "iipr/ISearchParams.h"


namespace iipr
{


/**
	Definition of standard search parameters.
*/
class CSearchParams: virtual public iipr::ISearchParams
{
public:
	CSearchParams();
	
	// reimplemented (iipr::ISearchParams)
	virtual i2d::CRectangle GetSearchRegion() const;
	virtual double GetMinScore() const;
	virtual void SetMinScore(double minScore);
	virtual const istd::CRange& GetRotationRange() const;
	virtual void SetRotationRange(const istd::CRange& angleRange);
	virtual const istd::CRange& GetScaleRange() const;
	virtual void SetScaleRange(const istd::CRange& scaleRange);
	virtual int GetNominalModelsCount() const;
	virtual void SetNominalModelsCount(int nominalModelsCount);
	virtual bool IsRotationEnabled() const; 
	virtual void SetRotationEnabled(bool isRotationEnabled);
	virtual bool IsScaleEnabled() const;
	virtual void SetScaleEnabled(bool isScaleEnabled);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive & archive);

protected:
	i2d::CRectangle m_searchRegion;
	istd::CRange m_angleRange;
	istd::CRange m_scaleRange;
	int m_nominalModelsCount;
	double m_minScore;
	bool m_isRotationEnabled;
	bool m_isScaleEnabled;
};


} // namespace iipr


#endif // !iipr_CSearchParams_included


