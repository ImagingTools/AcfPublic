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


#ifndef iipr_CCaliperParams_included
#define iipr_CCaliperParams_included


#include "iipr/ICaliperParams.h"


namespace iipr
{


class CCaliperParams: virtual public ICaliperParams
{
public:
	CCaliperParams();

	// reimplemented (iipr::ICaliperParams)
	virtual double GetWeightThreshold() const;
	virtual void SetWeightThreshold(double threshold);
	virtual int GetPolarityMode() const;
	virtual void SetPolarityMode(int mode);
	virtual int GetDirectionMode() const;
	virtual void SetDirectionMode(int mode);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	double m_weightThreshold;
	int m_polarityMode;
	int m_directionMode;
};


} // namespace iipr


#endif // !iipr_CCaliperParams_included


