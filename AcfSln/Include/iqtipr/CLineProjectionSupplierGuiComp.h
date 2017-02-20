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


#ifndef iqtipr_CLineProjectionSupplierGuiComp_included
#define iqtipr_CLineProjectionSupplierGuiComp_included


// ACF includes
#include <ifile/IFilePersistence.h>
#include <imod/IObserver.h>
#include <imod/TModelWrap.h>
#include <i2d/CPosition2d.h>
#include <iqtgui/IGuiObject.h>
#include <iqtgui/TDesignerGuiObserverCompBase.h>

// ACF-Solutions includes
#include <imeas/IDataSequenceProvider.h>
#include <imeas/CGeneralDataSequence.h>

#include <iqtinsp/TSupplierGuiCompBase.h>

#include <iqtipr/iqtipr.h>

#include <GeneratedFiles/iqtipr/ui_CLineProjectionSupplierGuiComp.h>


namespace iqtipr
{


class CLineProjectionSupplierGuiComp: public iqtinsp::TSupplierGuiCompBase<Ui::CLineProjectionSupplierGuiComp>
{
	Q_OBJECT

public:
	typedef iqtinsp::TSupplierGuiCompBase<Ui::CLineProjectionSupplierGuiComp> BaseClass;

	I_BEGIN_COMPONENT(CLineProjectionSupplierGuiComp);
		I_ASSIGN(m_projectionObserverCompPtr, "ProjectionObserver", "Observer for the generated line projection", true, "ProjectionObserver");
		I_ASSIGN_TO(m_projectionObserverGuiCompPtr, m_projectionObserverCompPtr, true);
	I_END_COMPONENT;

protected Q_SLOTS:
	void on_TestButton_clicked();
	void on_LoadParamsButton_clicked();
	void on_SaveParamsButton_clicked();

protected:
	// reimplemented (iqtinsp::TSupplierGuiCompBase)
	virtual QWidget* GetParamsWidget() const;

	// reimplemented (iqt2d::TViewExtenderCompBase)
	virtual void CreateShapes(int sceneId, Shapes& result);

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiModelAttached();
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet);

	// reimplemented (iqtgui::IGuiObject)
	virtual void OnGuiCreated();
	virtual void OnGuiDestroyed();

private:
	imod::TModelWrap<imeas::CGeneralDataSequence> m_projectionData;

	I_REF(imod::IObserver, m_projectionObserverCompPtr);
	I_REF(iqtgui::IGuiObject, m_projectionObserverGuiCompPtr);
};


} // namespace iqtipr


#endif // !iqtipr_CLineProjectionSupplierGuiComp_included


