/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#include "iqtgui/CDoubleRangeSpinEdit.h"


namespace iqtgui
{


CDoubleRangeSpinEdit::CDoubleRangeSpinEdit(QWidget *parent): 
	QWidget(parent),
	m_maxValueEnabled(true)
{
	m_ui.setupUi(this);

	connect(m_ui.ValueFromSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(ValuesChanged()));
	connect(m_ui.ValueToSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(ValuesChanged()));
}


// public interface

void CDoubleRangeSpinEdit::SetMinRange(double minFrom, double minTo)
{
	m_ui.ValueFromSpinBox->setRange(minFrom, minTo);
}


void CDoubleRangeSpinEdit::SetMaxRange(double maxFrom, double maxTo)
{
	m_ui.ValueToSpinBox->setRange(maxFrom, maxTo);
}


void CDoubleRangeSpinEdit::SetRange(double from, double to)
{
	m_ui.ValueFromSpinBox->setRange(from, to);
	m_ui.ValueToSpinBox->setRange(from, to);
}


void CDoubleRangeSpinEdit::SetDecimals(int count)
{
	m_ui.ValueFromSpinBox->setDecimals(count);
	m_ui.ValueToSpinBox->setDecimals(count);
}


void CDoubleRangeSpinEdit::SetSingleStep(double step)
{
	m_ui.ValueFromSpinBox->setSingleStep(step);
	m_ui.ValueToSpinBox->setSingleStep(step);
}


void CDoubleRangeSpinEdit::SetSuffixText(const QString& suffix)
{
	m_ui.SuffixLabel1->setText(suffix);
	m_ui.SuffixLabel1->setVisible(!suffix.isEmpty());

	m_ui.SuffixLabel2->setText(suffix);
	m_ui.SuffixLabel2->setVisible(!suffix.isEmpty() && m_maxValueEnabled);
}


void CDoubleRangeSpinEdit::SetMinLabelText(const QString& text)
{
	m_ui.FromLabel->setText(text);
	m_ui.FromLabel->setVisible(!text.isEmpty());
}


void CDoubleRangeSpinEdit::SetMaxLabelText(const QString& text)
{
	m_ui.ToLabel->setText(text);
	m_ui.ToLabel->setVisible(!text.isEmpty() && m_maxValueEnabled);
}


void CDoubleRangeSpinEdit::EnableMaxValue(bool enable)
{
	if (m_maxValueEnabled != enable){
		m_maxValueEnabled = enable;

		m_ui.ToLabel->setVisible(!m_ui.ToLabel->text().isEmpty() && m_maxValueEnabled);
		m_ui.SuffixLabel2->setVisible(!m_ui.SuffixLabel2->text().isEmpty() && m_maxValueEnabled);
		m_ui.ValueToSpinBox->setVisible(m_maxValueEnabled);
	}
}


void CDoubleRangeSpinEdit::SetValues(double minValue, double maxValue)
{
	m_ui.ValueFromSpinBox->setValue(minValue);
	m_ui.ValueToSpinBox->setValue(maxValue);
}


double CDoubleRangeSpinEdit::GetMinValue() const
{
	return m_ui.ValueFromSpinBox->value();
}


double CDoubleRangeSpinEdit::GetMaxValue() const
{
	return m_ui.ValueToSpinBox->value();
}


} // namespace iqtgui
