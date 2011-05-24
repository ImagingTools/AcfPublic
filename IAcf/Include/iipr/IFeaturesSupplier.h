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


#ifndef iipr_IFeaturesSupplier_included
#define iipr_IFeaturesSupplier_included


// ACF includes
#include "iproc/ISupplier.h"

#include "iipr/IFeaturesContainer.h"


namespace iipr
{


class IFeaturesSupplier: virtual public iproc::ISupplier
{
public:
	/**
		Get access to produced features container.
		\return	pointer to the feature container if this was correctly produced, or NULL.
	*/
	virtual const iipr::IFeaturesContainer* GetFeatures() const = 0;
};


} // namespace iipr


#endif // !iipr_IFeaturesSupplier_included

