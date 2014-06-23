/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iqtipr_CGeneralSearchParamsGuiComp_included
#define iqtipr_CGeneralSearchParamsGuiComp_included


// ACF includes
#include "iqtgui/TDesignerGuiObserverCompBase.h"

// ACF-Solutions
#include "iipr/ISearchParams.h"

// Generated
#include "GeneratedFiles/iqtipr/ui_CGeneralSearchParamsGuiComp.h"


namespace iqtipr
{


class CGeneralSearchParamsGuiComp:
			public iqtgui::TDesignerGuiObserverCompBase<
						Ui::CGeneralSearchParamsGuiComp,
						iipr::ISearchParams>
{
	Q_OBJECT
public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CGeneralSearchParamsGuiComp,
				iipr::ISearchParams> BaseClass;

	I_BEGIN_COMPONENT(CGeneralSearchParamsGuiComp);
	I_END_COMPONENT;

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiModelAttached();
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet);

protected Q_SLOTS:
	void OnParamsChanged();
	void on_RotationCB_toggled(bool);
	void on_ScalingCB_toggled(bool);
};


} // namespace iqtipr


#endif // !iqtipr_CGeneralSearchParamsGuiComp_included
