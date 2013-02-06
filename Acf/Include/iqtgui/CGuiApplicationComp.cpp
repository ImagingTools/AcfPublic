/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqtgui/CGuiApplicationComp.h"


// Qt includes
#include <QtCore/QString>

#include <QtGui/QApplication>
#include <QtGui/QVBoxLayout>
#include <QtGui/QIcon>


namespace iqtgui
{


// reimplemented (iqtgui::IGuiApplication)

const iqtgui::IGuiObject* CGuiApplicationComp::GetApplicationGui() const
{
	if (m_mainGuiCompPtr.IsValid()){
		return m_mainGuiCompPtr.GetPtr();
	}

	return NULL;
}


// reimplemented (ibase::IApplication)

int CGuiApplicationComp::Execute(int argc, char** argv)
{
	int retVal = -1;

	if (BaseClass::InitializeApplication(argc, argv)){
		m_runtimeStatus.SetRuntimeStatus(ibase::IRuntimeStatusProvider::RS_STARTING);
	
		QByteArray appStyle;

		// parse arguments:
		for (int index = 1; index < argc; index++){
			QByteArray arg = argv[index];
			if (arg == "-style"){
				if (index+1 < argc){
					appStyle = argv[index+1];
				}
			}
		}
		QApplication::setStyle(appStyle);

		TryShowSplashScreen();

		if (m_mainGuiCompPtr.IsValid()){
			if (m_frameSpaceSizeAttrPtr.IsValid()){
				m_mainWidgetPtr.SetPtr(new QWidget());
				QVBoxLayout* frameLayout = new QVBoxLayout(m_mainWidgetPtr.GetPtr());

				frameLayout->setMargin(*m_frameSpaceSizeAttrPtr);

				// create application's main widget:
				m_mainGuiCompPtr->CreateGui(m_mainWidgetPtr.GetPtr());
			}
			else{
				m_mainGuiCompPtr->CreateGui(NULL);

				m_mainWidgetPtr.SetPtr(m_mainGuiCompPtr->GetWidget());
			}

			m_mainWidgetPtr->setWindowTitle(QCoreApplication::applicationName());
			m_mainWidgetPtr->setWindowIcon(QApplication::windowIcon());
		}

		HideSplashScreen();

		if (m_mainWidgetPtr.IsValid()){
			int uiStartMode = 0;
			if (m_uiStartModeAttrPtr.IsValid()){
				uiStartMode = *m_uiStartModeAttrPtr;
			}

			switch (uiStartMode){
				case 1:
					m_mainWidgetPtr->showFullScreen();
					break;

				case 2:
					m_mainWidgetPtr->showMinimized();
					break;

				case 3:
					m_mainWidgetPtr->showMaximized();
					break;

				default:
					m_mainWidgetPtr->show();
			}
		}

		if (m_mainWidgetPtr.IsValid()){
			m_runtimeStatus.SetRuntimeStatus(ibase::IRuntimeStatusProvider::RS_RUNNING);

			// start application loop:
			retVal = QApplication::exec();

			m_runtimeStatus.SetRuntimeStatus(ibase::IRuntimeStatusProvider::RS_SHUTDOWN);

			Q_ASSERT(m_mainGuiCompPtr.IsValid());
			m_mainGuiCompPtr->DestroyGui();

			m_mainWidgetPtr.Reset();
		}
	}

	return retVal;
}


QString CGuiApplicationComp::GetHelpText() const
{
	return "-style QtStyle\tname of Qt-specified style";
}


// public methods of the embedded class RuntimeStatus

CGuiApplicationComp::RuntimeStatus::RuntimeStatus()
	:m_status(RS_NONE)
{
}


void CGuiApplicationComp::RuntimeStatus::SetRuntimeStatus(IRuntimeStatusProvider::RuntimeStatus runtimeStatus)
{
	if (m_status != runtimeStatus){
		istd::CChangeNotifier changePtr(this);
		
		m_status = runtimeStatus;
	}
}


// reimplemented (ibase::IRuntimeStatusProvider)

ibase::IRuntimeStatusProvider::RuntimeStatus CGuiApplicationComp::RuntimeStatus::GetRuntimeStatus() const
{
	return m_status;
}


} // namespace iqtgui


