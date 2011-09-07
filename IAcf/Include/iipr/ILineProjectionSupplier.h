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


