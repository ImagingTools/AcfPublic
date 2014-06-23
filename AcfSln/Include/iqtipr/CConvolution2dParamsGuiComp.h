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


#ifndef iqtipr_CConvolution2dParamsGuiComp_included
#define iqtipr_CConvolution2dParamsGuiComp_included


// ACF includes
#include "iipr/IConvolutionKernel2d.h"
#include "iqtgui/TDesignerGuiObserverCompBase.h"

// ACF-Solutions includes
#include "GeneratedFiles/iqtipr/ui_CConvolution2dParamsGuiComp.h"


namespace iqtipr
{


class CConvolution2dParamsGuiComp: public iqtgui::TDesignerGuiObserverCompBase<
			Ui::CConvolution2dParamsGuiComp,
			iipr::IConvolutionKernel2d>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CConvolution2dParamsGuiComp,
				iipr::IConvolutionKernel2d> BaseClass;

	I_BEGIN_COMPONENT(CConvolution2dParamsGuiComp);
	I_END_COMPONENT;

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet);

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();

protected Q_SLOTS:
	void on_KernelWidthSpin_valueChanged(int value);
	void on_KernelHeightSpin_valueChanged(int value);
	void on_KernelTable_itemChanged(QTableWidgetItem* item);

private:
	void UpdateTableSize();
	void UpdateKernelSize() const;
};


} // namespace iqtipr


#endif // !iqtipr_CConvolution2dParamsGuiComp_included


