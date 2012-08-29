/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef imeas_CNumericParamsComp_included
#define imeas_CNumericParamsComp_included


// ACF includes
#include "iser/ISerializable.h"
#include "icomp/CComponentBase.h"

// ACF-Solutions incldues
#include "imeas/IUnitInfo.h"
#include "imeas/INumericConstraints.h"
#include "imeas/CSimpleNumericValue.h"


namespace imeas
{


/**
	Component implementating imeas::INumericValue interface.
	All parameter constraints can be defined directly or can use external implementation.
*/
class CNumericParamsComp:
			public icomp::CComponentBase,
			public CSimpleNumericValue,
			virtual protected INumericConstraints,
			virtual protected imeas::IUnitInfo
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef CSimpleNumericValue BaseClass2;

	I_BEGIN_COMPONENT(CNumericParamsComp);
		I_REGISTER_INTERFACE(istd::IChangeable);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(INumericValue);
		I_ASSIGN(m_dimensionsCountAttrPtr, "ValuesCount", "Default number of numeric values (will be used if no constraints set)", true, 1);
		I_ASSIGN(m_minValueAttrPtr, "MinValues", "Minimal value (will be used if no constraints set)", true, 1);
		I_ASSIGN(m_maxValueAttrPtr, "MaxValues", "Maximal value (will be used if no constraints set)", true, 10);
		I_ASSIGN_MULTI_0(m_defaultValuesAttrPtr, "Values", "Default values", false);
		I_ASSIGN(m_constraintsCompPtr, "Constraints", "Constraints object describing possible parameter values", false, "Constraints");
	I_END_COMPONENT;

	// reimplemented (imeas::INumericValue)
	virtual const INumericConstraints* GetNumericConstraints() const;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

	// reimplemented (imeas::INumericConstraints)
	virtual int GetNumericValuesCount() const;
	virtual QString GetNumericValueName(int index) const;
	virtual QString GetNumericValueDescription(int index) const;
	virtual const imeas::IUnitInfo& GetNumericValueUnitInfo(int index) const;

	// reimplemented (imeas::IUnitInfo)
	virtual int GetUnitType() const;
	virtual QString GetUnitName() const;
	virtual double GetDisplayMultiplicationFactor() const;
	virtual istd::CRange GetValueRange() const;
	virtual const imath::IDoubleManip& GetValueManip() const;

private:
	I_ATTR(int, m_dimensionsCountAttrPtr);
	I_ATTR(double, m_minValueAttrPtr);
	I_ATTR(double, m_maxValueAttrPtr);
	I_MULTIATTR(double, m_defaultValuesAttrPtr);
	I_REF(INumericConstraints, m_constraintsCompPtr);
};


} // namespace imeas


#endif // !imeas_CNumericParamsComp_included


