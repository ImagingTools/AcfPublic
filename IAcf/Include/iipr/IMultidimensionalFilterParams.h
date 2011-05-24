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


#ifndef iipr_IMultidimensionalFilterParams_included
#define iipr_IMultidimensionalFilterParams_included


#include "iser/ISerializable.h"

#include "imath/CVarVector.h"


namespace iipr
{


class IMultidimensionalFilterConstraints;


class IMultidimensionalFilterParams: virtual public iser::ISerializable
{
public:
	/**
		Get parameter constraints describing possible parameter values.
	*/
	virtual const IMultidimensionalFilterConstraints* GetConstraints() const = 0;

	/**
		Get filter length for each dimension.
	*/
	virtual imath::CVarVector GetFilterLengths() const = 0;

	/**
		Set filter length for each dimension.
	*/
	virtual bool SetFilterLengths(const imath::CVarVector& lengths) = 0;
};


} // namespace iipr


#endif // !iipr_IMultidimensionalFilterParams_included


