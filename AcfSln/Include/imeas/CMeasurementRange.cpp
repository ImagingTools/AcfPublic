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


#include "imeas/CMeasurementRange.h"


namespace imeas
{


CMeasurementRange::CMeasurementRange()
{
}


bool CMeasurementRange::IsValid() const
{
	return (m_warningRange.IsValid() && m_errorRange.IsValid()) && (!m_warningRange.IsEmpty() && !m_errorRange.IsEmpty());
}


void CMeasurementRange::SetLowerErrorLimit(double lowerErrorLimit)
{
	m_errorRange.SetMinValue(lowerErrorLimit);
}


void CMeasurementRange::SetUpperErrorLimit(double upperErrorLimit)
{
	m_errorRange.SetMaxValue(upperErrorLimit);
}


void CMeasurementRange::SetLowerWarningLimit(double lowerWarningLimit)
{
	m_warningRange.SetMinValue(lowerWarningLimit);
}


void CMeasurementRange::SetUpperWarningLimit(double upperWarningLimit)
{
	m_warningRange.SetMaxValue(upperWarningLimit);
}


double CMeasurementRange::GetLowerErrorLimit() const
{
	return m_errorRange.GetMinValue();
}


double CMeasurementRange::GetUpperErrorLimit() const
{
	return m_errorRange.GetMaxValue();
}


double CMeasurementRange::GetLowerWarningLimit() const
{
	return m_warningRange.GetMinValue();
}


double CMeasurementRange::GetUpperWarningLimit() const
{
	return m_warningRange.GetMaxValue();
}


bool CMeasurementRange::IsOk(double value) const
{
	Q_ASSERT(IsValid());

	return m_warningRange.Contains(value) && m_errorRange.Contains(value);
}


bool CMeasurementRange::IsWarning(double value) const
{
	Q_ASSERT(IsValid());

	return m_warningRange.Contains(value);
}


bool CMeasurementRange::IsError(double value) const
{
	Q_ASSERT(IsValid());

	return (!IsOk(value) && !IsWarning(value));
}


bool CMeasurementRange::operator == (const CMeasurementRange& otherRange) const
{
	return (m_warningRange == otherRange.m_warningRange) && (m_errorRange == otherRange.m_errorRange);
}


bool CMeasurementRange::operator != (const CMeasurementRange& otherRange) const
{
	return !operator == (otherRange);
}



} // namespace imeas


