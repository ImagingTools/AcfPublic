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


#ifndef iqtipr_CSearchGuiComp_included
#define iqtipr_CSearchGuiComp_included


// ACF includes
#include "imod/IModel.h"
#include "imod/IObserver.h"
#include "icomp/CComponentBase.h"
#include "iprm/IParamsSet.h"
#include "iproc/IProcessor.h"
#include "iipr/IFeaturesConsumer.h"
#include "iproc/IBitmapAcquisition.h"
#include "iqt2d/TSceneExtenderCompBase.h"
#include "iqtgui/TDesignerGuiCompBase.h"

#include "iqtipr/iqtipr.h"

#include "iqtipr/Generated/ui_CSearchGuiComp.h"


namespace iqtipr
{


class CSearchGuiComp: public iqt2d::TSceneExtenderCompBase<iqtgui::TDesignerGuiCompBase<Ui::CSearchGuiComp, QWidget> >
{
	Q_OBJECT
public:
	typedef iqt2d::TSceneExtenderCompBase<iqtgui::TDesignerGuiCompBase<Ui::CSearchGuiComp, QWidget> > BaseClass;

	I_BEGIN_COMPONENT(CSearchGuiComp)
		I_ASSIGN(m_searchResultsModelCompPtr, "SearchResults", "Search results model", true, "SearchResults");
		I_ASSIGN_TO(m_searchResultsCompPtr, m_searchResultsModelCompPtr, true);
		I_ASSIGN(m_paramsSetCompPtr, "ParamsSet", "Parameters set", false, "ParamsSet");
		I_ASSIGN_TO(m_paramsSetModelCompPtr, m_paramsSetCompPtr, false);
		I_ASSIGN(m_paramsSetGuiCompPtr, "ParamsSetGui", "Shows parameter set", false, "ParamsSetGui");
		I_ASSIGN_TO(m_paramsSetObserverCompPtr, m_paramsSetGuiCompPtr, false);
		I_ASSIGN(m_bitmapAcquisitionCompPtr, "BitmapAcquisition", "Gets image", true, "BitmapAcquisition");
		I_ASSIGN(m_searchProcessorCompPtr, "Processor", "Does model search in an image", true, "Processor");
		I_ASSIGN(m_bitmapCompPtr, "Bitmap", "Bitmap", true, "Bitmap");
		I_ASSIGN_TO(m_bitmapModelCompPtr, m_bitmapCompPtr, true);
	I_END_COMPONENT

	// reimplemented (iqt2d::TSceneExtenderCompBase)
	virtual void CreateShapes(int sceneId, bool inactiveOnly, Shapes& result);

protected:
	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiDestroyed();

protected Q_SLOTS:
	void on_FindButton_clicked();

private:
	void DoSearch();

private:
	I_ATTR(istd::CString, m_unitNameAttrPtr);
	I_REF(iproc::IProcessor, m_searchProcessorCompPtr);
	I_REF(imod::IModel, m_searchResultsModelCompPtr);
	I_REF(iipr::IFeaturesConsumer, m_searchResultsCompPtr);
	I_REF(iprm::IParamsSet, m_paramsSetCompPtr);
	I_REF(imod::IModel, m_paramsSetModelCompPtr);
	I_REF(iqtgui::IGuiObject, m_paramsSetGuiCompPtr);
	I_REF(imod::IObserver, m_paramsSetObserverCompPtr);
	I_REF(iproc::IBitmapAcquisition, m_bitmapAcquisitionCompPtr);
	I_REF(iimg::IBitmap, m_bitmapCompPtr);
	I_REF(imod::IModel, m_bitmapModelCompPtr);
};


} // namespace iqtipr


#endif // !iqtipr_CSearchGuiComp_included

