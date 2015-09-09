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


#include "iqtmeas/CDataStatisticsGuiComp.h"


namespace iqtmeas
{


// reimplemenented (iqtgui::TGuiObserverWrap)

void CDataStatisticsGuiComp::UpdateGui(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	Q_ASSERT(IsGuiCreated());

	imeas::IDataStatistics* objectPtr = GetObservedObject();
	if (objectPtr != NULL){
		AverageLabel->setText(QString("%1").arg(objectPtr->GetAverage(), 4, 'f', 4));
		MedianLabel->setText(QString("%1").arg(objectPtr->GetMedian(), 4, 'f', 4));
		StandardDeviationLabel->setText(QString("%1").arg(objectPtr->GetStandardDeviation(), 4, 'f', 4));
		MinimumLabel->setText(QString("%1").arg(objectPtr->GetDataBoundaries().GetMinValue(), 4, 'f', 4));
		MaximumLabel->setText(QString("%1").arg(objectPtr->GetDataBoundaries().GetMaxValue(), 4, 'f', 4));
	}
}


} // namespace iqtmeas


