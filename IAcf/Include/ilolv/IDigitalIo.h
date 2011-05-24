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


#ifndef ilolv_IDigitalIo_included
#define ilolv_IDigitalIo_included


#include "istd/IPolymorphic.h"

#include "ilolv/ilolv.h"


namespace ilolv
{


class IDigitalIo: virtual public istd::IPolymorphic
{
public:
	virtual I_DWORD GetInputBits() const = 0;
	virtual void SetOutputBits(I_DWORD value, I_DWORD mask) = 0;
};


} // namespace ilolv


#endif // !ilolv_IDigitalIo_included


