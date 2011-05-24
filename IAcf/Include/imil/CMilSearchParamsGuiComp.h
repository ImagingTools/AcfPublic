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


#ifndef imil_CMilSearchParamsGuiComp_h
#define imil_CMilSearchParamsGuiComp_h


#include "iqtgui/TDesignerGuiObserverCompBase.h"

#include "imil/CMilSearchParams.h"
#include "imil/Generated/ui_CMilSearchParamsGuiComp.h"

#include "imod/TModelWrap.h"

#include "iqt/CBitmap.h"


namespace imil
{


class CMilSearchParamsGuiComp: public iqtgui::TDesignerGuiObserverCompBase<Ui::CMilSearchParamsGuiComp, imil::CMilSearchParams>
{
    Q_OBJECT
public:
	typedef  iqtgui::TDesignerGuiObserverCompBase<Ui::CMilSearchParamsGuiComp, imil::CMilSearchParams> BaseClass;

	I_BEGIN_COMPONENT(CMilSearchParamsGuiComp)
	I_END_COMPONENT

	CMilSearchParamsGuiComp();

	// reimplemented (imod::IModelEditor)
	virtual void UpdateEditor(int updateFlags = 0);
	virtual void UpdateModel() const;

protected slots:
	void OnParameterChanged();
	void OnFilterTypeChanged(int filterType);

protected:
	// reimplemented (iqt::CGuiObjectBase)
	virtual void OnGuiCreated();

private:
	imod::TModelWrap<iqt::CBitmap> m_modelBitmap;
	QMap<int,int> m_speedMap;
	QMap<int,int> m_accuracyMap;
	QMap<int,int> m_detailLevelMap;
	QMap<int,int> m_polarityMap;
};


} // namespace imil


#endif // !imil_CMilSearchParamsGuiComp_h


