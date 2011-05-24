/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
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


