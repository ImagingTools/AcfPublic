/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqtgui_IStatusIconProvider_included
#define iqtgui_IStatusIconProvider_included


// Qt includes
#include <QtGui/QIcon>

// ACF includes
#include "istd/IChangeable.h"


namespace iqtgui
{


/**
	Extends standard information provider to provide additional visual informations.
*/
class IVisualStatusProvider: virtual public istd::IChangeable
{
public:
	/**
		Get icon describing current status.
	*/
	virtual QIcon GetStatusIcon() const = 0;
	/**
		Get status text.
		Typically it will be used as tool tip.
	*/
	virtual QString GetStatusText() const = 0;
};


} // namespace iqtgui


#endif // !iqtgui_IStatusIconProvider_included


