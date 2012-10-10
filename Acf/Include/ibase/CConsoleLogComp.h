/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef ibase_CConsoleLogComp_included
#define ibase_CConsoleLogComp_included


#include "ibase/CStreamLogCompBase.h"


namespace ibase
{


/**
	Message container displaying messages as log list.
*/
class CConsoleLogComp: public CStreamLogCompBase
{
public:
	typedef CStreamLogCompBase BaseClass;

	I_BEGIN_COMPONENT(CConsoleLogComp);
	I_END_COMPONENT;

protected:
	// reimplemented (CStreamLogCompBase)
	virtual void WriteText(const QString& text);
	virtual void NewLine();
};


} // namespace ibase


#endif // !ibase_CConsoleLogComp_included

