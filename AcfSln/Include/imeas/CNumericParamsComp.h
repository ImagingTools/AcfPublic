/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef imeas_CNumericParamsComp_included
#define imeas_CNumericParamsComp_included


// ACF includes
#include "iser/ISerializable.h"
#include "icomp/CComponentBase.h"

// ACF-Solutions incldues
#include "imeas/IUnitInfo.h"

#include "imeas/INumericParams.h"
#include "imeas/INumericConstraints.h"


namespace imeas
{


/**
	Component implementating imeas::INumericParams interface.
	All parameter constraints can be defined directly or can use external implementation.
*/
class CNumericParamsComp:
			public icomp::CComponentBase,
			virtual public INumericParams,
			virtual protected INumericConstraints,
			virtual protected imeas::IUnitInfo
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CNumericParamsComp);
		I_REGISTER_INTERFACE(istd::IChangeable);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(INumericParams);
		I_ASSIGN(m_dimensionsCountAttrPtr, "DimensionsCount", "Number of filter dimensions (will be used if no constraints set)", true, 2);
		I_ASSIGN(m_minFilterLengthAttrPtr, "MinFilterLength", "Minimal length of filter for all dimensions (will be used if no constraints set)", true, 1);
		I_ASSIGN(m_maxFilterLengthAttrPtr, "MaxFilterLength", "Maximal length of filter for all dimensions (will be used if no constraints set)", true, 10);
		I_ASSIGN_MULTI_0(m_filterLengthsAttrPtr, "FilterLengths", "Default values of filter lengths", false);
		I_ASSIGN(m_constraintsCompPtr, "Constraints", "Constraints object describing possible parameter values", false, "FilterConstraints");
	I_END_COMPONENT;

	// reimplemented (imeas::INumericParams)
	virtual const INumericConstraints* GetConstraints() const;
	virtual imath::CVarVector GetValues() const;
	virtual bool SetValues(const imath::CVarVector& lengths);

	// reimplemented (imeas::INumericConstraints)
	virtual int GetFilterDimensionsCount() const;
	virtual istd::CString GetFilterDescription(int dimension) const;
	virtual const imeas::IUnitInfo& GetFilterUnitInfo(int dimension) const;

	// reimplemented (imeas::IUnitInfo)
	virtual int GetUnitType() const;
	virtual istd::CString GetUnitName() const;
	virtual double GetDisplayMultiplicationFactor() const;
	virtual istd::CRange GetValueRange() const;
	virtual const imath::IDoubleManip& GetValueManip() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	imath::CVarVector m_filterLengts;

	I_ATTR(int, m_dimensionsCountAttrPtr);
	I_ATTR(double, m_minFilterLengthAttrPtr);
	I_ATTR(double, m_maxFilterLengthAttrPtr);
	I_MULTIATTR(double, m_filterLengthsAttrPtr);
	I_REF(INumericConstraints, m_constraintsCompPtr);
};


} // namespace imeas


#endif // !imeas_CNumericParamsComp_included


