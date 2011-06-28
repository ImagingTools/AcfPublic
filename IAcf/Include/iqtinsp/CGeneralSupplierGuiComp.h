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


#ifndef iqtinsp_CGeneralSupplierGuiComp_included
#define iqtinsp_CGeneralSupplierGuiComp_included


#include "iproc/ISupplier.h"

#include "iqtinsp/TSupplierGuiCompBase.h"

#include "iqtinsp/Generated/ui_CGeneralSupplierGuiComp.h"


namespace iqtinsp
{


class CGeneralSupplierGuiComp: public TSupplierGuiCompBase<
			Ui::CGeneralSupplierGuiComp,
			iproc::ISupplier>
{
	Q_OBJECT

public:
	typedef TSupplierGuiCompBase<
				Ui::CGeneralSupplierGuiComp,
				iproc::ISupplier> BaseClass;

	I_BEGIN_COMPONENT(CGeneralSupplierGuiComp);
	I_END_COMPONENT;

protected Q_SLOTS:
	void on_TestButton_clicked();
	void on_LoadParamsButton_clicked();
	void on_SaveParamsButton_clicked();

protected:
	// reimplemented (iqtinsp::TSupplierGuiCompBase)
	virtual QWidget* GetParamsWidget() const;

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiModelAttached();
	virtual void UpdateGui(int updateFlags = 0);
};


} // namespace iqtinsp


#endif // !iqtinsp_CGeneralSupplierGuiComp_included


