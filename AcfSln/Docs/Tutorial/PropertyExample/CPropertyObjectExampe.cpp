/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "CPropertyObjectExampe.h"


// public methods

CPropertyObjectExampe::CPropertyObjectExampe()
	:m_number(this, /*Tag name*/"MyNumber", /*Tag description*/"A simple number", /* Property is persistent*/iprop::IProperty::PF_PERSISTENT),
	m_text(this, "MyText", "A small text", iprop::IProperty::PF_PERSISTENT),
	m_rectangle(this, "MyRectangle", "Rectangle object", iprop::IProperty::PF_PERSISTENT)
{
	// register your own property types:
	RegisterPropertyType<CRectangleProperty>();
}


// reimplemented (IMyDataModel)

double CPropertyObjectExampe::GetNumber() const
{
	return m_number.GetValue();
}


void CPropertyObjectExampe::SetNumber(double number)
{
	m_number.SetValue(number);
}


QByteArray CPropertyObjectExampe::GetText() const
{
	return m_text.GetValue();
}


void CPropertyObjectExampe::SetText(const QByteArray& text)
{
	m_text.SetValue(text);
}


i2d::CRectangle CPropertyObjectExampe::GetRectangle() const
{
	return m_rectangle.GetValue();
}


void CPropertyObjectExampe::SetRectangle(const i2d::CRectangle& rectangle)
{
	m_rectangle.SetValue(rectangle);
}

