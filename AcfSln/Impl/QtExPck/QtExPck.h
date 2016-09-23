/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef QtExPck_included
#define QtExPck_included


#include <icomp/TModelCompWrap.h>
#include <icomp/TMakeComponentWrap.h>

#include <iqtex/CTcpTerminalGuiComp.h>
#include <iqtex/CXslSerializerComp.h>

#include <iservice/CServiceApplicationComp.h>


/**
	Qt package with extended untipical components.
*/
namespace QtExPck
{


typedef iqtex::CTcpTerminalGuiComp TcpTerminalGui;
typedef iqtex::CXslSerializerComp XslFileSerializer;
typedef iservice::CServiceApplicationComp ServiceApplication;


} // namespace QtExPck


#endif // !QtExPck_included


