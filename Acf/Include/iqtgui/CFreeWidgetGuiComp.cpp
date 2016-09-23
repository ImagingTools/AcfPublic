/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include <iqtgui/CFreeWidgetGuiComp.h>


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QVBoxLayout>
#else
#include <QtGui/QVBoxLayout>
#endif


namespace iqtgui
{


// protected methods

// reimplemented (icomp::CComponentBase)

void CFreeWidgetGuiComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_slaveGuiCompPtr.IsValid()){
		m_mainWindowPtr.SetPtr(new QMainWindow);

		if (m_mainWindowPtr.IsValid()){
			QVBoxLayout* layoutPtr = new QVBoxLayout(m_mainWindowPtr.GetPtr());
			m_mainWindowPtr->setLayout(layoutPtr);
			m_mainWindowPtr->setWindowTitle(*m_titleAttrPtr);

			if (m_slaveGuiCompPtr->CreateGui(m_mainWindowPtr.GetPtr())){
				m_mainWindowPtr->setCentralWidget(m_slaveGuiCompPtr->GetWidget());
				m_mainWindowPtr->show();
			}
		}
	}
}


void CFreeWidgetGuiComp::OnComponentDestroyed()
{
	BaseClass::OnComponentDestroyed();

	if (m_slaveGuiCompPtr.IsValid() && m_slaveGuiCompPtr->IsGuiCreated()){
		m_slaveGuiCompPtr->DestroyGui();
	}

	m_mainWindowPtr.Reset();
}


} // namespace iqtgui


