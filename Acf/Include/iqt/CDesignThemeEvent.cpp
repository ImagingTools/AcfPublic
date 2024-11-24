/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#include <iqt/CDesignThemeEvent.h>


namespace iqt
{


// public static methods

int CDesignThemeEvent::s_eventType = QEvent::MaxUser - 1;


// public methods

CDesignThemeEvent::CDesignThemeEvent(const QByteArray& themeId)
	:BaseClass(QEvent::Type(s_eventType)),
	m_themeId(themeId)
{
}


QByteArray CDesignThemeEvent::GetThemeId() const
{
	return m_themeId;
}


// reimplemented (QEvent)

#if QT_VERSION >= 0x600000

QEvent* CDesignThemeEvent::clone() const
{
	return new CDesignThemeEvent;
}
#endif


} // namespace iqt


