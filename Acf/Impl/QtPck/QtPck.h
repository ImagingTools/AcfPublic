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


#ifndef QtPck_included
#define QtPck_included


#include <icomp/TModelCompWrap.h>
#include <icomp/TMakeComponentWrap.h>

#include <iqt/CSettingsSerializerComp.h>
#include <iqt/CApplicationSettingsProviderComp.h>
#include <iqt/CIniSettingsProviderComp.h>
#include <iqt/CClipboardSerializerComp.h>
#include <iqt/CTranslationManagerComp.h>



/**
	Standard Qt package.
*/
namespace QtPck
{



typedef iqt::CSettingsSerializerComp SettingsSerializer;
typedef iqt::CApplicationSettingsProviderComp ApplicationSettingsProvider;
typedef iqt::CIniSettingsProviderComp IniSettingsProvider;
typedef iqt::CClipboardSerializerComp ClipboardSerializer;
typedef icomp::TModelCompWrap<iqt::CTranslationManagerComp> TranslationManager;


} // namespace QtPck


#endif // !QtPck_included


