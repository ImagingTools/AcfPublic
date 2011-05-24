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


#ifndef iipr_CGaussian2dFilterParams_included
#define iipr_CGaussian2dFilterParams_included


#include "iser/ISerializable.h"


namespace iipr
{


/**
	Basic implementation for the local operators with a rectangular kernel
*/
class CGaussian2dFilterParams: virtual public iser::ISerializable
{
public:
	CGaussian2dFilterParams();

	virtual double GetSigma1() const;
	virtual void SetSigma1(double sigma1);
	virtual double GetSigma2() const;
	virtual void SetSigma2(double sigma2);
	virtual double GetAngle() const;
	virtual void SetAngle(double sigma1);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	double m_sigma1;
	double m_sigma2;
	double m_angle;
};


} // namespace iipr


#endif // !iipr_CGaussian2dFilterParams_included

