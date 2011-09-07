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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iwin_CCriticalSection_included
#define iwin_CCriticalSection_included


#include "isys/ICriticalSection.h"

#include "iwin/iwin.h"

#include <windows.h>


namespace iwin
{


/**
	Realization of critical section on Windows.

	\ingroup Windows
*/
class CCriticalSection: virtual public isys::ICriticalSection
{
public:
	CCriticalSection();
	~CCriticalSection();

	// reimplemented (isys::ICriticalSection)
	virtual void Enter();
	virtual bool EnterIfFree();
	virtual void Leave();

private:
	CRITICAL_SECTION m_section;
};


} // namespace iwin


#endif // !iwin_CCriticalSection_included


