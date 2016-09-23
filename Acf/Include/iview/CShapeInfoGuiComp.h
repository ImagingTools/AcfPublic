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


#ifndef iview_CShapeInfoGuiComp_included
#define iview_CShapeInfoGuiComp_included


// ACF includes
#include <iqtgui/TDesignerGuiObserverCompBase.h>

#include <iview/IShapeStatusInfo.h>
#include <GeneratedFiles/iview/ui_CShapeInfoGuiComp.h>


namespace iview
{


class CShapeInfoGuiComp:
			public iqtgui::TDesignerGuiObserverCompBase<Ui::CShapeInfoGuiComp, IShapeStatusInfo>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<Ui::CShapeInfoGuiComp, IShapeStatusInfo> BaseClass;

	I_BEGIN_COMPONENT(CShapeInfoGuiComp);
	I_END_COMPONENT;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet);
};


} // namespace iview


#endif // !iview_CShapeInfoGuiComp_included


