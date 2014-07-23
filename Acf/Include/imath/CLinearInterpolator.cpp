/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "imath/CLinearInterpolator.h"


// Qt includes
#include <QtCore/QVector>


namespace imath
{


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
	if (m_nodes.count() < 2){
		return false;
	}

	if (argument < m_nodes.firstKey() || argument > m_nodes.lastKey()){
		return false;
	}

	if (m_nodes.contains(argument)){
		result = m_nodes.value(argument);

		return true;
	}

	QList<double> keys = m_nodes.keys();

	double prevKey = keys[0];
	double nextKey = keys[0];

	for (int i = 1; i < keys.count(); i++){
		if (argument > nextKey){
			prevKey = nextKey;
			
			nextKey = keys[i];
		}
		else{
			break;
		}
	}

	double preValue = m_nodes.value(prevKey);
	double nextValue = m_nodes.value(nextKey);

	if (preValue == nextValue){
		result = preValue;

		return true;
	}

	double keyDiff = nextKey - prevKey;
	double argDiff = argument - prevKey;
	double argRatio = argDiff / keyDiff;

	double valueDiff = nextValue - preValue;

	result = preValue + (valueDiff * argRatio);

	return true;
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


