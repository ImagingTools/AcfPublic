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


#ifndef iorn_included
#define iorn_included


#include "istd/istd.h"
#include "icomp/icomp.h"


/**
	Library containing core of concept of Witold Gantzkes 'objectron'.
	Objectron is something like layer in neural network, it has similiar behaviuor on interface level.
	It means objectron has input vector and output. It can calculate the output from input.
	It can be leaned self-associative or based on teached learning - it depends on implementation.
	The main difference to ANN is that objectron defines no assumption about internal realisation of this interface.
	It means classic algebraic realisation can be used, some recursive combinations of slave objectrons etc.
*/
namespace iorn
{


} // namespace iorn


#endif // !iorn_included

