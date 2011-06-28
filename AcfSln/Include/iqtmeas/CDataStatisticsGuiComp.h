/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iqtmeas_CDataStatisticsGuiComp_included
#define iqtmeas_CDataStatisticsGuiComp_included


// ACF includes
#include "iqtgui/TDesignerGuiObserverCompBase.h"


// ACF-Solutions includes
#include "imeas/IDataStatistics.h"

#include "iqtmeas/Generated/ui_CDataStatisticsGuiComp.h"


namespace iqtmeas
{


class CDataStatisticsGuiComp: public iqtgui::TDesignerGuiObserverCompBase<
			Ui::CDataStatisticsGuiComp,
			imeas::IDataStatistics>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CDataStatisticsGuiComp,
				imeas::IDataStatistics> BaseClass;

	I_BEGIN_COMPONENT(CDataStatisticsGuiComp);
	I_END_COMPONENT;

	// reimplemenented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags = 0);
};


} // namespace iqtmeas


#endif // !iqtmeas_CDataStatisticsGuiComp_included


