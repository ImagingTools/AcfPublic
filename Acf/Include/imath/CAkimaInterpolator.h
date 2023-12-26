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


#ifndef imath_CAkimaInterpolator_included
#define imath_CAkimaInterpolator_included


// Qt includes
#include <QtCore/QMap>

// ACF includes
#include <imath/TIMathFunction.h>


namespace imath
{


/**
	1D interpolation using Akima method.
*/
class CAkimaInterpolator: public virtual IDoubleFunction
{
public:
	struct Node
	{
		double value;
		double derivative;
	};

	typedef QMap<double, Node> Nodes;

	CAkimaInterpolator();
	CAkimaInterpolator(double* positions, double* values, int nodesCount);

	void SetNodes(double* positions, double* values, int nodesCount);

	// reimplemented (imath::TIMathFunction<double, double>)
	virtual bool GetValueAt(const double& argument, double& result) const override;
	virtual double GetValueAt(const double& argument) const override;

protected:
	Nodes m_nodes;
};


} // namespace imath


#endif // !imath_CAkimaInterpolator_included


