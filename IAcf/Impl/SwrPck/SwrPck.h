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


#ifndef SwrPck_included
#define SwrPck_included


// ACF includes
#include "icomp/TModelCompWrap.h"
#include "icomp/TMakeComponentWrap.h"

#include "iswr/CSwissRangerAcquisitionComp.h"
#include "iswr/CSwissRangerParams.h"
#include "iswr/CSwissRangerParamsComp.h"
#include "iswr/CSwissRangerAcquisitionData.h"


/**
	SwissRanger-specific package.
*/
namespace SwrPck
{


typedef iswr::CSwissRangerAcquisitionComp SwissRangerAcquisition;
typedef icomp::TModelCompWrap<
			icomp::TMakeComponentWrap<
						iswr::CSwissRangerParams, 
						iswr::ISwissRangerParams, 
						iser::ISerializable> > SwissRangerParams;

typedef icomp::TModelCompWrap<iswr::CSwissRangerParamsComp> AttributedSwissRangerParams;

typedef icomp::TModelCompWrap<
			icomp::TMakeComponentWrap<
						iswr::CSwissRangerAcquisitionData, 
						iswr::ISwissRangerAcquisitionData, 
						iser::ISerializable> > SwissRangerAcquisitionData;


} // namespace SwrPck


#endif // !SwrPck_included


