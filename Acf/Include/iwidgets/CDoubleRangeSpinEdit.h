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


#ifndef iwidgets_CDoubleRangeSpinEdit_included
#define iwidgets_CDoubleRangeSpinEdit_included


// Local includes
#include <GeneratedFiles/iwidgets/ui_CDoubleRangeSpinEdit.h>


namespace iwidgets
{


class CDoubleRangeSpinEdit: public QWidget
{
	Q_OBJECT
public:
	explicit CDoubleRangeSpinEdit(QWidget *parent = NULL);

	// public interface
	void SetMinRange(double minFrom, double minTo);
	void SetMaxRange(double maxFrom, double maxTo);
	void SetRange(double from, double to);

	void SetDecimals(int count);
	void SetSingleStep(double step);
	void SetSuffixText(const QString& suffix);
	void SetMinLabelText(const QString& text);
	void SetMaxLabelText(const QString& text);

	void EnableMaxValue(bool enable = true);
	void EnableValdation(bool enable = true);

	void SetValues(double minValue, double maxValue);
	double GetMinValue() const;
	double GetMaxValue() const;

Q_SIGNALS:
	void ValuesChanged();

protected Q_SLOTS:
	void OnMinValueChanged(double);
	void OnMaxValueChanged(double);

protected:
	Ui::CDoubleRangeSpinEdit m_ui;

	bool m_maxValueEnabled;
	bool m_validateRangesEnabled;
};


} // namespace iwidgets


#endif // !iwidgets_CDoubleRangeSpinEdit_included
