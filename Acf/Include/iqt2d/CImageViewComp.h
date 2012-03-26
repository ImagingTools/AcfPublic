/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqt2d_CImageViewComp_included
#define iqt2d_CImageViewComp_included


// ACF includes
#include "icomp/CComponentBase.h"

#include "imod/CMultiModelDispatcherBase.h"

#include "ibase/TModelObserverCompWrap.h"

#include "iqtgui/TGuiComponentBase.h"
#include "iqtgui/TGuiObserverWrap.h"

#include "iview/CImageShape.h"
#include "iview/CAffiniteCalibrationShape.h"

#include "iqt2d/CViewProviderGuiComp.h"


namespace iqt2d
{


/**
	Show observed bitmap on the 2D-console.
	This class extends standard 2D-console to provide background bitmap object.
*/
class CImageViewComp:
	public ibase::TModelObserverCompWrap<
				iqtgui::TGuiObserverWrap<
							CViewProviderGuiComp, iview::CImageShape> >,
			protected imod::CMultiModelDispatcherBase
{
public:
	typedef ibase::TModelObserverCompWrap<
					iqtgui::TGuiObserverWrap<
								CViewProviderGuiComp, iview::CImageShape> > BaseClass;
	typedef imod::CMultiModelDispatcherBase BaseClass2;

	I_BEGIN_COMPONENT(CImageViewComp);
		I_REGISTER_INTERFACE(imod::IObserver);
		I_ASSIGN(m_calibrationProviderCompPtr, "CalibrationProvider", "Provider of 2D-calibration for the view", false, "CalibrationProvider");
		I_ASSIGN_TO(m_calibrationProviderModelCompPtr, m_calibrationProviderCompPtr, false);
	I_END_COMPONENT;

protected:
	// reimplemented (imod::CMultiModelDispatcherBase)
	void OnModelChanged(int modelId, int changeFlags, istd::IPolymorphic* updateParamsPtr);

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags);

	// reimplemented (iqtui::CGuiComponentBase)
	virtual void OnGuiCreated();

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_REF(i2d::ICalibrationProvider, m_calibrationProviderCompPtr);
	I_REF(imod::IModel, m_calibrationProviderModelCompPtr);

	iview::CAffiniteCalibrationShape m_calibrationShape;
};


} // namespace iqt2d


#endif // !iqt2d_CImageViewComp_included


