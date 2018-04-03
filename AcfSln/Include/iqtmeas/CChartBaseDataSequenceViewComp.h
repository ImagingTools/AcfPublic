/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqtmeas_CChartBaseDataSequenceViewComp_included
#define iqtmeas_CChartBaseDataSequenceViewComp_included


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050800
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#endif

// ACF includes
#include <istd/TRange.h>
#include <iqtgui/TDesignerGuiObserverCompBase.h>
#include <imeas/IDataSequence.h>
#include <GeneratedFiles/iqtmeas/ui_CChartBaseDataSequenceViewComp.h>


namespace iqtmeas
{


class CChartBaseDataSequenceViewComp: public iqtgui::TDesignerGuiObserverCompBase<
			Ui::CChartBaseDataSequenceViewComp,
			imeas::IDataSequence>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CChartBaseDataSequenceViewComp,
				imeas::IDataSequence> BaseClass;

	I_BEGIN_COMPONENT(CChartBaseDataSequenceViewComp);
	I_END_COMPONENT;

	CChartBaseDataSequenceViewComp();

protected:
	// reimplemenented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet);
	virtual void OnGuiModelAttached();

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiDestroyed();

private:
#if QT_VERSION >= 0x050800
	QtCharts::QChart m_chart;
#endif
};


} // namespace iqtmeas


#endif // !iqtmeas_CChartBaseDataSequenceViewComp_included


