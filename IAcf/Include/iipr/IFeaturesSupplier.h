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

