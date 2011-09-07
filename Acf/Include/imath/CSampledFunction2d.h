/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef imath_CSampledFunction2d_included
#define imath_CSampledFunction2d_included


#include "istd/TArray.h"

#include "imath/TISampledFunction.h"


namespace imath
{


/**
	Implementation of the resampled 2D-function.
*/
class CSampledFunction2d: virtual public ISampledFunction2d
{
public:
	CSampledFunction2d(int width = -1, int height = -1, double defaultValue = 0);

	void Reset();
	void Create(int width, int height, double defaultValue = 0);
	void SetSampleValue(const ArgumentType& index, double value);
	
	// reimplemented (imath::ISampledFunction2d)
	virtual bool CreateFunction(double* dataPtr, const ArgumentType& sizes);
	virtual int GetTotalSamplesCount() const;
	virtual int GetGridSize(int dimensionIndex) const;
	virtual istd::CRange GetLogicalRange(int dimensionIndex) const;
	virtual istd::CRange GetResultValueRange(int dimensionIndex, int resultDimension = -1) const;

	// reimplemented (imath::TIMathFunction)
	virtual bool GetValueAt(const ArgumentType& argument, ResultType& result) const;
	virtual ResultType GetValueAt(const ArgumentType& argument) const;

private:
	typedef istd::TArray<double, 2> SamplesContainer;

	SamplesContainer m_samplesContainer;
};


} // namespace imath


#endif // !imath_CSampledFunction2d_included


