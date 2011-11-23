/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iprm_IEnableableParam_included
#define iprm_IEnableableParam_included


#include "iser/ISerializable.h"


namespace iprm
{


/**
	Interface for objects which can be enabled/disabled.	
*/
class IEnableableParam: virtual public iser::ISerializable
{
public:
	/**
		Return a \c true, if something is enabled.
	*/
	virtual bool IsEnabled() const = 0;

	/**
		Return a \c true, if something can be enabled.
	*/
	virtual bool IsEnablingAllowed() const = 0;

	/**
		Set something to \c isEnabled state.
	*/
	virtual void SetEnabled(bool isEnabled = true) = 0;

};


} // namespace iprm


#endif // !iprm_IEnableableParam_included


