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


#ifndef istd_CBitManip_included
#define istd_CBitManip_included


// Qt includes
#include <QtCore/QtGlobal>


namespace istd
{


/**
	Helper class for bits manipulations.
*/
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
	if (bits == 0) {
		return -1;
	}

	quint8 b0 = static_cast<quint8>(bits & 0xFFu);
	if (b0 != 0){
		return int(m_firstBitInByte[b0]);
	}

	quint8 b1 = static_cast<quint8>((bits >> 8) & 0xFFu);
	if (b1 != 0) {
		return int(m_firstBitInByte[b1]) + 8;
	}

	quint8 b2 = static_cast<quint8>((bits >> 16) & 0xFFu);
	if (b2 != 0){
		return int(m_firstBitInByte[b2]) + 16;
	}

	quint8 b3 = static_cast<quint8>((bits >> 24) & 0xFFu);
	if (b3 != 0) {
		return int(m_firstBitInByte[b3]) + 24;
	}

	return -1;
}


} // namespace istd


#endif // !istd_CBitManip_included


