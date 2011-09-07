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


#include "imil/CMilEngine.h"


namespace imil
{


// public methods

CMilEngine::CMilEngine()
{
	s_criticalSection.Enter();
	if (s_referenceCount == 0){
		MappAllocDefault(M_SETUP, &s_milApplication, &s_milSystemId, M_NULL, M_NULL, M_NULL);
	}
	s_referenceCount++;
	s_criticalSection.Leave();
}


CMilEngine::~CMilEngine()
{
	s_criticalSection.Enter();
	if (s_referenceCount == 1){
		MappFreeDefault(s_milApplication, s_milSystemId, M_NULL, M_NULL, M_NULL);
		s_milApplication = M_NULL;
		s_milSystemId = M_NULL;
	}
	s_referenceCount--;
	s_criticalSection.Leave();
}


MIL_ID CMilEngine::GetSystemId() const
{
	I_ASSERT(s_milSystemId != M_NULL);

	return s_milSystemId;
}


// private static members

MIL_ID CMilEngine::s_milSystemId = M_NULL;
MIL_ID CMilEngine::s_milApplication = M_NULL;
int CMilEngine::s_referenceCount = 0;
inat::CCriticalSection CMilEngine::s_criticalSection;


} // namespace imil


