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


#ifndef iipr_IISearchParamsConstraints_included
#define iipr_IISearchParamsConstraints_included


#include <istd/IChangeable.h>
#include <istd/TRange.h>


namespace iipr
{


/**	
	Interface for search algorithm limitations.
*/
class ISearchConstraints: virtual public istd::IChangeable
{
public:
	/**
		List of flags for supported options.
		This flags can be binary combined.
	*/
	enum SearchSupportedFlags
	{
		SSF_NONE = 0,
		/**
			Translation is supported by model search.
		*/
		SSF_TRANSLATION = 1 << 0,
		/**
			Rotation is supported by model search.
		*/
		SSF_ROTATION = 1 << 1,
		/**
			Scaling is supported by model search.
		*/
		SSF_SCALING = 1 << 2,
		/**
			More than one result is supported.
		*/
		SSF_MULTIPLE_RESULTS = 1 << 3,
		/**
			Quality score threshold is supported.
		*/
		SSF_SCORE_THRESHOLD = 1 << 4
	};

	/**
		Get set of supported options.
	*/
	virtual int GetSearchSupportedFlags() const = 0;
	/**
		Get boundaries of rotation range.
	*/
	virtual const istd::CRange& GetRotationRangeConstraints() const = 0;
	/**
		Get boundaries of scaling range.
	*/
	virtual const istd::CRange& GetScaleRangeConstraints() const = 0;
	/**
		Get boundaries of result count.
	*/
	virtual const istd::CIntRange& GetResultsCountConstraints() const = 0;
};


} // namespace iipr


#endif // !iipr_IISearchParamsConstraints_included

