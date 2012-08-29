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


#ifndef istd_CBase64_included
#define istd_CBase64_included


// Qt includes
#include <QtCore/QByteArray>
#include <QtCore/QVector>

// ACF includes
#include <istd/istd.h>


namespace istd
{


/**
	Base64 converter.
*/
class CBase64
{
public:
	static QByteArray ConvertToBase64(const void* dataPtrPtr, int size);
	static QVector<quint8> ConvertFromBase64(const QByteArray& base64String);

private:
	static char SixBitToChar(quint8 b);
	static quint8 CharToSixBit(char c);
};


} // namespace istd


#endif // !istd_CBase64_included


