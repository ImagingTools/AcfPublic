/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef iinsp_IConsumer_included
#define iinsp_IConsumer_included


// ACF includes
#include <istd/IChangeable.h>
#include <iinsp/ISupplier.h>


namespace iinsp
{


/**
	Base interface for consumers accepting suppliers.
*/
class IConsumer: virtual public istd::IChangeable
{
public:
	virtual void AcceptSupplier(const ISupplier* supplier) = 0;
};


} // namespace iinsp


#endif // !iinsp_IConsumer_included


