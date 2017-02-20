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


#ifndef iproc_included
#define iproc_included


#include <ibase/ibase.h>


/**
	This namespace containes interfaces and implementation of data processing concepts.
	There are 2 main processing concepts:
	\li	asynchrone processing with <em>"push data"</em> model, where the caller controls life cycle of processed objects. It is represented by class iproc::IProcessor,
	\li	asynchrone processing with <em>"pull data" model</em>, where processing objects are global, undepend on processing session. It is represented by class iinsp::ISupplier.

	This package is system independent.
	This package use following ACF packages:
	\li	istd
	\li	iser
	\li	ibase
	\li	iprm
*/
namespace iproc
{


} // namespace iproc


#endif // !iproc_included

