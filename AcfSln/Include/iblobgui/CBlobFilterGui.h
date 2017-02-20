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


#ifndef iblobgui_CBlobFilterGui_included
#define iblobgui_CBlobFilterGui_included


// QSF includes
#include <iblob/IBlobFilterParams.h>

#include <GeneratedFiles/iblobgui/ui_CBlobFilterGui.h>


namespace iblobgui
{


class CBlobFilterGui: public QWidget, public Ui::CFilterWidget
{
	Q_OBJECT
public:
	CBlobFilterGui(QWidget* parentPtr = 0);

	virtual void retranslateUi(QWidget* widgetPtr);

	void SetFilterInfo(const iblob::IBlobFilterParams::Filter& info);
	iblob::IBlobFilterParams::Filter GetFilterInfo() const;

	void SetSupportedProperties(const iprm::IOptionsList& features);

Q_SIGNALS:
	void FilterChanged();
	void RemoveFilter(QWidget* filterGui);

protected:
	void UpdateComboBoxes();
	void UpdateFilter();

protected Q_SLOTS:
	void OnFilterParameterChanged();
	void on_RemoveButton_clicked();
};


} // namespace iblobgui


#endif // !iblobgui_CFilterWidget_included
