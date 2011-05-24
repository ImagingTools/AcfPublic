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


#ifndef icntl_IEjectorParams_included
#define icntl_IEjectorParams_included


// ACF includes
#include "istd/INamed.h"
#include "istd/IEnableable.h"
#include "iser/ISerializable.h"

#include "icntl/icntl.h"


namespace icntl
{


/**
	Parameters of single ejector.
*/
class IEjectorParams:
			virtual public iser::ISerializable,
			virtual public istd::INamed,
			virtual public istd::IEnableable
{
public:
	/**
		Get position of this ejector.
		This value is in physical units relative to abstract base position.
	*/
	virtual double GetEjectorPosition() const = 0;
	/**
		Set position of this ejector.
		This value is in physical units relative to abstract base position.
	*/
	virtual void SetEjectorPosition(double position) = 0;

	/**
		Get ejection distance.
		This value is in physical units relative to abstract base position.
	*/
	virtual double GetEjectionDistance() const = 0;
	/**
		Set ejection distance.
		This value is in physical units relative to abstract base position.
	*/
	virtual void SetEjectionDistance(double position) = 0;
};


} // namespace icntl


#endif // !icntl_IEjectorParams_included


