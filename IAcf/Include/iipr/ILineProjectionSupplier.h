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


#ifndef iipr_ILineProjectionSupplier_included
#define iipr_ILineProjectionSupplier_included


// ACF includes
#include "iproc/ISupplier.h"

// ACF-Solutions includes
#include "imeas/IDataSequence.h"

#include "iipr/iipr.h"


namespace iipr
{


/**
	Image line projection supplier.
*/
class ILineProjectionSupplier: virtual public iproc::ISupplier
{
public:
	/**
		Get access to produced line projection object.
	*/
	virtual const imeas::IDataSequence* GetLineProjection() const = 0;
};


} // namespace iipr


#endif // !iipr_ILineProjectionSupplier_included


