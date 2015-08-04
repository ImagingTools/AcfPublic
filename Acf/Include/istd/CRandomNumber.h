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


#ifndef istd_CRandomNumber_included
#define istd_CRandomNumber_included


namespace istd
{


/**
	Helper class for calculation of a random number.
*/
class CRandomNumber
{
public:
	CRandomNumber();

	/**
		Get new random integer value in the given range.
	*/
	int GetNextInt(int minValue, int maxValue) const;

	/**
		Get new random real value in the given range.
	*/
	double GetNextDouble(double minValue, double maxValue) const;

protected:
	double GetNextUnitary() const;
};


} // namespace istd


#endif // !istd_CRandomNumber_included


