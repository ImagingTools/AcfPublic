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

#include "iview/CInteractivePolylineShape.h"

#include "iqt2d/TPolygonBasedParamsGuiComp.h"


namespace iqt2d
{


class CPolylineParamsGuiComp: public TPolygonBasedParamsGuiComp<iview::CInteractivePolylineShape, i2d::CPolyline>
{
	Q_OBJECT

public:
	typedef TPolygonBasedParamsGuiComp<iview::CInteractivePolylineShape, i2d::CPolyline> BaseClass;

	I_BEGIN_COMPONENT(CPolylineParamsGuiComp);
	I_END_COMPONENT;

protected Q_SLOTS:
	void OnParamsChanged();

	void on_InsertButton_clicked();
	void on_RemoveButton_clicked();
	void on_CopyButton_clicked();
	void on_PasteButton_clicked();
};


} // namespace iqt2d


#endif // !iqt2d_CPolylineParamsGuiComp_included
