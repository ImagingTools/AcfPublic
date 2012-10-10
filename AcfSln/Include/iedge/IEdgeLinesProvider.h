/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iedge_IEdgeLinesProvider_included
#define iedge_IEdgeLinesProvider_included


// ACF includes
#include "istd/IChangeable.h"

// ACF-Solutions includes
#include "iedge/CEdgeLine.h"


namespace iedge
{


class IEdgeLinesProvider: virtual public istd::IChangeable
{
public:
	/**
		Provide access to container of endges.
		\return contour container containing set of contours or NULL if no contours are available.
	*/
	virtual const CEdgeLine::Container* GetEdgesContainer() const = 0;
};


} // namespace iedge


#endif // !iedge_IEdgeLinesProvider_included


