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


#ifndef iedge_CEdgesReductorComp_included
#define iedge_CEdgesReductorComp_included


// ACF includes
#include "istd/TSmartPtr.h"
#include "iproc/TSyncProcessorCompBase.h"

// ACF-Solutions includes
#include "imeas/INumericValue.h"
#include "imeas/INumericConstraints.h"

#include "iedge/IEdgeLinesProcessor.h"


namespace iedge
{


class CEdgesReductorComp: public iproc::TSyncProcessorCompBase<IEdgeLinesProcessor>
{
public:
	typedef iproc::TSyncProcessorCompBase<IEdgeLinesProcessor> BaseClass;

	I_BEGIN_COMPONENT(CEdgesReductorComp);
		I_REGISTER_INTERFACE(IEdgeLinesProcessor);
		I_REGISTER_INTERFACE(imeas::INumericConstraints);
		I_ASSIGN(m_defaultToleranceParamsCompPtr, "DefaultToleranceParams", "Default parameter for thresholds, if not taken from parameters", false, "DefaultToleranceParams");
		I_ASSIGN(m_toleranceParamsIdAttrPtr, "ToleranceParamsId", "Parameter ID (imeas::INumericValue) for reduction tolerance", false, "ReductionTolerances");
		I_ASSIGN(m_distanceUnitInfoCompPtr, "DistanceUnitInfo", "Unit information used for distance tolerance", false, "DistanceUnit");
	I_END_COMPONENT;

	void GetReducedLine(
				const CEdgeLine& edgeLine,
				double positionTolerance,
				double weightTolerance,
				CEdgeLine& result) const;
	void GetReducedLines(
				const CEdgeLine::Container& edgeLines,
				double positionTolerance,
				double weightTolerance,
				CEdgeLine::Container& result) const;

	// reimplemented (iedge::IEdgeLinesProcessor)
	virtual bool DoLinesProcessing(
				const iprm::IParamsSet* paramsPtr,
				const CEdgeLine::Container& edgeLines,
				CEdgeLine::Container& result) const;

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				iproc::IProgressManager* progressManagerPtr = NULL);

	// reimplemented (imeas::INumericConstraints)
	virtual int GetNumericValuesCount() const;
	virtual QString GetNumericValueName(int index) const;
	virtual QString GetNumericValueDescription(int index) const;
	virtual const imeas::IUnitInfo& GetNumericValueUnitInfo(int index) const;

protected:
	typedef QVector<bool> NodesToRemove;

	/**
		Mark points to remove.
		\return	number of removed points.
	*/
	int ReduceNodes(
				const CEdgeLine& edgeLine,
				double positionTolerance,
				double weightTolerance,
				int firstIndex,
				int lastIndex,
				NodesToRemove& nodesToRemove,
				int& firstInsideIndex,
				int& lastInsideIndex) const;

private:
	I_REF(imeas::INumericValue, m_defaultToleranceParamsCompPtr);
	I_ATTR(QByteArray, m_toleranceParamsIdAttrPtr);
	I_REF(imeas::IUnitInfo, m_distanceUnitInfoCompPtr);
};


} // namespace iedge


#endif // !iedge_CEdgesReductorComp_included


