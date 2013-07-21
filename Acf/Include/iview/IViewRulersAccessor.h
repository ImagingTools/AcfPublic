/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iview_IViewRulersAccessor_included
#define iview_IViewRulersAccessor_included


#include "istd/IPolymorphic.h"

#include "iview/IRuler.h"


namespace iview
{


/**
	Common interface for all view rulers provider.
	This interface allows you to get an access to left and top view ruler.
*/
class IViewRulersAccessor: virtual public istd::IPolymorphic
{
public:
	/**
		Get an access to left view ruler.
		\return	pointer to left ruler object, or NULL, when it is not accessible.
	*/
	virtual IRuler* GetLeftRulerPtr() = 0;
	
	/**
		Get an access to top view ruler.
		\return	pointer to top ruler object, or NULL, when it is not accessible.
	*/
	virtual IRuler* GetTopRulerPtr() = 0;
};


} // namespace iview


#endif // !iview_IViewRulersAccessor_included


