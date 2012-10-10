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


#ifndef iqtmeas_CNumericValueWidget_included
#define iqtmeas_CNumericValueWidget_included


// Qt includes
#include <QtGui/QWidget>


#include "imeas/IUnitInfo.h"

#include "generated/ui_CNumericValueWidget.h"


namespace iqtmeas
{


class CNumericValueWidget:
			public QWidget,
			protected Ui::CNumericValueWidget
{
	Q_OBJECT

public:
	CNumericValueWidget(QWidget* parentPtr = NULL, bool showSlilder = true);

	void SetUnitInfo(const QString& description, const imeas::IUnitInfo& unitInfo);

	double GetValue() const;
	void SetValue(double value);

Q_SIGNALS:
	/**
		Will be emited when user changed value.
	*/
	void ValueChanged();

protected Q_SLOTS:
	void on_ValueSB_valueChanged(double value);
	void on_ValueSlider_valueChanged(int value);

private:
	bool m_ignoreEvents;
	double m_unitMultiplicationFactor;
	double m_unitPrecisionFactor;
};


} // namespace iqtmeas


#endif // !iqtmeas_CNumericValueWidget_included



