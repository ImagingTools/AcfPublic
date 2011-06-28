/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
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


