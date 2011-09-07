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


#ifndef imil_CMilEngine_included
#define imil_CMilEngine_included


#include "imil/imil.h"


#include "inat/CCriticalSection.h"


namespace imil
{


class CMilEngine
{
public:
	CMilEngine();
	~CMilEngine();

	MIL_ID GetSystemId() const;

private:
	static inat::CCriticalSection s_criticalSection;
	static MIL_ID s_milSystemId;
	static MIL_ID s_milApplication;
	static int s_referenceCount;
};


} // namespace imil


#endif // !imil_CMilEngine_included


