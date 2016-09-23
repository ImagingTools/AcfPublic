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


#ifndef imeas_ILinearAdjustParams_included
#define imeas_ILinearAdjustParams_included


#include <iser/ISerializable.h>


namespace imeas
{


class ILinearAdjustConstraints;


/**
	Get parameter of linear adjust.
	Linear adjust is simple linear transformation in form y = x * scale + offset.
*/
class ILinearAdjustParams: virtual public iser::ISerializable
{
public:
	/**
		Get access to constraints object.
		This object describes for example range of possible parameter values.
	*/
	virtual const ILinearAdjustConstraints* GetAdjustConstraints() const = 0;

	/**
		Get value of scale factor.
	*/
	virtual double GetScaleFactor() const = 0;

	/**
		Set value of scale factor.
	*/
	virtual void SetScaleFactor(double scale) = 0;

	/**
		Get value of offset factor.
	*/
	virtual double GetOffsetFactor() const = 0;

	/**
		Set value of offset factor.
	*/
	virtual void SetOffsetFactor(double offset) = 0;
};


} // namespace imeas


#endif // !imeas_ILinearAdjustParams_included


