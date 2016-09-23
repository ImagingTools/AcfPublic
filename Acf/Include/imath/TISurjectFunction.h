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


#ifndef imath_TISurjectFunction_included
#define imath_TISurjectFunction_included


#include <imath/TIMathFunction.h>


namespace imath
{


/**
	Template interface for any surjective mathematical function.
	A function is surjective if for every y in the codomain Y
	there is at least one x in the domain X such that f(x) = y.
*/
template <typename Argument, typename Result>
class TISurjectFunction: virtual public TIMathFunction<Argument, Result>
{
public:
	/**
		Get inverted function value.
		\param	argument	function argument.
		\param	result		function value for specified argument.
		\return	true if result was correctly calculated.
	*/
	virtual bool GetInvValueAt(const Result& argument, Argument& result) const = 0;
	/**
		Get inverted function value.
		This overloaded menthod is provided only for convinence.
		\param	argument	function argument.
		\return				function value for specified argument.
	*/
	virtual Argument GetInvValueAt(const Result& argument) const = 0;
};


// standard templatization

typedef TISurjectFunction<double, double> ISurjectDoubleFunction;


} // namespace imath


#endif // !imath_TISurjectFunction_included


