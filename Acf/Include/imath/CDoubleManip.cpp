/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#include "imath/CDoubleManip.h"


namespace imath
{


CDoubleManip::CDoubleManip()
:	m_pointChar('.')
{
}


// reimplemented (imath::IDoubleManip)

int CDoubleManip::GetPrecision() const
{
	return 15;	// approximated precision of type double with the leading digit before the point
}


// reimplemented (imath::TIValueManip)

QString CDoubleManip::GetString(const double& value) const
{
	return QString::number(value);
}


bool CDoubleManip::GetParsed(const QString& text, double& result) const
{
	bool isOk;

	result = text.toDouble(&isOk);

	return isOk;
}


} // namespace imath


