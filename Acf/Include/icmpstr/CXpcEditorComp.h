#ifndef icmpstr_CXpcEditorComp_included
#define icmpstr_CXpcEditorComp_included


#include "iqtgui/TDesignerGuiObserverCompBase.h"
#include "icomp/CXpcModel.h"
#include "generated/ui_CXpcEditorComp.h"
#include <QtGui/QStringListModel>
#include "idoc/IDocumentManager.h"
#include <QtCore/QDir>


namespace icmpstr
{


/**
	Editor GUI component for the XpcModel.
*/
class CXpcEditorComp: 
	public iqtgui::TDesignerGuiObserverCompBase<Ui::XpcEditorComp, icomp::CXpcModel>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<Ui::XpcEditorComp, icomp::CXpcModel> BaseClass;

	CXpcEditorComp();

	I_BEGIN_COMPONENT(CXpcEditorComp);
	I_ASSIGN(m_docMgrPtr, "DocumentManager", "An object to provide current document file name, to handle relative paths", true, "");
	I_ASSIGN(m_confFileTypeInfo, "ConfigurationFileType", "File type description for filtering configuration files, ie. XPC", false, "");
	I_ASSIGN(m_packageFileTypeInfo, "PackageFileType", "File type description for filtering package files, ie. ARP", false, "");
	I_END_COMPONENT;

protected:
	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags = 0);

	// reimplemented (CGuiComponentBase)
	virtual void OnGuiCreated();

	private Q_SLOTS:
		//
		void on_button_add_cf_clicked();
		void on_button_add_pd_clicked();
		void on_button_add_pk_clicked();
		void on_button_remove_cf_clicked();
		void on_button_remove_pd_clicked();
		void on_button_remove_pk_clicked();
		void on_buttonEdit_cf_clicked();		
		void on_buttonEdit_pd_clicked();		
		void on_buttonEdit_pk_clicked();
		void OnModelLayoutChanged();
		void OnModelDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);

private:
	I_REF(idoc::IDocumentManager, m_docMgrPtr);
	I_REF(iser::IFileTypeInfo, m_confFileTypeInfo);
	I_REF(iser::IFileTypeInfo, m_packageFileTypeInfo);


	/** Retrieve strings from a table */
	QStringList GetStringList(int tableIdx) const;
	/** Fill a table with strings (replaces existing content)

	\param table table index in m_tablePointer
	*/
	void SetStringList(int tableIdx, QStringList);
	void PickFileNameForSelection(QListView* listView, bool SelectDirectories = false, iser::IFileTypeInfo* typeInfo = NULL);
	QStringListModel *m_guiModel[3];
	enum Section {SectionConfFiles = 0, SectionPackageDirectories, SectionPackages};
};


} // namespace icmpstr


#endif // !icmpstr_CXpcEditorComp_included

