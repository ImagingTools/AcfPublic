/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iwin/CCriticalSection.h"


extern "C" BOOL _stdcall TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);	// TODO: try to find other work around


namespace iwin
{


CCriticalSection::CCriticalSection()
{
	::InitializeCriticalSection(&m_section);
}


CCriticalSection::~CCriticalSection()
{
	::DeleteCriticalSection(&m_section);
}


// reimplemented (isys::ICriticalSection)

void CCriticalSection::Enter()
{
	::EnterCriticalSection(&m_section);
}


bool CCriticalSection::EnterIfFree()
{
	BOOL status = ::TryEnterCriticalSection(&m_section);

	return status == TRUE;
}


void CCriticalSection::Leave()
{
	::LeaveCriticalSection(&m_section);
}


} // namespace iwin


