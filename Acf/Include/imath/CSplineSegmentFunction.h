/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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


#ifndef imath_CSplineSegmentFunction_included
#define imath_CSplineSegmentFunction_included


namespace imath
{


/**
	Helper class for calculation of splines of 3rd degree.
*/
class CSplineSegmentFunction
{
public:
	// static methods
	/**
		Get kernel of value normalized to range [0, 1].
	*/
	static double GetValueKernelAt(double alpha);
	/**
		Get kernel of derivative normalized to range [0, 1].
	*/
	static double GetDerivativeKernelAt(double alpha);
};


// static protected inline methods

inline double CSplineSegmentFunction::GetValueKernelAt(double alpha)
{
	return (2 * alpha - 3) * alpha * alpha + 1;
}


inline double CSplineSegmentFunction::GetDerivativeKernelAt(double alpha)
{
	double beta = 1 - alpha;
	return alpha * beta * beta;
}


} // namespace imath


#endif // !imath_CSplineSegmentFunction_included


