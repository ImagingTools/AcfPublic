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


#ifndef isys_CSimpleDateTime_included
#define isys_CSimpleDateTime_included


#include "istd/TIndex.h"

#include "isys/CDateTimeBase.h"


namespace isys
{


/**
	Implementation of isys::IDateTime interface using no operating system.
*/
class CSimpleDateTime: public isys::CDateTimeBase
{
public:
	CSimpleDateTime();
	CSimpleDateTime(const IDateTime& dateTime);

	CSimpleDateTime& operator=(const IDateTime& dateTime);

	bool operator==(const IDateTime& dateTime) const;
	bool operator!=(const IDateTime& dateTime) const;

	static CSimpleDateTime GetCurrent();

	// reimplemented (isys::IDateTime)
	virtual int GetComponent(int component) const;
	virtual void SetComponent(int component, int value);
	virtual bool SetCurrentTime();
	virtual double ToCTime() const;
	virtual void FromCTime(double ctime);

private:
	istd::TIndex<TC_LAST + 1> m_components;
};


} // namespace isys


#endif // !isys_CSimpleDateTime_included


