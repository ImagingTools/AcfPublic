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


#ifndef iipr_IProjectionConstraints_included
#define iipr_IProjectionConstraints_included


#include "istd/IPolymorphic.h"
#include "istd/CRange.h"


namespace iipr
{


class IProjectionConstraints: virtual public istd::IPolymorphic
{
public:
	/**
		Get range of possible projection line width.
		If this range is invalid, no width setting is suported.
	*/
	virtual istd::CRange GetLineWidthRange() const = 0;

	/**
		Get minimal number of projection elements can be calculated by projection.
		If this value is bigger than returned by \c GetMaxProjectionSize() there is no fixed size supported.
	*/
	virtual int GetMinProjectionSize() const = 0;

	/**
		Get maximal number of projection elements can be calculated by projection.
		If this value is smaller than returned by \c GetMinProjectionSize() there is no fixed size supported.
	*/
	virtual int GetMaxProjectionSize() const = 0;

	/**
		Check if automatical projection size is supported.
	*/
	virtual bool IsAutoProjectionSizeSupported() const = 0;
};


} // namespace iipr


#endif // !iipr_IProjectionConstraints_included


