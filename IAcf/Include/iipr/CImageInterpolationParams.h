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


#ifndef iipr_CImageInterpolationParams_included
#define iipr_CImageInterpolationParams_included


// IACF includes
#include "iipr/IImageInterpolationParams.h"


namespace iipr
{


/**
	Common interace for interpolation parameters
*/
class CImageInterpolationParams: virtual public iipr::IImageInterpolationParams
{
public:
	CImageInterpolationParams();

	// reimplemented (iipr::IImageInterpolationParams)
	virtual int GetInterpolationMode() const;
	virtual void SetInterpolationMode(int interpolationMode);
	
	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	int m_interpolationMode;
};


} // namespace iipr


#endif // !iipr_CImageInterpolationParams_included


