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


