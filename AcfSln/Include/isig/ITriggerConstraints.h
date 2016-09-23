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


#ifndef isig_ITriggerConstraints_included
#define isig_ITriggerConstraints_included


#include <istd/IPolymorphic.h>


namespace isig
{


/**
	Interface for AVT camera parameters.
*/
class ITriggerConstraints: virtual public istd::IPolymorphic
{
public:
	/**
		Check if specified trigger mode is supported.
		Default mode should be always supported.
		Normal trigger modes are defined in \c isig::ITriggerParams::TriggerMode.
	*/
	virtual bool IsTriggerModeSupported(int triggerMode) const = 0;
};


} // namespace isig


#endif // !isig_ITriggerConstraints_included


