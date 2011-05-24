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


#ifndef istd_CCrcCalculator_included
#define istd_CCrcCalculator_included


// STL includes
#include <vector>


#include "istd/istd.h"


namespace istd
{


class CString;


class CCrcCalculator
{
public:
	typedef std::vector<I_BYTE> ByteStream;

	static I_DWORD GetCrcFromData(const I_BYTE* dataPtr, int dataSize);
	static I_DWORD GetCrcFromStream(const ByteStream& byteStream);
	static I_DWORD GetCrcFromFile(const istd::CString& fileName);

	static void UpdateCrc(const I_BYTE& byte, I_DWORD& dwCrc32);

private:
	static I_DWORD s_crcTable[256];
};


// inline methods

inline void CCrcCalculator::UpdateCrc(const I_BYTE& byte, I_DWORD& crcValue)
{
	crcValue = (crcValue >> 8) ^ s_crcTable[byte ^ (crcValue & 0x000000FF)];
}


} // namespace istd


#endif // !istd_CCrcCalculator_included

