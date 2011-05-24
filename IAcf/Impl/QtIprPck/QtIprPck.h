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


#ifndef QtIprPck_included
#define QtIprPck_included


// ACF includes
#include "icomp/TModelCompWrap.h"
#include "icomp/TMakeComponentWrap.h"

#include "iqtipr/CMultidimensionalFilterParamsGuiComp.h"
#include "iqtipr/CSearchGuiComp.h"
#include "iqtipr/CSearchParamsGuiComp.h"
#include "iqtipr/CValueSupplierGuiComp.h"
#include "iqtipr/CCaliperParamsGuiComp.h"
#include "iqtipr/CLineProjectionSupplierGuiComp.h"
#include "iqtipr/CCircleFinderParamsGuiComp.h"


/**
	Standard package of Qt related implementations for image processing.
*/
namespace QtIprPck
{


typedef iqtipr::CMultidimensionalFilterParamsGuiComp RectangularFilterParamsGui;
typedef iqtipr::CSearchGuiComp SearchGui;
typedef iqtipr::CSearchParamsGuiComp SearchParamsGui;
typedef iqtipr::CValueSupplierGuiComp ValueSupplierGui;
typedef iqtipr::CCaliperParamsGuiComp CaliperParamsGui;
typedef iqtipr::CLineProjectionSupplierGuiComp LineProjectionSupplierGui;
typedef iqtipr::CCircleFinderParamsGuiComp CircleFinderParamsGui;



} // namespace QtIprPck


#endif // !QtIprPck_included


