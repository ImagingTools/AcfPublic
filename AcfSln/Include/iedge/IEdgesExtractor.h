/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#ifndef iedge_IEdgesExtractor_included
#define iedge_IEdgesExtractor_included


// ACF includes
#include "iimg/IBitmap.h"
#include "iproc/IProcessor.h"

// ACF-Solutions includes
#include "iedge/CEdgeLineContainer.h"


namespace iedge
{


/**
	Interface for edge lines extraction from the image.
*/
class IEdgesExtractor: virtual public iproc::IProcessor
{
public:
	/**
		Do extraction of set of edge lines found on the image.
		\param	bitmap		image where the contour lines should be extracted.
		\param	result		container of result edges lines.
		\return				true if success.
	*/
	virtual bool DoContourExtraction(
				const iprm::IParamsSet* paramsPtr,
				const iimg::IBitmap& bitmap,
				CEdgeLineContainer& result) const = 0;
};


} // namespace iedge


#endif // !iedge_IEdgesExtractor_included


