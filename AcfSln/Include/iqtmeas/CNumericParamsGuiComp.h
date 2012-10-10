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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iqtmeas_CNumericParamsGuiComp_included
#define iqtmeas_CNumericParamsGuiComp_included


// Qt includes
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>


// ACF includes
#include "istd/TPointerVector.h"

#include "imod/TModelWrap.h"

#include "iqtgui/TDesignerGuiObserverCompBase.h"


// ACF-Solutions includes
#include "imeas/INumericValue.h"

#include "iqtmeas/CNumericValueWidget.h"


namespace iqtmeas
{


class CNumericParamsGuiComp:
			public ibase::TModelObserverCompWrap<
						iqtgui::TGuiObserverWrap<
									iqtgui::TGuiComponentBase<QWidget>,
									imod::TSingleModelObserverBase<imeas::INumericValue> > >
{
	Q_OBJECT
public:
	typedef ibase::TModelObserverCompWrap<
				iqtgui::TGuiObserverWrap<
							iqtgui::TGuiComponentBase<QWidget>,
							imod::TSingleModelObserverBase<imeas::INumericValue> > > BaseClass;

	I_BEGIN_COMPONENT(CNumericParamsGuiComp);
		I_REGISTER_INTERFACE(imod::IModelEditor);
		I_ASSIGN(m_isSliderVisibleAttrPtr, "SliderVisible", "Enables slider control", true, true);
	I_END_COMPONENT;

	virtual ~CNumericParamsGuiComp();

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

protected:
	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiDestroyed();

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int changeFlags);

public Q_SLOTS:
	void OnValueChanged();

private:
	I_ATTR(bool, m_isSliderVisibleAttrPtr);

	istd::TPointerVector<CNumericValueWidget> m_valueWidgets;
};


} // namespace iqtmeas


#endif // !iqtmeas_CNumericParamsGuiComp_included


