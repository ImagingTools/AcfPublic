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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
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


