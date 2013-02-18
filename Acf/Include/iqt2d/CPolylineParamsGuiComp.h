/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqt2d_CPolylineParamsGuiComp_included
#define iqt2d_CPolylineParamsGuiComp_included


// ACF includes
#include "i2d/CPolyline.h"

#include "iview/CPolylineShape.h"

#include "iqt2d/TPolygonBasedParamsGuiComp.h"


namespace iqt2d
{


class CPolylineParamsGuiComp: public TPolygonBasedParamsGuiComp<iview::CPolylineShape, i2d::CPolyline>
{
	Q_OBJECT

public:
	typedef TPolygonBasedParamsGuiComp<iview::CPolylineShape, i2d::CPolyline> BaseClass;

	I_BEGIN_COMPONENT(CPolylineParamsGuiComp);
	I_ASSIGN(m_showOrientationAttrPtr, "ShowOrientation", "Show orientation on display console", true, false);
	I_END_COMPONENT;

protected:
	// reimplemented (iqt2d::TShapeParamsGuiCompBase)
	virtual iview::CPolylineShape* CreateShape() const;

	protected Q_SLOTS:
	void OnParamsChanged();

	void on_InsertButton_clicked();
	void on_RemoveButton_clicked();
	void on_CopyButton_clicked();
	void on_PasteButton_clicked();
	void on_NodeParamsTable_itemSelectionChanged();
	void on_CloseLineCheckBox_stateChanged(int state);

	// reimplemented from TPolygonBasedParamsGuiComp<iview::CPolylineShape, i2d::CPolyline>
	void OnGuiModelAttached();
	void OnGuiModelDetached();
	void OnGuiCreated();

	void OnToolsButtonMenuActionTriggered(QAction* action);

private:
	/**
		Change state of a line close check box: disabled and hidden, according 
		to the attached model type (only visible for CPolyline) and list selection 
		(uncheckable if a list element is selected, always checkable).
	 */
	void UpdateClosedLineCheckBox(bool forceEnabled, bool forceHidden);

	I_ATTR(bool, m_showOrientationAttrPtr);
};


} // namespace iqt2d


#endif // !iqt2d_CPolylineParamsGuiComp_included
