/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#ifndef iinsp_ITimeStampProvider_included
#define iinsp_ITimeStampProvider_included


// ACF includes
#include <istd/IChangeable.h>
#include <istd/ITimeStamp.h>


namespace iinsp
{


/**
	Interface allowing to retrieve a current time stamp.
*/
class ITimeStampProvider: virtual public istd::IChangeable
{
public:
	/**
		Get current processing the time stamp.
		\return	timer representing time stamp or NULL if it is impossible to retrive it.
	*/
	virtual const istd::ITimeStamp* GetCurrentTimeStamp() const = 0;
};


} // namespace iinsp


#endif // !iinsp_ITimeStampProvider_included


