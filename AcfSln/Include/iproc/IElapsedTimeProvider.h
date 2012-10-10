/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iproc_IElapsedTimeProvider_included
#define iproc_IElapsedTimeProvider_included


#include "istd/IChangeable.h"


namespace iproc
{


/**
	Provider of the elapsed time
	E.g. used for processing time measuring.
*/
class IElapsedTimeProvider: virtual public istd::IChangeable
{
public:
	/**
		Get the elapsed time.
	*/
	virtual double GetElapsedTime() const = 0;
};


} // namespace iproc


#endif // !iproc_IElapsedTimeProvider_included


