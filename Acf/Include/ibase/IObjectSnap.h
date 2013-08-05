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


#ifndef ibase_IObjectSnap_included
#define ibase_IObjectSnap_included


// ACF includes
#include "istd/IChangeable.h"
#include "istd/CIndex2d.h"
#include "iimg/IBitmap.h"


namespace ibase
{


/**
	Interface for getting a bitmap snap of any object.
*/
class IObjectSnap: virtual public istd::IPolymorphic
{
public:
	/**
		Get bitmap snap for the data object \c data.
	*/
	virtual bool GetSnap(
				const istd::IChangeable& data,
				iimg::IBitmap& objectSnap,
				const istd::CIndex2d& size) const = 0;
};


} // namespace ibase


#endif // !ibase_IObjectSnap_included


