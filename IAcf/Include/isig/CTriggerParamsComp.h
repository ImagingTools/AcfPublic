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


#ifndef isig_CTriggerParamsComp_included
#define isig_CTriggerParamsComp_included


#include "icomp/CComponentBase.h"

#include "isig/ITriggerConstraints.h"
#include "isig/ITriggerParams.h"


namespace isig
{


/**
	Implementatation of standard trigger parameters set.
*/
class CTriggerParamsComp: public icomp::CComponentBase, virtual public isig::ITriggerParams
{
public:
	typedef icomp::CComponentBase BaseClass;

	CTriggerParamsComp();

	I_BEGIN_COMPONENT(CTriggerParamsComp);
		I_REGISTER_INTERFACE(isig::ITriggerParams);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_ASSIGN(m_triggerConstraintsCompPtr, "TriggerConstraints", "Describing allowed parameter state, typically implemented in camera component", false, "TriggerConstraints");
		I_ASSIGN(m_isTriggerEnabledAttrPtr, "ExternalTriggerEnabled", "Enables external trigger", false, false);
		I_ASSIGN(m_triggerModeAttrPtr, "TriggerMode", "Set trigger mode: 0 - Default, 1 - Rising edge, 2 - Falling edge, 3 - Positive level, 4 - Negative level", false, 0);
	I_END_COMPONENT;

	// reimplmented (isig::ITriggerParams)
	virtual const ITriggerConstraints* GetConstraints() const;
	virtual bool IsTriggerEnabled() const;
	virtual void SetTriggerEnabled(bool isEnabled);
	virtual int GetTriggerMode() const;
	virtual void SetTriggerMode(int triggerMode);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	bool m_isTriggerEnabled;
	int m_triggerMode;

	I_REF(isig::ITriggerConstraints, m_triggerConstraintsCompPtr);
	I_ATTR(bool, m_isTriggerEnabledAttrPtr);
	I_ATTR(int, m_triggerModeAttrPtr);
};


} // namespace isig


#endif // !isig_CTriggerParamsComp_included


