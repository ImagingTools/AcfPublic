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


#ifndef iqtgui_IIconProvider_included
#define iqtgui_IIconProvider_included


// Qt includes
#include <QtGui/QIcon>


// ACF includes
#include <istd/IPolymorphic.h>
#include <iqtgui/iqtgui.h>


namespace iqtgui
{


/**
	This interface provides acces to an icon.
*/
class IIconProvider: virtual public istd::IPolymorphic
{
public:
	/**
		Gets the number of icons in the collection.
	*/
	virtual int GetIconCount() const = 0;

	/**
		Gets icon with the index \c iconIndex from collection.
	*/
	virtual QIcon GetIcon(int iconIndex) const = 0;
};


} // namespace iqtgui


#endif // !iqtgui_IIconProvider_included

