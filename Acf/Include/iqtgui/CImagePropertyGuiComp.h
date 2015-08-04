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


#ifndef iqtgui_CImagePropertyGuiComp_included
#define iqtgui_CImagePropertyGuiComp_included


#include "iimg/IBitmap.h"

#include "iqtgui/TDesignerGuiObserverCompBase.h"
#include "GeneratedFiles/iqtgui/ui_CImagePropertyGuiComp.h"


namespace iqtgui
{


class CImagePropertyGuiComp:
			public iqtgui::TDesignerGuiObserverCompBase<
						Ui::CImagePropertyGuiComp, iimg::IBitmap>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CImagePropertyGuiComp, iimg::IBitmap> BaseClass;

	I_BEGIN_COMPONENT(CImagePropertyGuiComp);
	I_END_COMPONENT;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet);
};


} // namespace iqtgui


#endif // !iqtgui_CImagePropertyGuiComp_included


