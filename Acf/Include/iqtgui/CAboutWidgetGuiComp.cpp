/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqtgui/CAboutWidgetGuiComp.h"


namespace iqtgui
{


// protected methods

// reimplemented (iqtgui::CGuiComponentBase)

void CAboutWidgetGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();
	
	if (m_logoPathAttrPtr.IsValid()){
		LogoLabel->setPixmap(QPixmap(iqt::GetQString(*m_logoPathAttrPtr)));
		LogoLabel->setVisible(true);
	}
	else{
		LogoLabel->setVisible(false);
	}

	QString productName;
	QString applicationName;
	QString applicationSubname;
	QString applicationType;
	QString legalCopyright;

	if (m_applicationInfoCompPtr.IsValid()){
		// set version information
		QGridLayout* layoutPtr = dynamic_cast<QGridLayout*>(VersionsFrame->layout());
		if (layoutPtr != NULL){
			const iser::IVersionInfo& versionInfo = m_applicationInfoCompPtr->GetVersionInfo();

			if (m_versionIdsAttrPtr.IsValid()){
				int versionsCount = m_versionIdsAttrPtr.GetCount();

				for (int i = 0; i < versionsCount; ++i){
					int versionId = m_versionIdsAttrPtr[i];

					I_DWORD version;
					if (versionInfo.GetVersionNumber(versionId, version)){
						istd::CString description = (i < m_versionNamesAttrPtr.GetCount())?
									m_versionNamesAttrPtr[i]:
									versionInfo.GetVersionIdDescription(versionId);
						istd::CString versionText = versionInfo.GetEncodedVersionName(versionId, version);

						QLabel* descriptionLabelPtr = new QLabel(iqt::GetQString(description), VersionsFrame);
						layoutPtr->addWidget(descriptionLabelPtr, i, 0);

						QLabel* versionLabelPtr = new QLabel(iqt::GetQString(versionText), VersionsFrame);
						layoutPtr->addWidget(versionLabelPtr, i, 1);
					}
				}
			}
			else{
				int rowCount = 0;
				
				iser::IVersionInfo::VersionIds ids = versionInfo.GetVersionIds();
				for (		iser::IVersionInfo::VersionIds::const_iterator iter = ids.begin();
							iter != ids.end();
							++iter){
					int versionId = *iter;

					I_DWORD version;
					if (versionInfo.GetVersionNumber(versionId, version)){
						istd::CString description = versionInfo.GetVersionIdDescription(versionId);;
						istd::CString versionText = versionInfo.GetEncodedVersionName(versionId, version);

						QLabel* descriptionLabelPtr = new QLabel(iqt::GetQString(description), VersionsFrame);
						layoutPtr->addWidget(descriptionLabelPtr, rowCount, 0);

						QLabel* versionLabelPtr = new QLabel(iqt::GetQString(versionText), VersionsFrame);
						layoutPtr->addWidget(versionLabelPtr, rowCount++, 1);
					}
				}
			}
		}

		if (*m_showProductNameAttrPtr){
			productName = iqt::GetQString(m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_PRODUCT_NAME));
		}

		if (*m_showApplicationNameAttrPtr){
			applicationName = iqt::GetQString(m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_APPLICATION_NAME));
		}

		if (*m_showApplicationSubnameAttrPtr){
			applicationSubname = iqt::GetQString(m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_APPLICATION_SUBNAME));
		}

		if (*m_showProductTypeAttrPtr){
			applicationType = iqt::GetQString(m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_APPLICATION_TYPE));
		}

		if (*m_showLegalCopyrightAttrPtr){
			legalCopyright = iqt::GetQString(m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_LEGAL_COPYRIGHT));
		}
	}

	ProductNameLabel->setText(productName);
	ProductNameLabel->setVisible(!productName.isEmpty());
	ApplicationNameLabel->setText(applicationName);
	ApplicationNameLabel->setVisible(!applicationName.isEmpty());
	if (!applicationSubname.isEmpty() && !applicationType.isEmpty()){
		ApplicationTypeLabel->setText(applicationSubname + "(" + applicationType + ")");
	}
	else{
		ApplicationTypeLabel->setText(applicationSubname + applicationType);
	}
	ApplicationTypeLabel->setVisible(!applicationSubname.isEmpty() || !applicationType.isEmpty());

	CopyrightLabel->setText(legalCopyright);
	CopyrightLabel->setVisible(!legalCopyright.isEmpty());
}


} // namespace iqtgui


