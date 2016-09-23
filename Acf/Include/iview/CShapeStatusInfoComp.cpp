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


#include <iview/CShapeStatusInfoComp.h>


// ACF includes
#include <istd/CChangeNotifier.h>
#include <iview/IDisplay.h>


namespace iview
{


// public methods

CShapeStatusInfoComp::CShapeStatusInfoComp()
	:m_logicalPosition(0, 0),
	m_pixelPosition(0, 0)
{
}


// reimplemented (iview::IShapeStatusInfo)

i2d::CVector2d CShapeStatusInfoComp::GetLogicalPosition() const
{
	return m_logicalPosition;
}


void CShapeStatusInfoComp::SetLogicalPosition(const i2d::CVector2d& logicalPosition)
{
	if (m_logicalPosition != logicalPosition){
		static const istd::IChangeable::ChangeSet changeSet(IDisplay::CS_CONSOLE, i2d::IObject2d::CF_OBJECT_POSITION);
		istd::CChangeNotifier notifier(this, &changeSet);
		Q_UNUSED(notifier);

		m_logicalPosition = logicalPosition;
	}
}


i2d::CVector2d CShapeStatusInfoComp::GetPixelPosition() const
{
	return m_pixelPosition;
}


void CShapeStatusInfoComp::SetPixelPosition(const i2d::CVector2d& pixelPosition)
{
	if (m_pixelPosition != pixelPosition){
		static const istd::IChangeable::ChangeSet changeSet(IDisplay::CS_CONSOLE);
		istd::CChangeNotifier notifier(this, &changeSet);
		Q_UNUSED(notifier);

		m_pixelPosition = pixelPosition;
	}
}


QString CShapeStatusInfoComp::GetInfoText() const
{
	return m_infoText;
}


void CShapeStatusInfoComp::SetInfoText(const QString& infoText)
{
	if (m_infoText != infoText){
		static const istd::IChangeable::ChangeSet changeSet(IDisplay::CS_CONSOLE);
		istd::CChangeNotifier notifier(this, &changeSet);
		Q_UNUSED(notifier);

		m_infoText = infoText;
	}
}


} // namespace iview



