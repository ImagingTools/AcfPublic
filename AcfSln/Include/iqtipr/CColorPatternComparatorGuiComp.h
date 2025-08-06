/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqtipr_CColorPatternComparatorGuiComp_included
#define iqtipr_CColorPatternComparatorGuiComp_included


// ACF includes
#include <istd/IInformationProvider.h>

// ACF-Solutions includes
#include <imeas/CGeneralDataSequence.h>
#include <iipr/IFeaturesProvider.h>
#include <iqtinsp/TSupplierGuiCompBase.h>

#include <GeneratedFiles/iqtipr/ui_CColorPatternComparatorGuiComp.h>


namespace iqtipr
{


class CColorPatternComparatorGuiComp: public iqtinsp::TSupplierGuiCompBase<Ui::CColorPatternComparatorGuiComp>
{
	Q_OBJECT

public:
	typedef iqtinsp::TSupplierGuiCompBase<Ui::CColorPatternComparatorGuiComp> BaseClass;

	I_BEGIN_COMPONENT(CColorPatternComparatorGuiComp);
	I_END_COMPONENT;

	CColorPatternComparatorGuiComp();

signals:
	void OnSupplierParamsChangedSignal();

protected Q_SLOTS:
	void on_TestButton_clicked();

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet) override;

	// reimplemented (iqtinsp::TSupplierGuiCompBase)
	virtual void OnSupplierParamsChanged();
	virtual QWidget* GetParamsWidget() const;
};


} // namespace iqtipr


#endif // !iqtipr_CColorPatternComparatorGuiComp_included


