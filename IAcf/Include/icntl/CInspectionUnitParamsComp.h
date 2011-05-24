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


#ifndef icntl_CInspectionUnitParamsComp_included
#define icntl_CInspectionUnitParamsComp_included


// ACF includes
#include "icomp/CComponentBase.h"
#include "ibase/TEnableableWrap.h"
#include "ibase/TNamedWrap.h"

#include "icntl/IInspectionUnitParams.h"


namespace icntl
{


/**
	Parameters of single inspection unit.
*/
class CInspectionUnitParamsComp:
			public icomp::CComponentBase,
			public ibase::TEnableableWrap<ibase::TNamedWrap<IInspectionUnitParams> >
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CInspectionUnitParamsComp);
		I_REGISTER_INTERFACE(IInspectionUnitParams);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(istd::IEnableable);
		I_REGISTER_INTERFACE(istd::INamed);
		I_REGISTER_INTERFACE(istd::IChangeable);

		I_ASSIGN(m_nameAttrPtr, "Name", "Name", true, "");
		I_ASSIGN(m_isEnabledAttrPtr, "IsEnabled", "Is function enabled", true, true);
		I_ASSIGN(m_triggerOffsetAttrPtr, "TriggerOffset", "Distance between light barrier trigger and real trigger position", true, 0);
		I_ASSIGN(m_triggerAlphaAttrPtr, "TriggerAlpha", "0 if rising edge should be used, 1 if falling and rest values are interpolated", true, 0);
	I_END_COMPONENT;

	CInspectionUnitParamsComp();

	// reimplemented (icntl::IInspectionUnitParams)
	virtual double GetTriggerOffset() const;
	virtual void SetTriggerOffset(double offset);
	virtual double GetTriggerAlpha() const;
	virtual void SetTriggerAlpha(double value);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(istd::CString, m_nameAttrPtr);
	I_ATTR(bool, m_isEnabledAttrPtr);
	I_ATTR(double, m_triggerOffsetAttrPtr);
	I_ATTR(double, m_triggerAlphaAttrPtr);

	double m_triggerOffset;
	double m_triggerAlpha;
};


} // namespace icntl


#endif // !icntl_CInspectionUnitParamsComp_included


