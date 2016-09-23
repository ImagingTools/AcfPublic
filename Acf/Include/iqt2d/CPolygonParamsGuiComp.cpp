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


#include <iqt2d/CPolygonParamsGuiComp.h>


namespace iqt2d
{


CPolygonParamsGuiComp::CPolygonParamsGuiComp() 
{
}


// protected slots

void CPolygonParamsGuiComp::OnParamsChanged()
{
	DoUpdateModel();
}


void CPolygonParamsGuiComp::OnActionTriggered(QAction* actionPtr)
{
	BaseClass::OnActionTriggered(actionPtr);
}


void CPolygonParamsGuiComp::on_InsertButton_clicked()
{
	OnInsertNode();
}


void CPolygonParamsGuiComp::on_RemoveButton_clicked()
{
	OnRemoveNode();
}


void CPolygonParamsGuiComp::on_CopyButton_clicked()
{
	OnCopyData();
}


void CPolygonParamsGuiComp::on_PasteButton_clicked()
{
	OnPasteData();
}


} // namespace iqt2d
