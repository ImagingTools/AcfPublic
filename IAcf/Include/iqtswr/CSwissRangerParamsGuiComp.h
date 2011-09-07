/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#ifndef iqtswr_CSwissRangerParamsGuiComp_included
#define iqtswr_CSwissRangerParamsGuiComp_included


#include "iswr/ISwissRangerParams.h"
#include "iswr/ISwissRangerConstrains.h"

#include "iqtgui/TDesignerGuiObserverCompBase.h"

#include "iqtswr/Generated/ui_CSwissRangerParamsGuiComp.h"


namespace iqtswr
{


class CSwissRangerParamsGuiComp: public iqtgui::TDesignerGuiObserverCompBase<
			Ui::CSwissRangerParamsGuiComp,
			iswr::ISwissRangerParams>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CSwissRangerParamsGuiComp,
				iswr::ISwissRangerParams> BaseClass;

	I_BEGIN_COMPONENT(CSwissRangerParamsGuiComp)
		I_ASSIGN(m_swissRangerConstrainsCompPtr, "SwissRangerConstrains", "Constrains of the swiss ranger sensor", false, "SwissRangerConstrains")
	I_END_COMPONENT

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags = 0);

	// reimplemented (iqtgui::CComponentBase)
	virtual void OnGuiCreated();

protected Q_SLOTS:
	void OnModelChanged();

private:
	I_REF(iswr::ISwissRangerConstrains, m_swissRangerConstrainsCompPtr);
};


} // namespace iqtswr


#endif // !iqtswr_CSwissRangerParamsGuiComp_included


