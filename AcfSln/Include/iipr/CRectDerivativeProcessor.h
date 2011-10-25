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


#ifndef iipr_CRectDerivativeProcessor_included
#define iipr_CRectDerivativeProcessor_included


// ACF includes
#include "iproc/TSyncProcessorWrap.h"

// ACF-Solutions includes
#include "imeas/IDataSequence.h"
#include "imeas/IUnitInfo.h"
#include "imeas/INumericConstraints.h"


namespace iipr
{


/**
	Calculate derivative of projection using rectangular filter kernel.
*/
class CRectDerivativeProcessor:
			public iproc::CSyncProcessorBase,
			virtual public imeas::INumericConstraints,
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

	// reimplemented (imeas::INumericConstraints)
	virtual int GetNumericValuesCount() const;
	virtual istd::CString GetNumericValueDescription(int index) const;
	virtual const imeas::IUnitInfo& GetNumericValueUnitInfo(int index) const;

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


