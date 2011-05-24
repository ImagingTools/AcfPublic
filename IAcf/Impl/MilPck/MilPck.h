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


#ifndef MilPck_included
#define MilPck_included


// ACF includes
#include "icomp/TModelCompWrap.h"
#include "icomp/TMakeComponentWrap.h"

#include "imil/CMilSearchParamsGuiComp.h"
#include "imil/CMilSearchProcessorComp.h"


/**
	MIL package.
*/
namespace MilPck
{


typedef imil::CMilSearchParamsGuiComp MilSearchParamsGui;
typedef icomp::TMakeComponentWrap<imod::TModelWrap<imil::CMilSearchParams>, iser::ISerializable, iipr::ISearchParams> MilSearchParams;
typedef imil::CMilSearchProcessorComp MilSearchProcessor;


} // namespace MilPck


#endif // !MilPck_included


