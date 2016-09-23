/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef inat_included
#define inat_included


#ifdef _WIN32
#include <iwin/iwin.h>
#else
#include <iqt/iqt.h>
#endif


/**
	This namespace contains implementations for the compile-time native plattform
*/
namespace inat
{


#ifdef _WIN32
	using namespace iwin;
#else
	using namespace iqt;
#endif


} // namespace inat


#endif // !inat_included
