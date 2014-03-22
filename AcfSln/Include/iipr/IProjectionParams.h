/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#ifndef iipr_IProjectionParams_included
#define iipr_IProjectionParams_included


#include "iser/ISerializable.h"


namespace iipr
{


class IProjectionConstraints;


/**
	Describe parameter for projection 2D image to 1D structure.
*/
class IProjectionParams: virtual public iser::ISerializable
{
public:
	/**
		Get access to constraints information about possible value ranges.
	*/
	virtual const IProjectionConstraints* GetProjectionConstraints() const = 0;

	/**
		Get width of projection line.
		Depending on interpretation this value can be in pixel or logical units.
		If this value is negative, smallest width is mean.
	*/
	virtual double GetLineWidth() const = 0;
	/**
		Set width of projection line.
		Depending on interpretation this \c width value can be in pixel or logical units.
		If \c width value is negative, smallest width is mean.
	*/
	virtual void SetLineWidth(double width) = 0;

	/**
		Get number of projection elements should be calculated by this projection.
		If returned value is negative, automatic size is mean.
	*/
	virtual int GetProjectionSize() const = 0;
	/**
		Set number of projection elements should be calculated by this projection.
		If \c size value is negative, automatic projction size is mean.
	*/
	virtual void SetProjectionSize(int size) = 0;
};


} // namespace iipr


#endif // !iipr_IProjectionParams_included


