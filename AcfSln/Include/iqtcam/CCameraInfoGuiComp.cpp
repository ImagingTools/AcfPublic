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


#include "iqtcam/CCameraInfoGuiComp.h"


namespace iqtcam
{


// reimplemented (iqtgui::TGuiObserverWrap)

void CCameraInfoGuiComp::UpdateGui(int /*updateFlags*/)
{
	iprm::ISelectionParam* paramPtr = GetObjectPtr();

	if (paramPtr != NULL && m_cameraInfoProviderComp.IsValid()){
		int cameraIndex = paramPtr->GetSelectedOptionIndex();

		TableView->setUpdatesEnabled(false);

		TableView->clear();
		TableView->setRowCount(0);
		TableView->setColumnCount(1);

		AddItem(cameraIndex, icam::ICameraInfo::CA_VENDOR, tr("Vendor"));
		AddItem(cameraIndex, icam::ICameraInfo::CA_MODEL, tr("Model"));
		AddItem(cameraIndex, icam::ICameraInfo::CA_DEVICE_CLASS, tr("Class"));
		AddItem(cameraIndex, icam::ICameraInfo::CA_DEVICE_VERSION, tr("Version"));
		AddItem(cameraIndex, icam::ICameraInfo::CA_FIRMWARE_VERSION, tr("Firmware"));
		AddItem(cameraIndex, icam::ICameraInfo::CA_DEVICE_ID, tr("ID"));
		AddItem(cameraIndex, icam::ICameraInfo::CA_DEVICE_NAME, tr("Name"));
		AddItem(cameraIndex, icam::ICameraInfo::CA_SERIAL_NUMBER, tr("Serial number"));
		AddItem(cameraIndex, icam::ICameraInfo::CA_IP_ADDRESS, tr("IP address"));
		AddItem(cameraIndex, icam::ICameraInfo::CA_MAC_ADDRESS, tr("MAC address"));
		AddItem(cameraIndex, icam::ICameraInfo::CA_PORT, tr("Port number"));
		AddItem(cameraIndex, icam::ICameraInfo::CA_MAX_WIDTH, tr("Sensor width"));
		AddItem(cameraIndex, icam::ICameraInfo::CA_MAX_HEIGHT, tr("Sensor height"));

		TableView->setUpdatesEnabled(true);
	}
}


// private

void CCameraInfoGuiComp::AddItem(int cameraIndex, icam::ICameraInfo::CameraAttribute attr, const QString& attrName)
{
	QString textValue = m_cameraInfoProviderComp->GetCameraAttribute(cameraIndex, attr);

	QTableWidgetItem* keyPtr = new QTableWidgetItem(attrName);
	QTableWidgetItem* valuePtr = new QTableWidgetItem(textValue);

	int row = TableView->rowCount();
	TableView->insertRow(row);

	TableView->setVerticalHeaderItem(row, keyPtr);
	TableView->setItem(row, 0, valuePtr);
}


} // namespace iqtcam
