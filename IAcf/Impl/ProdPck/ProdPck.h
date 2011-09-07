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


#ifndef ProdPck_included
#define ProdPck_included


// ACF includes
#include "imod/TModelWrap.h"
#include "icomp/TModelCompWrap.h"
#include "icomp/TMakeComponentWrap.h"

#include "icntl/CMultiLineParamsComp.h"
#include "icntl/CLineParamsComp.h"
#include "icntl/CInspectionUnitParamsComp.h"
#include "icntl/CEjectorParamsComp.h"


/**
	System-independent production control package.
*/
namespace ProdPck
{

typedef icomp::TModelCompWrap<icntl::CMultiLineParamsComp> MultiLineParams;
typedef icomp::TModelCompWrap<icntl::CLineParamsComp> LineParams;
typedef icomp::TModelCompWrap<icntl::CInspectionUnitParamsComp> InspectionUnitParams;
typedef icomp::TModelCompWrap<icntl::CEjectorParamsComp> EjectorParams;


} // namespace ProdPck


#endif // !ProdPck_included


