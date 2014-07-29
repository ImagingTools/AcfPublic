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


#ifndef iqtipr_CColorPatternComparatorGuiComp_included
#define iqtipr_CColorPatternComparatorGuiComp_included


// ACF includes
#include "istd/IInformationProvider.h"

// ACF-Solutions includes
#include "imeas/CGeneralDataSequence.h"
#include "imeas/INumericValueProvider.h"
#include "iqtinsp/TSupplierGuiCompBase.h"

#include "GeneratedFiles/iqtipr/ui_CColorPatternComparatorGuiComp.h"


namespace iqtipr
{


class CColorPatternComparatorGuiComp:
			public iqtinsp::TSupplierGuiCompBase<
						Ui::CColorPatternComparatorGuiComp,
						istd::IInformationProvider>
{
	Q_OBJECT

public:
	typedef iqtinsp::TSupplierGuiCompBase<
				Ui::CColorPatternComparatorGuiComp,
				istd::IInformationProvider> BaseClass;

	I_BEGIN_COMPONENT(CColorPatternComparatorGuiComp);
		I_ASSIGN(m_taskEnabledIdAttrPtr, "TaskEnabledId", "ID of the task enabled attribute", true, "CheckEnabled");
	I_END_COMPONENT;

protected Q_SLOTS:
	void on_TestButton_clicked();
	void on_TaskEnabledCB_toggled(bool);

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiCreated();

	virtual void UpdateModel();
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet);

	// reimplemented (iqtinsp::TSupplierGuiCompBase)
	virtual void OnSupplierParamsChanged();
	virtual QWidget* GetParamsWidget() const;

private:
	I_ATTR(QByteArray, m_taskEnabledIdAttrPtr);
};


} // namespace iqtipr


#endif // !iqtipr_CColorPatternComparatorGuiComp_included


