/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#include "iqtipr/CProcessedMultiBitmapView.h"


// Qt includes
#if QT_VERSION >= 0x050000
#include <QtWidgets/QVBoxLayout>
#else
#include <QtGui/QVBoxLayout>
#endif

// ACF includes
#include "iqtipr/CProcessedBitmapView.h"


namespace iqtipr
{


CProcessedMultiBitmapView::CProcessedMultiBitmapView(QWidget* parent): QWidget(parent)
{
	setLayout(new QVBoxLayout());

	// default size
	resize(800,600);
}


void CProcessedMultiBitmapView::Update(const iimg::IMultiBitmapProvider* bitmapProviderPtr)
{
	for (int i = 0; i < m_views.count(); i++){
		m_views.at(i)->hide();
	}

	if (bitmapProviderPtr == NULL){
		return;
	}

	int bitmapCount = bitmapProviderPtr->GetBitmapsCount();
	while (m_views.count() < bitmapCount){
		CProcessedBitmapView* viewPtr = new CProcessedBitmapView(this);
		layout()->addWidget(viewPtr);
		m_views.append(viewPtr);
	}

	const iprm::IOptionsList* constraintsPtr = bitmapProviderPtr->GetBitmapListInfo();

	for (int i = 0; i < bitmapCount; i++){
		CProcessedBitmapView* viewPtr = m_views.at(i);

		viewPtr->SetBitmap(bitmapProviderPtr->GetBitmap(i));

		if (constraintsPtr != NULL){
			QString titleText = constraintsPtr->GetOptionDescription(i);
			if (titleText.isEmpty()){
				titleText = constraintsPtr->GetOptionName(i);
			}

			viewPtr->SetTitle(titleText);
		}

		viewPtr->show();
	}
}


} // namespace iqtipr
