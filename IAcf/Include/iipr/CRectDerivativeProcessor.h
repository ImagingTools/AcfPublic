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


#ifndef iipr_CRectDerivativeProcessor_included
#define iipr_CRectDerivativeProcessor_included


// ACF includes
#include "iproc/TSyncProcessorWrap.h"

// ACF-Solutions includes
#include "imeas/IDataSequence.h"
#include "imeas/IUnitInfo.h"


#include "iipr/IMultidimensionalFilterConstraints.h"


namespace iipr
{


/**
	Calculate derivative of projection using rectangular filter kernel.
*/
class CRectDerivativeProcessor:
			public iproc::CSyncProcessorBase,
			virtual public IMultidimensionalFilterConstraints,
			virtual protected imeas::IUnitInfo
{
public:
	/**
		Do extremum features analyze.
	*/
	virtual bool DoDerivativeProcessing(const imeas::IDataSequence& source, double filterLength, imeas::IDataSequence& results);

	/**
		Get parameter ID used to extract caliper parameter object from parameter set.
	*/
	const std::string& GetFilterParamsId() const;

	/**
		Set parameter ID used to extract caliper parameter object from parameter set.
		It is only needed while using general processing interface iproc::IProcessor.
	*/
	void SetFilterParamsId(const std::string& id);

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				iproc::IProgressManager* progressManagerPtr = NULL);

	// reimplemented (iipr::IMultidimensionalFilterConstraints)
	virtual int GetFilterDimensionsCount() const;
	virtual istd::CString GetFilterDescription(int dimension) const;
	virtual const imeas::IUnitInfo& GetFilterUnitInfo(int dimension) const;

	// reimplemented (imeas::IUnitInfo)
	virtual int GetUnitType() const;
	virtual istd::CString GetUnitName() const;
	virtual double GetDisplayMultiplicationFactor() const;
	virtual istd::CRange GetValueRange() const;
	virtual const imath::IDoubleManip& GetValueManip() const;

private:
	std::string m_filterParamsId;
};


// inline methods

inline const std::string& CRectDerivativeProcessor::GetFilterParamsId() const
{
	return m_filterParamsId;
}


inline void CRectDerivativeProcessor::SetFilterParamsId(const std::string& id)
{
	m_filterParamsId = id;
}


} // namespace iipr


#endif // !iipr_CRectDerivativeProcessor_included


