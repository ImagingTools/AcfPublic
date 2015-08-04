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


#ifndef ibase_CSize_included
#define ibase_CSize_included


// ACF includes
#include "istd/CIndex2d.h"
#include "iser/ISerializable.h"


namespace ibase
{		


/**
	Definition of simple 2D size based on integer values.
*/
class CSize: public istd::CIndex2d
{
public:
	typedef istd::CIndex2d BaseClass;

	CSize();
	CSize(int width, int height);
	CSize(const istd::CIndex2d& index);
	CSize(const QPoint& point);
	CSize(const QSize& size);

	CSize operator+(const CSize& size);
	CSize operator-(const CSize& size);
	CSize& operator+=(const CSize& size);
	CSize& operator-=(const CSize& size);

	bool IsNull() const;
	
	bool Serialize(iser::IArchive& archive);
};


} // namespace ibase


#endif // !ibase_CSize_included


