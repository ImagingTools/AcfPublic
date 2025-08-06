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


#include <iqtinsp/CGeneralSupplierGuiComp.h>


namespace iqtinsp
{


CGeneralSupplierGuiComp::CGeneralSupplierGuiComp()
{
}


// protected methods

void CGeneralSupplierGuiComp::ShowResultsBox(bool on)
{
	BaseClass::ResultsGroupBox->setVisible(on);
}


// reimplemented (iqtgui::CGuiComponentBase)

void CGeneralSupplierGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	connect(TestButton, SIGNAL(clicked()), this, SLOT(OnTestButtonClicked()), Qt::QueuedConnection);
	connect(this, SIGNAL(OnSupplierParamsChangedSignal()), SLOT(OnTestButtonClicked()), Qt::QueuedConnection);
}


void CGeneralSupplierGuiComp::OnGuiDestroyed()
{
	disconnect(TestButton, SIGNAL(clicked()), this, SLOT(OnTestButtonClicked()));

	BaseClass::OnGuiDestroyed();
}


void CGeneralSupplierGuiComp::OnGuiDesignChanged()
{
	BaseClass::OnGuiDesignChanged();

	AutoTestButton->setIcon(GetIcon(":/Icons/AutoUpdate"));
	TestButton->setIcon(GetIcon(":/Icons/Play"));
}


void CGeneralSupplierGuiComp::UpdateGui(const istd::IChangeable::ChangeSet & changeSet)
{
	BaseClass::UpdateGui(changeSet);

	const bool enableAutoTest = !m_disableAutoTestAttrPtr.IsValid() || !*m_disableAutoTestAttrPtr;
	AutoTestButton->setEnabled(enableAutoTest);
	AutoTestButton->setVisible(enableAutoTest);

	if (m_buttonLabelCompPtr.IsValid()) {
		TestButton->setText(m_buttonLabelCompPtr->GetText());
	}
}


// reimplemented (iqtinsp::TSupplierGuiCompBase)

void CGeneralSupplierGuiComp::OnSupplierParamsChanged()
{
	if (BaseClass::IsGuiCreated() && BaseClass::AutoTestButton->isChecked())
		Q_EMIT OnSupplierParamsChangedSignal();
}


// protected slots

void CGeneralSupplierGuiComp::OnTestButtonClicked()
{
	Test();
	QCoreApplication::removePostedEvents(this, QEvent::MetaCall); // prevents endless testing if test button is clicked continuously
}


void CGeneralSupplierGuiComp::on_LoadParamsButton_clicked()
{
	LoadParams();
}


void CGeneralSupplierGuiComp::on_SaveParamsButton_clicked()
{
	SaveParams();
}


} // namespace iqtinsp


