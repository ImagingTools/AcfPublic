/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#include <imath/CLinearInterpolator.h>


namespace imath
{


CLinearInterpolator::CLinearInterpolator()
{
}


CLinearInterpolator::CLinearInterpolator(double* positions, double* values, int nodesCount)
{
	SetNodes(positions, values, nodesCount);
}


void CLinearInterpolator::SetNodes(double* positions, double* values, int nodesCount)
{
	m_nodes.clear();

	for (int i = 0; i < nodesCount; i++){
		m_nodes[positions[i]] = values[i];
	}
}


// reimplemented (imath::TIMathFunction<double, double>)

bool CLinearInterpolator::GetValueAt(const double& argument, double& result) const
{
	Nodes::ConstIterator nextIter = m_nodes.lowerBound(argument);
	if (nextIter != m_nodes.constEnd()){
		double nextPosition = nextIter.key();
		Q_ASSERT(nextPosition >= argument);
		double nextValue = nextIter.value();

		if ((nextValue == argument) || (nextIter == m_nodes.constBegin())){
			result = nextValue;

			return true;
		}

		Nodes::ConstIterator prevIter = nextIter - 1;

		double prevPosition = prevIter.key();
		Q_ASSERT(prevPosition <= argument);
		double prevValue = prevIter.value();

		// interpolation in segment
		double nodeDiff = (nextPosition - prevPosition);
		Q_ASSERT(nodeDiff > 0);

		double alpha = (argument - prevPosition) / nodeDiff;

		result =	prevValue * (1 - alpha) +
					nextValue * alpha;

		return true;
	}

	return false;
}


double CLinearInterpolator::GetValueAt(const double& argument) const
{
	double retVal;
	if (GetValueAt(argument, retVal)){
		return retVal;
	}
	else{
		return 0;
	}
}


} // namespace imath


