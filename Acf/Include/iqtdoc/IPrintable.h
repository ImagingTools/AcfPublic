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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqtdoc_IPrintable_included
#define iqtdoc_IPrintable_included


// Qt includes
#include <QPrinter>


// ACF includes
#include "istd/IPolymorphic.h"

#include "iqtdoc/iqtdoc.h"


namespace iqtdoc
{


/**
	Common interface for printable objects.
*/
class IPrintable: virtual public istd::IPolymorphic
{
public:
	/**
		Print some contents to the printer \c printer.
		Printer object is already initialized from framework.
	*/
	virtual void Print(QPrinter* printerPtr) const = 0;
};


} // namespace iqtdoc


#endif // !iqtdoc_IPrintable_included


