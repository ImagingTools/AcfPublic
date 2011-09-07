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


#ifndef icntl_IMultiLineController_included
#define icntl_IMultiLineController_included


// ACF includes
#include "istd/IPolymorphic.h"

#include "icntl/icntl.h"


namespace icntl
{


class ILineController;


/**
	Interfce to controlling set of production lines.
*/
class IMultiLineController: virtual public istd::IPolymorphic
{
public:
	/**
		Get number of lines in this multi line system.
	*/
	virtual int GetLinesCount() const = 0;

	/**
		Get access to single line using its index.
	*/
	virtual ILineController& GetLineController(int lineIndex) const = 0;
};


} // namespace icntl


#endif // !icntl_IMultiLineController_included


