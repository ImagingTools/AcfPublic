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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iqtsig/CSampleContainerView.h"


// Qt includes
#include <QtGui/QPainter>


namespace iqtsig
{


CSampleContainerView::CSampleContainerView(QWidget* parentPtr)
:	BaseClass(parentPtr),
	m_displayedRange(0, 100)
{
}


void CSampleContainerView::SetDisplayedRange(const istd::CRange& range)
{
	m_displayedRange = range;
}


// reimplemented (imod::CSingleModelObserverBase)

void CSampleContainerView::OnUpdate(int updateFlags, istd::IPolymorphic* updateParamsPtr)
{
	BaseClass2::OnUpdate(updateFlags, updateParamsPtr);

	emit repaint();
}


// reimplemented (QWidget)

void CSampleContainerView::paintEvent(QPaintEvent* /*event*/)
{
	const imeas::IDataSequence* samplesPtr = GetObjectPtr();
	if (samplesPtr != NULL){
		QPainter painter(this);

		painter.setRenderHint(QPainter::Antialiasing);

		int rectWidth = width();
		int rectHeight = height();

		int samplesCount = samplesPtr->GetSamplesCount();
		QPolygonF polyline(samplesCount);

		for (int i = 0; i < samplesCount; ++i){
			polyline[i].setX(double(i * rectWidth) / samplesCount);
			double sample = samplesPtr->GetSample(i);
			polyline[i].setY((1 - m_displayedRange.GetAlphaFromValue(sample)) * rectHeight);
		}

		painter.drawPolyline(polyline);
	}
}


} // namespace iqtsig


