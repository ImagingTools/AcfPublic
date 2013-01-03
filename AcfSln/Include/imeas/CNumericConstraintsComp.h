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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/



#ifndef imeas_CNumericConstraintsComp_included
#define imeas_CNumericConstraintsComp_included


// ACF includes
#include "iser/ISerializable.h"
#include "icomp/CComponentBase.h"

// ACF-Solutions includes
#include "imath/IUnitInfo.h"
#include "imath/CDoubleManip.h"

#include "imeas/INumericValue.h"
#include "imeas/INumericConstraints.h"


namespace imeas
{


/**
	Simple implementation of imeas::INumericConstraints interface.
	All values use the same units and ranges.
*/
class CNumericConstraintsComp:
			public icomp::CComponentBase,
			virtual public INumericConstraints,
			virtual protected imath::IUnitInfo,
			protected imath::CDoubleManip
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CNumericConstraintsComp);
		I_REGISTER_INTERFACE(INumericConstraints);
		I_ASSIGN(m_dimensionsCountAttrPtr, "ValuesCount", "Default number of numeric values", true, 1);
		I_ASSIGN_MULTI_0(m_namesAttrPtr, "ValueName", "Name of each single value", true);
		I_ASSIGN_MULTI_0(m_descriptionsAttrPtr, "ValueDescriptions", "Description of each single value", true);
		I_ASSIGN_MULTI_0(m_valueIdsAttrPtr, "ValueIds", "ID of each single value", true);
		I_ASSIGN(m_unitTypeAttrPtr, "UnitType", "Type of unit\n\t0 - unknown,\n\t1 - physical,\n\t2 - technical,\n\t3 - relative", true, 0);
		I_ASSIGN(m_unitNameAttrPtr, "UnitName", "Name of unit", true, "");
		I_ASSIGN(m_displayMultFactorAttrPtr, "DisplayMultFactor", "Scale factor used for display, e.g for unit name '%' it will be 100", true, 1);
		I_ASSIGN(m_minValueAttrPtr, "MinValue", "Minimal value", true, 0);
		I_ASSIGN(m_maxValueAttrPtr, "MaxValue", "Maximal value", true, 1);
		I_ASSIGN(m_precisionAttrPtr, "Precision", "Typical values: 0 - integer, 15 - double", true, 15);
	I_END_COMPONENT;

	// reimplemented (imeas::INumericConstraints)
	virtual int GetNumericValuesCount() const;
	virtual QString GetNumericValueName(int index) const;
	virtual QString GetNumericValueDescription(int index) const;
	virtual const imath::IUnitInfo& GetNumericValueUnitInfo(int index) const;

protected:
	// reimplemented (imath::IUnitInfo)
	virtual int GetUnitType() const;
	virtual QString GetUnitName() const;
	virtual double GetDisplayMultiplicationFactor() const;
	virtual istd::CRange GetValueRange() const;
	virtual const imath::IDoubleManip& GetValueManip() const;

	// reimplemented (imath::IDoubleManip)
	virtual int GetPrecision() const;

	// reimplemented (ibase::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(int, m_dimensionsCountAttrPtr);
	I_MULTIATTR(QString, m_namesAttrPtr);
	I_MULTIATTR(QString, m_descriptionsAttrPtr);
	I_MULTIATTR(QByteArray, m_valueIdsAttrPtr);
	I_ATTR(int, m_unitTypeAttrPtr);
	I_ATTR(QString, m_unitNameAttrPtr);
	I_ATTR(double, m_displayMultFactorAttrPtr);
	I_ATTR(double, m_minValueAttrPtr);
	I_ATTR(double, m_maxValueAttrPtr);
	I_ATTR(int, m_precisionAttrPtr);

	int m_precision;
};


} // namespace imeas


#endif // !imeas_CNumericConstraintsComp_included


