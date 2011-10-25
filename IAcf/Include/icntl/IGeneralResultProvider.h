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


#ifndef icntl_IGeneralResultProvider_included
#define icntl_IGeneralResultProvider_included


// ACF includes
#include "istd/IChangeable.h"


namespace icntl
{


/**
	Provide general inspection result.
*/
class IGeneralResultProvider: virtual public istd::IChangeable
{
public:
	enum GeneralResult
	{
		GR_OK,
		GR_WARNING,
		GR_FAILED,
		GR_CRITICAL
	};

	virtual GeneralResult GetGeneralResult() const = 0;
};


} // namespace icntl


#endif // !icntl_IGeneralResultProvider_included


