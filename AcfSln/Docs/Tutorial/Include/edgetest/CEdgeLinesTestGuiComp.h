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


#ifndef edgetest_CHelloWorldGuiComp_included
#define edgetest_CHelloWorldGuiComp_included


//Qt includes
#include <QtGui/QMessageBox>

// ACF includes
#include "iqtgui/TDesignerGuiCompBase.h" 
#include "iqt2d/TViewExtenderCompBase.h"
#include "iqt2d/IViewExtender.h"
#include "iedge/CEdgeLine.h"

#include "Generated/ui_CEdgeLinesTestGuiComp.h" 
 

namespace edgetest
{


/**
	Component used to test visualization of edge lines.
*/
class CEdgeLinesTestGuiComp: 
			public iqt2d::TViewExtenderCompBase< iqtgui::TDesignerGuiCompBase<Ui::CEdgeLinesTestGuiComp> >
{
 
     Q_OBJECT
 public:
     typedef iqt2d::TViewExtenderCompBase< iqtgui::TDesignerGuiCompBase<Ui::CEdgeLinesTestGuiComp> > BaseClass;
 
     I_BEGIN_COMPONENT(CEdgeLinesTestGuiComp);
	 I_REGISTER_INTERFACE(iqt2d::IViewExtender);
         //place for attributes, references, factories
		I_ASSIGN(m_aboutDialogPtr, "AboutDialog", "Gui object shown as about window", false, "AboutDialog");
		//I_ASSIGN(m_container, "AboutDialog", "Gui object shown as about window", false, "AboutDialog");
     I_END_COMPONENT;

	 CEdgeLinesTestGuiComp();
protected:
	/**
		Fill the container with random lines.
	*/
	void GenerateLines();

	// reimplemented (iqt2d::TViewExtenderCompBase)
	virtual void CreateShapes(int sceneId, Shapes& result);
 
 private Q_SLOTS:
     /**
     The function will be triggered on clicking the button.
     */
     void on_CreateLinesButton_clicked();

private:
	I_REF(IGuiObject, m_aboutDialogPtr); 
	//I_REF(IModel, m_container); 
 
	imod::TModelWrap<iedge::CEdgeLine::Container> m_model;
};


} // namespace edgetest


#endif // !edgetest_CHelloWorldGuiComp_included


