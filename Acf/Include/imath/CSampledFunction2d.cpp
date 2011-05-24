/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "imath/CSampledFunction2d.h"


// STL includes
#include <cstring>


// ACF includes
#include "istd/TChangeNotifier.h"


namespace imath
{


CSampledFunction2d::CSampledFunction2d(int width, int height, double defaultValue)
{
	Create(width, height, defaultValue);
}


void CSampledFunction2d::Reset()
{
	m_samplesContainer.Reset();
}


void CSampledFunction2d::Create(int width, int height, double defaultValue)
{
	Reset();

	if (width > 0 && height > 0){
		m_samplesContainer.SetSize(0, width);
		m_samplesContainer.SetSize(1, height);

		SamplesContainer::Iterator beginIter = m_samplesContainer.Begin();
		double* dataPtr = &(*beginIter);

		std::memset(dataPtr, 0, sizeof(double) * width * height);

		if (defaultValue != 0){
			for (		SamplesContainer::Iterator index = m_samplesContainer.Begin();
						index != m_samplesContainer.End();
						index++){
				*index = defaultValue;
			}
		}
	}
}


void CSampledFunction2d::SetSampleValue(const ArgumentType& index, double value)
{
	I_IF_DEBUG(
		ArgumentType boundary;
		boundary.SetAt(0, m_samplesContainer.GetSize(0));
		boundary.SetAt(1, m_samplesContainer.GetSize(1));)
	I_ASSERT(index.IsInside(boundary));

	m_samplesContainer.SetAt(index, value);
}


// reimplemented (ISampledFunction2d)

bool CSampledFunction2d::CreateFunction(double* dataPtr, const ArgumentType& sizes)
{
	Create(sizes[0], sizes[1]);

	SamplesContainer::Iterator beginIter = m_samplesContainer.Begin();
	double* functionDataPtr = &(*beginIter);
	
	std::memcpy(functionDataPtr, dataPtr, sizeof(double) * sizes[0] * sizes[1]);

	return true;
}


int CSampledFunction2d::GetTotalSamplesCount() const
{
	return m_samplesContainer.GetSize(0) * m_samplesContainer.GetSize(1);
}


istd::CRange CSampledFunction2d::GetLogicalRange(int dimensionIndex) const
{
	return istd::CRange(0, m_samplesContainer.GetSize(dimensionIndex));
}


int CSampledFunction2d::GetGridSize(int dimensionIndex) const
{
	return m_samplesContainer.GetSize(dimensionIndex);
}


istd::CRange CSampledFunction2d::GetResultValueRange(int /*dimensionIndex*/, int /*resultDimension*/) const
{
	return istd::CRange(0, 1.0);
}


// reimplemented (TIMathFunction)

bool CSampledFunction2d::GetValueAt(const ArgumentType& argument, ResultType& result) const
{
	ArgumentType boundary;
	boundary.SetAt(0, m_samplesContainer.GetSize(0));
	boundary.SetAt(1, m_samplesContainer.GetSize(1));

	if (argument.IsInside(boundary)){
		result.SetElement(0, m_samplesContainer.GetAt(argument));
		
		return true;
	}

	return false;
}


CSampledFunction2d::ResultType CSampledFunction2d::GetValueAt(const ArgumentType& argument) const
{
	ResultType result;

	GetValueAt(argument, result);

	return result;
}



} // namespace imath


