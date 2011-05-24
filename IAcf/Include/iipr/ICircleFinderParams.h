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


