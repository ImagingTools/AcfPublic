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


#ifndef iipr_IMultidimensionalFilterConstraints_included
#define iipr_IMultidimensionalFilterConstraints_included


// ACF includes
#include "istd/IPolymorphic.h"

// ACF-Solutions includes
#include "imeas/IUnitInfo.h"

#include "iipr/iipr.h"


namespace iipr
{


class IMultidimensionalFilterConstraints: virtual public istd::IPolymorphic
{
public:
	/**
		Get number of dimensions will be filtered.
	*/
	virtual int GetFilterDimensionsCount() const = 0;

	/**
		Get description of some filter element.
	*/
	virtual istd::CString GetFilterDescription(int dimension) const = 0;

	/**
		Get range of possible filter value for specified dimension.
	*/
	virtual const imeas::IUnitInfo& GetFilterUnitInfo(int dimension) const = 0;
};


} // namespace iipr


#endif // !iipr_IMultidimensionalFilterConstraints_included


