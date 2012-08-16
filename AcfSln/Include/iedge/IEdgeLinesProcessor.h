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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iedge_IEdgeLinesProcessor_included
#define iedge_IEdgeLinesProcessor_included


// ACF includes
#include "iproc/IProcessor.h"

// ACF-Solutions includes
#include "iedge/CEdgeLine.h"


namespace iedge
{


/**
	Interface for edge lines processing.
*/
class IEdgeLinesProcessor: virtual public iproc::IProcessor
{
public:
	/**
		Process set of edge lines to another set of edge lines.
		\param	edgeLines	set of edge lines used as input.
		\param	result		container of result edges lines.
		\return				true if success.
	*/
	virtual bool DoLinesProcessing(
				const iprm::IParamsSet* paramsPtr,
				const CEdgeLine::Container& edgeLines,
				CEdgeLine::Container& result) const = 0;
};


} // namespace iedge


#endif // !iedge_IEdgeLinesProcessor_included


