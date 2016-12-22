/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef icalibgui_CSimpleLensCorrectionEditorComp_included
#define icalibgui_CSimpleLensCorrectionEditorComp_included


// ACF includes
#include <imod/CMultiModelDispatcherBase.h>
#include <iqt2d/TShapeParamsGuiCompBase.h>

// ACF-Solutions includes
#include <icalib/CSimpleLensCorrection.h>
#include <GeneratedFiles/icalibgui/ui_CSimpleLensCorrectionEditorComp.h>


namespace icalibgui
{


class CSimpleLensCorrectionEditorComp:
			public iqtgui::TDesignerGuiObserverCompBase<Ui::CSimpleLensCorrectionEditorComp, icalib::CSimpleLensCorrection>,
			protected imod::CMultiModelDispatcherBase
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<Ui::CSimpleLensCorrectionEditorComp, icalib::CSimpleLensCorrection> BaseClass;

	I_BEGIN_COMPONENT(CSimpleLensCorrectionEditorComp);
		I_ASSIGN(m_calibProviderCompPtr, "CalibrationProvider", "Optional calibration provider for calibrate button", false, "CalibrationProvider");
		I_ASSIGN_TO(m_calibProviderModelCompPtr, m_calibProviderCompPtr, false);
	I_END_COMPONENT;

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet);

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiDestroyed();

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnModelChanged(int modelId, const istd::IChangeable::ChangeSet& changeSet);

protected Q_SLOTS:
	void on_CalibrateButton_clicked();
	void OnParamsChanged(double value);

private:
	I_REF(i2d::ICalibrationProvider, m_calibProviderCompPtr);
	I_REF(imod::IModel, m_calibProviderModelCompPtr);
};


} // namespace icalibgui


#endif // !icalibgui_CSimpleLensCorrectionEditorComp_included


