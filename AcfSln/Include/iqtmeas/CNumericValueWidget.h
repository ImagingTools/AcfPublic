/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef iqtmeas_CNumericValueWidget_included
#define iqtmeas_CNumericValueWidget_included


// Qt includes
#include<QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QWidget>
#else
#include <QtGui/QWidget>
#endif

// ACF includes
#include "imath/IUnitInfo.h"

#include "GeneratedFiles/iqtmeas/ui_CNumericValueWidget.h"


namespace iqtmeas
{


class CNumericValueWidget:
			public QWidget,
			protected Ui::CNumericValueWidget
{
	Q_OBJECT

public:
	CNumericValueWidget(QWidget* parentPtr = NULL, bool showSlilder = true, bool showButtons = true, int inputPolicy = 0);

	void SetUnitInfo(const QString& description, const imath::IUnitInfo* unitInfoPtr);

	double GetValue() const;
	void SetValue(double value);

	void SetupValueEditor(int editPrecision, double stepValue);

Q_SIGNALS:
	/**
		Will be emitted when user changed value.
	*/
	void ValueChanged();

protected Q_SLOTS:
	void on_ValueSB_valueChanged(double value);
	void on_ValueSlider_valueChanged(int value);
	void on_ValueSlider_sliderReleased();
	void on_MinButton_clicked();
	void on_MaxButton_clicked();

private:
	bool m_ignoreEvents;
	double m_unitMultiplicationFactor;
	double m_unitPrecisionFactor;
};


} // namespace iqtmeas


#endif // !iqtmeas_CNumericValueWidget_included



