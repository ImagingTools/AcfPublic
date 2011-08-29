/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef imeas_INumericParams_included
#define imeas_INumericParams_included


#include "iser/ISerializable.h"

#include "imath/CVarVector.h"


namespace imeas
{


class INumericConstraints;


class INumericParams: virtual public iser::ISerializable
{
public:
	/**
		Get parameter constraints describing possible parameter values.
	*/
	virtual const INumericConstraints* GetNumericConstraints() const = 0;

	/**
		Get filter length for each dimension.
	*/
	virtual imath::CVarVector GetValues() const = 0;

	/**
		Set filter length for each dimension.
	*/
	virtual bool SetValues(const imath::CVarVector& lengths) = 0;
};


} // namespace imeas


#endif // !imeas_INumericParams_included


