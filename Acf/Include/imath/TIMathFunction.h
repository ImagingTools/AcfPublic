/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#ifndef imath_TIMathFunction_included
#define imath_TIMathFunction_included


#include <istd/IPolymorphic.h>


namespace imath
{


/**
	Template interface for any mathematical function.
*/
template <typename Argument, typename Result>
class TIMathFunction: virtual public istd::IPolymorphic
{
public:
	typedef Argument ArgumentType;
	typedef Result ResultType;

	/**
		Get function value for specified argument value.
		\param	argument	function argument.
		\param	result		function value for specified argument.
		\return	true if result was correctly calculated.
	*/
	virtual bool GetValueAt(const Argument& argument, Result& result) const = 0;
	/**
		Get function value for specified argument value.
		This overloaded menthod is provided only for convinence.
		\param	argument	function argument.
		\return				function value for specified argument.
	*/
	virtual Result GetValueAt(const Argument& argument) const = 0;
};


// standard templatization

typedef TIMathFunction<double, double> IDoubleFunction;


} // namespace imath


#endif // !imath_TIMathFunction_included


