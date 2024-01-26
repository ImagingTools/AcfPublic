/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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


#ifndef icmm_CXyzToCieLabTransformation_included
#define icmm_CXyzToCieLabTransformation_included


// ACF includes
#include <icmm/IColorTransformation.h>


namespace icmm
{


/**
	Implementation of XYZ-to-CIE-Lab color transformation.
	2° Observer and D65-illumination are used.
*/
class CXyzToCieLabTransformation: public icmm::IColorTransformation
{
public:
	// reimplemented (icmm::IColorTransformation)
	virtual bool GetValueAt(const icmm::CVarColor& argument, icmm::CVarColor& result) const;
	virtual icmm::CVarColor GetValueAt(const icmm::CVarColor& argument) const;
};


} // namespace icmm


#endif // !icmm_CXyzToCieLabTransformation_included


