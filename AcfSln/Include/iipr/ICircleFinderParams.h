/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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


#ifndef iipr_ICircleFinderParams_included
#define iipr_ICircleFinderParams_included


#include "iser/ISerializable.h"

#include "iipr/iipr.h"


namespace iipr
{


/**
	Interface for the circle finder parameter.
*/
class ICircleFinderParams: virtual public iser::ISerializable
{
public:
	
	/**
		Caliper mode. Control, which caliper is used for the circle calculation.
	*/
	enum CaliperMode
	{
		/**
			The first found caliper is taked for circle calculation.
		*/
		CCM_FIRST,

		/**
			The best found caliper is taked for circle calculation.
		*/	
		CCM_BEST
	};


	/**
		Get caliper mode.
		\sa CaliperMode
	*/
	virtual int GetCaliperMode() const = 0;
	
	/**
		Set caliper mode.
		\sa CaliperMode
	*/
	virtual void SetCaliperMode(int caliperMode) = 0;

	/**
		Return \c true, if the outlier elimination is activated.
	*/
	virtual bool IsOutlierEliminationEnabled() const = 0;

	/**
		Enable the outlier elimination.
	*/
	virtual void SetOutlierEliminationEnabled(bool isOutlierEliminationEnabled = true) = 0;

	/**
		Get the minimal outlier distance.
	*/
	virtual double GetMinOutlierDistance() const = 0;

	/**
		Set minimal outlier distance
	*/
	virtual void SetMinOutlierDistance(double minOutlierDistance) = 0;

	/**
		Get the number of projection rays using for the find the circle points.
	*/
	virtual int GetRaysCount() const = 0;

	/**
		Set the number of projection rays using for the find the circle points.
	*/
	virtual void SetRaysCount(int raysCount) = 0;
};


} // namespace iipr


#endif // !iipr_ICircleFinderParams_included


