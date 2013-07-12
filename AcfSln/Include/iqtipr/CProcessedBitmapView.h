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


#ifndef iqtipr_CProcessedBitmapView_included
#define iqtipr_CProcessedBitmapView_included


// ACF includes
#include "iview/IShapeStatusInfo.h"
#include "iview/CImageShape.h"
#include "imod/TModelWrap.h"
#include "imod/CSingleModelObserverBase.h"
#include "iimg/CBitmap.h"
#include "iqtgui/CHierarchicalCommand.h"


// Local includes
#include "Generated/ui_CProcessedBitmapView.h"


namespace iqtipr
{


class CProcessedBitmapView: 
			public QWidget/*, 
			public iview::IShapeStatusInfo*/
{
	Q_OBJECT
public:
	CProcessedBitmapView(QWidget* parent = NULL);

	void SetBitmap(const iimg::IBitmap* bitmapPtr);
	void SetTitle(const QString& title);

	//// reimplemented (iview::IShapeStatusInfo)
	//virtual QString GetInfoText() const;
	//virtual void SetInfoText(const QString& infoText);

protected Q_SLOTS:
	void on_SaveButton_clicked();

protected:
	Ui::CProcessedBitmapView m_ui;

	imod::TModelWrap<iimg::CBitmap> m_sourceImageModel;
	iview::CImageShape m_sourceImageShape;

	QString m_lastImagePath;

	iqtgui::CHierarchicalCommand m_toolBarCommands;
};


} // namespace iqtipr


#endif // !iqtipr_CProcessedBitmapView_included
