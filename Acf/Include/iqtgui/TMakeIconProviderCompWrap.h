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


#pragma once


// ACF includes
#include <iqtgui/iqtgui.h>
#include <iqtgui/TDesignSchemaHandlerWrap.h>
#include <iqtgui/CIconProvider.h>


namespace iqtgui
{


template <class Base>
class TMakeIconProviderCompWrap: public TDesignSchemaHandlerWrap<Base>, public CIconProvider
{
public:
	typedef Base BaseClass;

	// reimplemented (ibase::TDesignSchemaHandlerWrap)
	virtual void OnDesignSchemaChanged(const QByteArray& themeId) override;
};


// reimplemented (ibase::TDesignSchemaHandlerWrap)

template <class Base>
void TMakeIconProviderCompWrap<Base>::OnDesignSchemaChanged(const QByteArray& themeId)
{
	SetThemeId(themeId);
}


} // namespace iqtgui


