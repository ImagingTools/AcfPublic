/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
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

