/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#pragma once


// ACF includes
#include <istd/TArray.h>
#include <istd/TIndex.h>
#include <imath/TISampledFunction.h>
#include <imath/ISampledFunctionInterpolator.h>


namespace imath
{


/**
	Implementation of the resampled 1D-function.
*/
class CSampledFunction: virtual public ISampledFunction
{
public:
	typedef istd::TIndex<1> Index;

	CSampledFunction();
	CSampledFunction(const CSampledFunction& function);
	explicit CSampledFunction(const imath::ISampledFunction& function);
	explicit CSampledFunction(int size, double defaultValue = 0);

	bool operator==(const CSampledFunction& other) const;

	void Reset();
	bool Initialize(int size, double defaultValue = 0);
	double GetSampleValue(int index) const;
	void SetSampleValue(int index, double value);
	void SetLogicalRange(const istd::CRange& logicalRange);
	void SetInterpolator(ISampledFunctionInterpolator* interpolatorPtr);
	
	// reimplemented (imath::ISampledFunction)
	virtual bool CreateFunction(double* dataPtr, const ArgumentType& sizes) override;
	virtual int GetTotalSamplesCount() const override;
	virtual double GetSampleAt(const SampleIndex& index) const override;
	virtual int GetGridSize(int dimensionIndex) const override;
	virtual istd::CRange GetLogicalRange(int dimensionIndex) const override;
	virtual istd::CRange GetResultValueRange(int dimensionIndex, int resultDimension = -1) const override;

	// reimplemented (imath::TIMathFunction)
	virtual bool GetValueAt(const ArgumentType& argument, ResultType& result) const override;
	virtual ResultType GetValueAt(const ArgumentType& argument) const override;

	// reimplemented (istd::IChangeable)
	virtual int GetSupportedOperations() const override;
	virtual bool CopyFrom(const IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS) override;
	virtual bool IsEqual(const IChangeable& object) const override;
	virtual IChangeable* CloneMe(CompatibilityMode mode = CM_WITHOUT_REFS) const override;
	virtual bool ResetData(CompatibilityMode mode = CM_WITHOUT_REFS) override;

private:
	typedef std::vector<double> SamplesContainer;
	SamplesContainer m_samplesContainer;
	istd::CRange m_logicalRange;

	ISampledFunctionInterpolator* m_interpolatorPtr;
};


// public inline methods

inline double CSampledFunction::GetSampleValue(int index) const
{
	Q_ASSERT(index>= 0 && index < m_samplesContainer.size());

	return m_samplesContainer[index];
}


inline void CSampledFunction::SetSampleValue(int index, double value)
{
	Q_ASSERT(index >= 0 && index < m_samplesContainer.size());

	m_samplesContainer[index] = value;
}


inline void CSampledFunction::SetLogicalRange(const istd::CRange& logicalRange)
{
	m_logicalRange = logicalRange;
}


} // namespace imath


