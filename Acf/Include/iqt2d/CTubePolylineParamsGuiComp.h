/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqt2d_CTubePolylineParamsGuiComp_included
#define iqt2d_CTubePolylineParamsGuiComp_included


// ACF includes
#include "i2d/CTubePolyline.h"

#include "iview/CTubePolylineShape.h"

#include "iqt2d/TPolygonBasedParamsGuiComp.h"


namespace iqt2d
{


class CTubePolylineParamsGuiComp: public TPolygonBasedParamsGuiComp<iview::CTubePolylineShape, i2d::CTubePolyline>
{
	Q_OBJECT

public:
	typedef TPolygonBasedParamsGuiComp<iview::CTubePolylineShape, i2d::CTubePolyline> BaseClass;

	I_BEGIN_COMPONENT(CTubePolylineParamsGuiComp);
	I_END_COMPONENT;

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

protected Q_SLOTS:
	void OnParamsChanged();

	void on_InsertButton_clicked();
	void on_RemoveButton_clicked();
	void on_CopyButton_clicked();
	void on_PasteButton_clicked();

	void OnToolsButtonMenuActionTriggered(QAction* action);

protected:
	// reimplemented (iqt2d::TPolygonBasedParamsGuiComp)
	virtual void OnInsertNode();

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet);

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiRetranslate();
};


} // namespace iqt2d


#endif // !iqt2d_CTubePolylineParamsGuiComp_included
