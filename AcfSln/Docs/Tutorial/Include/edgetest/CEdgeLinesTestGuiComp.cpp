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


#include "edgetest/CEdgeLinesTestGuiComp.h" 


// ACF includes
#include "iqtgui/CGuiComponentDialog.h"

#include "iedgegui/CEdgeLineContainerShape.h"


namespace edgetest
{


CEdgeLinesTestGuiComp::CEdgeLinesTestGuiComp()
{
	GenerateLines();
}


// protected methods

void CEdgeLinesTestGuiComp::GenerateLines()
{
	m_model.Reset();

	for(int c=0; c<2; c++){
		iedge::CEdgeLine line;
		for(int p=0; p<6; p++){
			double x = rand() & 255;
			double y = rand() & 255;
			double dx = (rand() & 255) - 127.5;
			double dy = (rand() & 255) - 127.5;
			double w = rand() * 1.0 / RAND_MAX;
			
			i2d::CVector2d pos(x,y), dif(dx,dy);

			iedge::CEdgeNode node(pos, dif, w);
			line.InsertNode(node);
		}
		m_model.PushBack(line);
	}
}


// reimplemented (iqt2d::TViewExtenderCompBase)

void CEdgeLinesTestGuiComp::CreateShapes(int /*sceneId*/, Shapes& result)
{
	iedgegui::CEdgeLineContainerShape* shapePtr = new iedgegui::CEdgeLineContainerShape;
	if (shapePtr != NULL){
		shapePtr->AssignToLayer(iview::IViewLayer::LT_INACTIVE);

		result.PushBack(shapePtr);

		m_model.AttachObserver(shapePtr);
	}
}


// private slots

void CEdgeLinesTestGuiComp::on_CreateLinesButton_clicked()
{
	GenerateLines();
}


} // namespace edgetest


