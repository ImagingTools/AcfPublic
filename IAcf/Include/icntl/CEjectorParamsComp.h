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


#ifndef icntl_CEjectorParamsComp_included
#define icntl_CEjectorParamsComp_included


// ACF includes
#include "icomp/CComponentBase.h"
#include "ibase/TEnableableWrap.h"
#include "ibase/TNamedWrap.h"

#include "icntl/IEjectorParams.h"


namespace icntl
{


/**
	Component implementation of single ejector parameters.
*/
class CEjectorParamsComp:
			public icomp::CComponentBase,
			public ibase::TEnableableWrap<ibase::TNamedWrap<IEjectorParams> >
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CEjectorParamsComp);
		I_REGISTER_INTERFACE(IEjectorParams);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(istd::IEnableable);
		I_REGISTER_INTERFACE(istd::INamed);
		I_REGISTER_INTERFACE(istd::IChangeable);

		I_ASSIGN(m_nameAttrPtr, "Name", "Name", true, "");
		I_ASSIGN(m_isEnabledAttrPtr, "IsEnabled", "Is function enabled", true, true);
		I_ASSIGN(m_ejectorPositionAttrPtr, "EjectorPosition", "Position of ejector in logical units", true, 1000);
		I_ASSIGN(m_ejectionDistanceAttrPtr, "EjectionDistance", "Distance of ejection in logical units", true, 50);
	I_END_COMPONENT;

	CEjectorParamsComp();

	// reimplemented (icntl::IEjectorParams)
	virtual double GetEjectorPosition() const;
	virtual void SetEjectorPosition(double position);
	virtual double GetEjectionDistance() const;
	virtual void SetEjectionDistance(double distance);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(istd::CString, m_nameAttrPtr);
	I_ATTR(bool, m_isEnabledAttrPtr);
	I_ATTR(double, m_ejectorPositionAttrPtr);
	I_ATTR(double, m_ejectionDistanceAttrPtr);

	double m_ejectorPosition;
	double m_ejectionDistance;
};


} // namespace icntl


#endif // !icntl_CEjectorParamsComp_included


