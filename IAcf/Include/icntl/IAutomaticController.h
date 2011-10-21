/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
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


