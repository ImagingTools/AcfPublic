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
	virtual void UpdateModel() const;

protected Q_SLOTS:
	void OnParameterChanged();
	void OnFilterTypeChanged(int filterType);

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags = 0);

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


