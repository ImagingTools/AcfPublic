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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef istd_CBitManip_included
#define istd_CBitManip_included


#include "istd/istd.h"


namespace istd
{


class CBitManip
{
public:
	CBitManip();

	/**
		Return index of first bit in byte.
	*/
	int GetFirstBitIndex(quint32 bits) const;

	static CBitManip instance;

private:
	qint8 m_firstBitInByte[256];
};


// inline methods

inline int CBitManip::GetFirstBitIndex(quint32 bits) const
{
	quint16* words = (quint16*)&bits;
	quint8* bytes = (quint8*)&bits;
	if (words[0] != 0){
		if (bytes[0] != 0){
			return int(m_firstBitInByte[bytes[0]]);
		}

		return int(m_firstBitInByte[bytes[1]]);
	}
	else if (words[1] != 0){
		if (bytes[2] != 0){
			return int(m_firstBitInByte[bytes[2]]);
		}

		return int(m_firstBitInByte[bytes[3]]);
	}

	return -1;
}


} // namespace istd


#endif // !istd_CBitManip_included


