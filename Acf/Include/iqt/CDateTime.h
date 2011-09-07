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


#ifndef iqt_CDateTime_included
#define iqt_CDateTime_included


// Qt includes
#include <QDateTime>


// ACF includes
#include "isys/CDateTimeBase.h"


namespace iqt
{


/**
	Implementation of isys::IDateTime interface based on Qt.
*/
class CDateTime: public isys::CDateTimeBase, public QDateTime
{
public:
	CDateTime();
	CDateTime(const CDateTime& time);
	CDateTime(const QDateTime& time);

	// reimplemented (isys::IDateTime)
	virtual int GetComponent(int component) const;
	virtual void SetComponent(int component, int value);
	virtual bool SetCurrentTime();
	virtual double ToCTime() const;
	virtual void FromCTime(double ctime);

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const istd::IChangeable& object);
	virtual istd::IChangeable* CloneMe() const;
};


} // namespace iqt


#endif // !iqt_CDateTime_included


