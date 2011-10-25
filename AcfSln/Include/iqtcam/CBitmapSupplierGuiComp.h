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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iqtcam_CBitmapSupplierGuiComp_included
#define iqtcam_CBitmapSupplierGuiComp_included


// ACF includes
#include "iser/IFileLoader.h"
#include "imod/IObserver.h"
#include "imod/TModelWrap.h"
#include "iqt/CBitmap.h"
#include "iqtgui/IGuiObject.h"
#include "iqtgui/TDesignerGuiObserverCompBase.h"

#include "iipr/IBitmapProvider.h"

#include "iqtinsp/TSupplierGuiCompBase.h"

#include "iqtcam/iqtcam.h"

#include "iqtcam/Generated/ui_CBitmapSupplierGuiComp.h"


namespace iqtcam
{


class CBitmapSupplierGuiComp: public iqtinsp::TSupplierGuiCompBase<Ui::CBitmapSupplierGuiComp>
{
	Q_OBJECT

public:
	typedef iqtinsp::TSupplierGuiCompBase<Ui::CBitmapSupplierGuiComp> BaseClass;

	I_BEGIN_COMPONENT(CBitmapSupplierGuiComp);
		I_ASSIGN(m_bitmapLoaderCompPtr, "BitmapLoader", "Saves bitmap to file", false, "BitmapLoader");
	I_END_COMPONENT;

protected Q_SLOTS:
	void on_SnapImageButton_clicked();
	void on_SaveImageButton_clicked();
	void on_LoadParamsButton_clicked();
	void on_SaveParamsButton_clicked();

protected:
	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();

	// reimplemented (iqtinsp::TSupplierGuiCompBase)
	virtual QWidget* GetParamsWidget() const;

	// reimplemented (iqt2d::TSceneExtenderCompBase)
	virtual void CreateShapes(int sceneId, bool inactiveOnly, Shapes& result);

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiModelAttached();
	virtual void UpdateGui(int updateFlags = 0);

	// reimplemented (imod::IObserver)
	virtual void AfterUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);

private:
	I_REF(iser::IFileLoader, m_bitmapLoaderCompPtr);

	imod::TModelWrap<iqt::CBitmap> m_bitmap;
};


} // namespace iqtcam


#endif // !iqtcam_CBitmapSupplierGuiComp_included


