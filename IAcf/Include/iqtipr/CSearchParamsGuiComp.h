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


#ifndef iqtipr_CSearchParamsGuiComp_h
#define iqtipr_CSearchParamsGuiComp_h


#include "imod/TModelWrap.h"

#include "iipr/CSearchParams.h"

#include "iqtgui/TDesignerGuiObserverCompBase.h"
#include "iqt/CBitmap.h"

#include "iqtipr/Generated/ui_CSearchParamsGuiComp.h"


namespace iqtipr
{


class CSearchParamsGuiComp: public iqtgui::TDesignerGuiObserverCompBase<Ui::CSearchParamsGuiComp, iipr::ISearchParams>
{
    Q_OBJECT
public:
	typedef  iqtgui::TDesignerGuiObserverCompBase<Ui::CSearchParamsGuiComp, iipr::ISearchParams> BaseClass;

	I_BEGIN_COMPONENT(CSearchParamsGuiComp)
		I_ASSIGN(m_modelViewCompPtr, "ModelView", "Model view", false, "ModelView");
		I_ASSIGN_TO(m_modelObserverCompPtr, m_modelViewCompPtr, false);
	I_END_COMPONENT

		// reimplemented (imod::IModelEditor)
	virtual void UpdateEditor(int updateFlags = 0);
	virtual void UpdateModel() const;

protected slots:
	void OnParameterChanged();

protected:
	// reimplemented (iqt::CGuiObjectBase)
	virtual void OnGuiCreated();
	virtual void OnGuiDestroyed();

private:
	imod::TModelWrap<iqt::CBitmap> m_modelBitmap;

	I_REF(iqtgui::IGuiObject, m_modelViewCompPtr);
	I_REF(imod::IObserver, m_modelObserverCompPtr);
};


} // namespace iqtipr


#endif // !iqtipr_CSearchParamsGuiComp_h

