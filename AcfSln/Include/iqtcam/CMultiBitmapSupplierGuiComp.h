#ifndef iqtcam_CMultiBitmapSupplierGuiComp_included
#define iqtcam_CMultiBitmapSupplierGuiComp_included


// Qt includes
#include <QtCore/QTimer>

// ACF includes
#include "iqtinsp/TSupplierGuiCompBase.h"
#include "iqt/CBitmap.h"
#include "iipr/IMultiBitmapProvider.h"

#include "iqtcam/Generated/ui_CMultiBitmapSupplierGuiComp.h"


namespace iqtcam
{


class CMultiBitmapSupplierGuiComp
: public iqtinsp::TSupplierGuiCompBase<Ui::CMultiBitmapSupplierGuiComp>
{
	Q_OBJECT

public:
	typedef iqtinsp::TSupplierGuiCompBase<Ui::CMultiBitmapSupplierGuiComp> BaseClass;

	I_BEGIN_COMPONENT(CMultiBitmapSupplierGuiComp);
	I_ASSIGN(m_bitmapLoaderCompPtr, "BitmapLoader", "Saves bitmap to file", false, "BitmapLoader");
	I_ASSIGN(m_iconSize, "IconSize", "Maximum icon size in preview [px]", true, 48);
	I_ASSIGN(m_saveFilePrefix, "SaveFilePrefix", "Name prefix for \"Save file\" function. Current timestamp and picture number will be appended.", true, "");
	I_ASSIGN(m_saveFileExtension, "SaveFileExt", "", true, "png");
	I_END_COMPONENT;

	CMultiBitmapSupplierGuiComp();

	protected Q_SLOTS:
	void on_SnapImageButton_clicked();
	void on_LiveImageButton_toggled(bool checked);
	void on_SaveImageButton_clicked();
	void on_LoadParamsButton_clicked();
	void on_SaveParamsButton_clicked();
	void on_IconsView_currentItemChanged(QListWidgetItem * current, QListWidgetItem * previous);
	void OnTimerReady();

protected:
	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();

	// reimplemented (iqtinsp::TSupplierGuiCompBase)
	virtual QWidget* GetParamsWidget() const;

	// reimplemented (iqt2d::TViewExtenderCompBase)
	virtual void CreateShapes(int sceneId, Shapes& result);

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiModelAttached();
	virtual void UpdateGui(int updateFlags = 0);

	// reimplemented (imod::IObserver)
	virtual void AfterUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);

private:
	I_REF(iser::IFileLoader, m_bitmapLoaderCompPtr);
	I_ATTR(int, m_iconSize);
	I_ATTR(QString, m_saveFilePrefix);
	I_ATTR(QString, m_saveFileExtension);

	/** Fetches a selected bitmap from IMultiBitmapProvider */
	void SelectBitmap(int bitmapIdx);

	imod::TModelWrap<iqt::CBitmap> m_bitmap;
	QList<QIcon>m_icons;

	QTimer m_timer;

};


} // namespace iqtcam


#endif // !iqtcam_CMultiBitmapSupplierGuiComp_included


