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


#ifndef ihotfgui_CDirectoryMonitorParamsGui_included
#define ihotfgui_CDirectoryMonitorParamsGui_included


// ACF includes
#include <iqtgui/TDesignerGuiObserverCompBase.h>


// AcfSln includes
#include <ihotf/IDirectoryMonitorParams.h>
#include <GeneratedFiles/ihotfgui/ui_CDirectoryMonitorParamsGui.h>


namespace ihotfgui
{


class CDirectoryMonitorParamsGui: public iqtgui::TDesignerGuiObserverCompBase<
			Ui::CDirectoryMonitorParamsGui,
			ihotf::IDirectoryMonitorParams>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CDirectoryMonitorParamsGui,
				ihotf::IDirectoryMonitorParams> BaseClass;

	I_BEGIN_COMPONENT(CDirectoryMonitorParamsGui);
	I_END_COMPONENT;

protected Q_SLOTS:
	void on_FilesCheck_toggled(bool isChecked);
	void on_DirsCheck_toggled(bool isChecked);
	void on_DrivesCheck_toggled(bool isChecked);
	void on_ModifiedCheck_toggled(bool isChecked);
	void on_AddedCheck_toggled(bool isChecked);
	void on_RemovedCheck_toggled(bool isChecked);
	void on_AttributesCheck_toggled(bool isChecked);
	void on_PoolingIntervallSpin_valueChanged(double value);
	void on_AddAcceptPatternButton_clicked();
	void on_RemoveAcceptPatternButton_clicked();
	void on_AcceptPatternsList_itemSelectionChanged();
	void on_AcceptPatternsList_itemChanged(QTreeWidgetItem* item, int column);
	void on_AddIgnorePatternButton_clicked();
	void on_RemoveIgnorePatternButton_clicked();
	void on_IgnorePatternsList_itemSelectionChanged();
	void on_IgnorePatternsList_itemChanged(QTreeWidgetItem* item, int column);
	void OnModelUpdate();

protected:
	// reimplemenented (iqtgui::TGuiObserverWrap)
	virtual void UpdateModel() const;
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet);

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();

private:
	void AddPattern(const QString& filter, QTreeWidget* treeView);
	void RemoveSelectedPatterns(QTreeWidget* treeView);
	void ResetEditor();
};


} // namespace ihotfgui


#endif // !ihotfgui_CDirectoryMonitorParamsGui_included


