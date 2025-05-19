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


#include <iqtgui/iqtgui.h>


namespace iqtgui
{


QMap<QString, QIcon> g_iconCache;


QIcon GetIconFromCache(const QString& iconName)
{
	if (g_iconCache.contains(iconName)){
		return g_iconCache[iconName];
	}

	return QIcon();
}


void AddIconToCache(const QString & iconName, const QIcon & icon)
{
	g_iconCache[iconName] = icon;
}


} // namespace iqtgui


