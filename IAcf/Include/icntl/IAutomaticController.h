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


#ifndef icntl_IAutomaticController_included
#define icntl_IAutomaticController_included


// ACF includes
#include "istd/IChangeable.h"


namespace icntl
{


/**
	Allows to control working mode of control system.
*/
class IAutomaticController: virtual public istd::IChangeable
{
public:
	enum WorkMode
	{
		WM_NONE,
		WM_MANUAL,
		WM_AUTOMATIC
	};

	/**
		Check if automatic is on.
	*/
	virtual int GetWorkMode() const = 0;
	/**
		Set automatic on or off.
		\return	true if automatic mode was switched to specified.
	*/
	virtual bool SetWorkMode(int mode) = 0;
	/**
		Check if some work mode is supported.
	*/
	virtual bool IsModeSupported(int mode) const = 0;
};


} // namespace icntl


#endif // !icntl_IAutomaticController_included


