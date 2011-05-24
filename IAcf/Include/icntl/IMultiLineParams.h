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


#ifndef icntl_IMultiLineParams_included
#define icntl_IMultiLineParams_included


// ACF includes
#include "istd/INamed.h"
#include "iser/ISerializable.h"

#include "icntl/icntl.h"


namespace icntl
{


class ILineParams;


class IMultiLineParams:
			virtual public iser::ISerializable,
			virtual public istd::INamed
{
public:
	/**
		Get number of lines in this multi line system.
	*/
	virtual int GetLinesCount() const = 0;

	/**
		Get access to single line using its index.
	*/
	virtual ILineParams& GetLineParams(int lineIndex) const = 0;
};


} // namespace icntl


#endif // !icntl_IMultiLineParams_included


