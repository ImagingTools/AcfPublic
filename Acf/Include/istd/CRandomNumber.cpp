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


#include "istd/CRandomNumber.h"


// STD includes
#include <stdlib.h>
#include <time.h>

// ACF includes
#include "istd/istd.h"


namespace istd
{


CRandomNumber::CRandomNumber()
{
	::srand((unsigned)::time(NULL));
}


int CRandomNumber::GetNextInt(int minValue, int maxValue) const
{
	double unitary = GetNextUnitary();

	return minValue + int(unitary * (maxValue - minValue));
}


double CRandomNumber::GetNextDouble(double minValue, double maxValue) const
{
	double unitary = GetNextUnitary();

	return minValue + unitary * (maxValue - minValue);
}


// protected methods

double CRandomNumber::GetNextUnitary() const
{
	double maxRand(RAND_MAX);

	double retVal = 0;
	double factor = 1;

	for (int i = 0; i < 10; ++i){
		factor *= 0.5;
		retVal += factor * 0.5 * ::rand() / maxRand;
	}

	I_ASSERT(retVal >= 0.0);
	I_ASSERT(retVal <= 1.0);

	return retVal;
}


} // namespace istd


