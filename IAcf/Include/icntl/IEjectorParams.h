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


