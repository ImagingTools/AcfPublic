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


#ifndef iipr_IProjectionConstraints_included
#define iipr_IProjectionConstraints_included


#include <istd/IPolymorphic.h>
#include <istd/TRange.h>


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


