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


#ifndef iipr_TFeatureWrap_included
#define iipr_TFeatureWrap_included


#include "iipr/CFeatureBase.h"


namespace iipr
{


/**
	Wrapper allowing to create feature object from some another serializable one.
*/
template <class BaseObject>
class TFeatureWrap:
			public CFeatureBase,
			public BaseObject
{
public:
	typedef CFeatureBase BaseClass;
	typedef BaseObject BaseClass2;

	TFeatureWrap(double weight = 1.0);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);
};


// public methods

template <class BaseObject>
TFeatureWrap<BaseObject>::TFeatureWrap(double weight)
:	BaseClass(weight)
{
}


// reimplemented (iser::ISerializable)

template <class BaseObject>
bool TFeatureWrap<BaseObject>::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	retVal = retVal && BaseClass::Serialize(archive);
	retVal = retVal && BaseClass2::Serialize(archive);

	return retVal;
}


} // namespace iipr


#endif // !iipr_TFeatureWrap_included


