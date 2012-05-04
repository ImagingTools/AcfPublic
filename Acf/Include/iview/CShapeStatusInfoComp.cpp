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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iview/CShapeStatusInfoComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"


namespace iview
{


i2d::CVector2d CShapeStatusInfoComp::GetLogicalPosition() const
{
	return m_logicalPosition;
}


void CShapeStatusInfoComp::SetLogicalPosition(const i2d::CVector2d& logicalPosition)
{
	if (m_logicalPosition != logicalPosition){
		istd::CChangeNotifier changePtr(this);

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
		istd::CChangeNotifier changePtr(this);

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
		istd::CChangeNotifier changePtr(this);

		m_infoText = infoText;
	}
}


} // namespace iview



