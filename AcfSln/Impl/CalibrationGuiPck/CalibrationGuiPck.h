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


#ifndef CalibrationGuiPck_included
#define CalibrationGuiPck_included


// ACF includes
#include <icomp/TModelCompWrap.h>
#include <ibase/TMakeModelObserverCompWrap.h>

// ACF-Solutions includes
#include <icalibgui/CNoneCalibrationShape.h>
#include <icalibgui/CAffiniteCalibrationShape.h>
#include <icalibgui/CPerspectiveCalibrationShape.h>
#include <icalibgui/CGeneralCalibrationShape.h>
#include <icalibgui/CPerspectiveCalibEditorComp.h>
#include <icalibgui/CSimpleLensCorrectionEditorComp.h>


/**
	Qt scene visualization package.
*/
namespace CalibrationGuiPck
{


typedef icomp::TMakeComponentWrap<icalibgui::CNoneCalibrationShape, iview::IShape, imod::IObserver, iview::IVisualizable, iview::ITouchable> NoneCalibrationShape;
typedef ibase::TMakeModelObserverCompWrap<icalibgui::CAffiniteCalibrationShape, iview::IShape, imod::IObserver, iview::IVisualizable, iview::ITouchable> AffiniteCalibrationShape;
typedef ibase::TMakeModelObserverCompWrap<icalibgui::CPerspectiveCalibrationShape, iview::IShape, imod::IObserver, iview::IVisualizable, iview::ITouchable> PerspectiveCalibrationShape;
typedef ibase::TMakeModelObserverCompWrap<icalibgui::CGeneralCalibrationShape, iview::IShape, imod::IObserver, iview::IVisualizable, iview::ITouchable> GeneralCalibrationShape;
typedef icalibgui::CPerspectiveCalibEditorComp PerspectiveCalibEditor;
typedef icalibgui::CSimpleLensCorrectionEditorComp SimpleLensCorrectionEditor;


} // namespace CalibrationGuiPck


#endif // !CalibrationGuiPck_included


