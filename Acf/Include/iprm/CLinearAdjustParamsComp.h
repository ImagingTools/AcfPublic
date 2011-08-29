/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iprm_CLinearAdjustParamsComp_included
#define iprm_CLinearAdjustParamsComp_included


#include "iser/ISerializable.h"

#include "icomp/CComponentBase.h"

#include "iprm/ILinearAdjustParams.h"
#include "iprm/ILinearAdjustConstraints.h"


namespace iprm
{


/**
	Basic implementation of component of linear adjust parameters.
*/
class CLinearAdjustParamsComp:
			public icomp::CComponentBase,
			virtual public ILinearAdjustParams
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CLinearAdjustParamsComp);
		I_REGISTER_INTERFACE(istd::IChangeable);
		I_REGISTER_INTERFACE(ILinearAdjustParams);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_ASSIGN(m_constraintsCompPtr, "Constraints", "Constraints describing allowed value ranges", false, "Constraints");
		I_ASSIGN(m_defaultScaleAttrPtr, "DefaultScale", "Default value of scale factor", true, 1);
		I_ASSIGN(m_defaultOffsetAttrPtr, "DefaultOffset", "Default value of offset factor", true, 0);
	I_END_COMPONENT;

	CLinearAdjustParamsComp();

	// reimplemented (iprm::ILinearAdjustParams)
	virtual const ILinearAdjustConstraints* GetAdjustConstraints() const;
	virtual double GetScaleFactor() const;
	virtual void SetScaleFactor(double scale);
	virtual double GetOffsetFactor() const;
	virtual void SetOffsetFactor(double offset);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	I_REF(ILinearAdjustConstraints, m_constraintsCompPtr);
	I_ATTR(double, m_defaultScaleAttrPtr);
	I_ATTR(double, m_defaultOffsetAttrPtr);

	double m_scale;
	double m_offset;
};


} // namespace iprm


#endif // !iprm_CLinearAdjustParamsComp_included


