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


#include <ifile/CSimpleEncoder.h>


namespace ifile
{


// public static methods

bool CSimpleEncoder::Encode(const quint8* dataPtr, quint8* resultPtr, int size)
{
	quint8 carry = EV_INIT_OFFSET;
	for (int i = 0; i < size; i++){
		carry += dataPtr[i] + EV_OFFSET;
		resultPtr[i] = carry;
	}

	return true;
}


bool CSimpleEncoder::Decode(const quint8* dataPtr, quint8* resultPtr, int size)
{
	quint8 carry = EV_INIT_OFFSET;
	for (int i = 0; i < size; i++){
		carry += EV_OFFSET;

		quint8 value = dataPtr[i] - carry;
		resultPtr[i] = value;

		carry += value;
	}

	return true;
}


} // namespace ifile


