/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef imeas_CNumericParamsComp_included
#define imeas_CNumericParamsComp_included


// ACF includes
#include <icomp/CComponentBase.h>
#include <imod/IModel.h>
#include <imod/CSingleModelObserverBase.h>

// ACF-Solutions includes
#include <imath/IUnitInfo.h>
#include <imeas/INumericConstraints.h>
#include <imeas/CSimpleNumericValue.h>


namespace imeas
{


/**
	Component implementating imeas::INumericValue interface.
	All parameter constraints can be defined directly or can use external implementation.
*/
class CNumericParamsComp:
			public icomp::CComponentBase,
			public CSimpleNumericValue,
			protected imod::CSingleModelObserverBase
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef CSimpleNumericValue BaseClass2;

	I_BEGIN_COMPONENT(CNumericParamsComp);
		I_REGISTER_INTERFACE(istd::IChangeable);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(INumericValue);
		I_ASSIGN_MULTI_0(m_defaultValuesAttrPtr, "Values", "Default values", false);
		I_ASSIGN(m_constraintsCompPtr, "Constraints", "Constraints object describing possible parameter values", false, "Constraints");
	I_END_COMPONENT;

	// reimplemented (imeas::INumericValue)
	virtual const INumericConstraints* GetNumericConstraints() const;

protected:
	// reimplemented (imeas::INumericValue)
	virtual void OnUpdate(const istd::IChangeable::ChangeSet& changeSet);

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_MULTIATTR(double, m_defaultValuesAttrPtr);
	I_REF(INumericConstraints, m_constraintsCompPtr);
};


} // namespace imeas


#endif // !imeas_CNumericParamsComp_included


