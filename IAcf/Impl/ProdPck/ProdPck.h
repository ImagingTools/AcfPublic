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


