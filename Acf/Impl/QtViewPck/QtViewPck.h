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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef QtViewPck_included
#define QtViewPck_included


#include "icomp/TModelCompWrap.h"
#include "icomp/TMakeComponentWrap.h"

#include "iqt2d/TSceneExtenderDelegatorCompWrap.h"
#include "iqt2d/CSceneConnectorGuiComp.h"
#include "iqt2d/CSceneProviderGuiComp.h"
#include "iqt2d/CImageViewComp.h"
#include "iqt2d/CLine2dParamsGuiComp.h"
#include "iqt2d/CRectangleParamsGuiComp.h"
#include "iqt2d/CCircleParamsGuiComp.h"
#include "iqt2d/CAnnulusParamsGuiComp.h"
#include "iqt2d/CAnnulusSegmentParamsGuiComp.h"
#include "iqt2d/CQuadrangleParamsGuiComp.h"
#include "iqt2d/CSceneControllerGuiComp.h"
#include "iqt2d/CSceneBinderComp.h"
#include "iqt2d/CSelectableSceneExtenderComp.h"

#include "iview/CImageViewComp.h"


/**
	Qt scene visualization package.
*/
namespace QtViewPck
{


typedef iqt2d::CSceneExtenderDelegatorComp SceneExtenderDelegator;
typedef iqt2d::CSceneConnectorGuiComp SceneConnector;
typedef iqt2d::CSceneProviderGuiComp SceneProvider;
typedef iqt2d::CImageViewComp ImageView;
typedef iqt2d::CLine2dParamsGuiComp Line2dParamsGui;
typedef iqt2d::CRectangleParamsGuiComp RectangleParamsGui;
typedef iqt2d::CCircleParamsGuiComp CircleParamsGui;
typedef iqt2d::CAnnulusParamsGuiComp AnnulusParamsGui;
typedef iqt2d::CAnnulusSegmentParamsGuiComp AnnulusSegmentParamsGui;
typedef iqt2d::CQuadrangleParamsGuiComp QuadrangleParamsGui;
typedef iqt2d::CSceneControllerGuiComp SceneControllerGui;
typedef iqt2d::CSceneBinderComp SceneBinder;
typedef iqt2d::CSelectableSceneExtenderComp SelectableSceneExtender;
typedef iview::CImageViewComp ConsoleImageView;



} // namespace QtViewPck


#endif // !QtViewPck_included


