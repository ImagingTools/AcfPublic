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


#ifndef MePck_included
#define MePck_included


// ACF includes
#include "icomp/TModelCompWrap.h"
#include "icomp/TMakeComponentWrap.h"

#include "CMeilhausSimpleComp.h"
#include "CChannelAddressParamComp.h"



/**
	Package for components depending on I/O component of Meilhaus GmbH company.
*/
namespace MePck
{


typedef imebase::CMeilhausSimpleComp MeilhausSimpleAcquisition;
typedef icomp::TModelCompWrap<imebase::CChannelAddressParamComp> ChannelAddressParam;


} // namespace MePck


#endif // !MePck_included


