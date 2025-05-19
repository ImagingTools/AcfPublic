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


#ifndef iipr_CSearchConstraintsComp_included
#define iipr_CSearchConstraintsComp_included


// ACF includes
#include <icomp/CComponentBase.h>
#include <iipr/ISearchConstraints.h>
#include <imeas/INumericValue.h>
#include <imeas/INumericConstraints.h>


namespace iipr
{


/**	
	Search algorithm limitations provider
*/
class CSearchConstraintsComp:
			public icomp::CComponentBase,
			virtual public iipr::ISearchConstraints
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CSearchConstraintsComp);
		I_REGISTER_INTERFACE(iipr::ISearchConstraints);
		I_ASSIGN(m_searchContraintsBaseCompPtr, "SearchContraintsBase", "Base provider of search constraints", true, "SearchContraintsBase");
		I_ASSIGN(m_modelOccurenceLimitationCompPtr, "ModelOccurenceLimitation", "Model occurence constraints", false, "ModelOccurenceConstraints");
		I_ASSIGN(m_rotationContraintsCompPtr, "ModelRotationConstraints", "Constraints on model rotation", false, "ModelRotationConstraints");
		I_ASSIGN(m_scaleRangeContraintsCompPtr, "ScaleRangeConstraints", "Constraints on model scale", false, "ScaleRangeConstraints");
	I_END_COMPONENT;

	// reimplemented (iipr::ISearchConstraints)
	virtual int GetSearchSupportedFlags() const override;
	virtual const istd::CRange& GetRotationRangeConstraints() const override;
	virtual const istd::CRange& GetScaleRangeConstraints() const override;
	virtual const istd::CIntRange& GetResultsCountConstraints() const override;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated() override;

private:
	I_REF(iipr::ISearchConstraints, m_searchContraintsBaseCompPtr);
	I_REF(imeas::INumericValue, m_modelOccurenceLimitationCompPtr);
	I_REF(imeas::INumericConstraints, m_rotationContraintsCompPtr);
	I_REF(imeas::INumericConstraints, m_scaleRangeContraintsCompPtr);

	istd::CRange m_rotationContraints;
	istd::CRange m_scaleContraints;
	istd::CIntRange m_resultCountContraints;
};


} // namespace iipr


#endif // iipr_CSearchConstraintsComp_included


