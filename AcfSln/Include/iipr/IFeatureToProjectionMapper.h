/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef iipr_IFeatureToProjectionMapper_included
#define iipr_IFeatureToProjectionMapper_included


// ACF includes
#include <i2d/CVector2d.h>
#include <iprm/IParamsSet.h>


namespace imeas
{
	class INumericValue;
}


namespace iipr
{


/**
	Interface allowing mapping of extracted features to native coordinate systems.
*/
class IFeatureToProjectionMapper: virtual public istd::IPolymorphic
{
public:
	/**
		Get position on projection using position extracted from projection.
	*/
	virtual bool GetProjectionPosition(
				const imeas::INumericValue& feature,
				const iprm::IParamsSet* paramsPtr,
				double& result) const = 0;
};


} // namespace iipr


#endif // !iipr_IFeatureToProjectionMapper_included


