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


#include "QtPck.h"


#include "icomp/export.h"


namespace QtPck
{


I_EXPORT_PACKAGE(
			"Acf/Qt/Base",
			"Standard Qt package",
			IM_PROJECT("ACF") IM_TAG("Qt") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			SettingsSerializer,
			"Load and save objects using QSettings as storage",
			"QSettings Registry Serializer Saver" IM_TAG("Persistence Loader"));

I_EXPORT_COMPONENT(
			ApplicationSettingsProvider,
			"Provider for the global application settings",
			"Settings QSettings Registry Saver" IM_TAG("Application Persistence"));

I_EXPORT_COMPONENT(
			IniSettingsProvider,
			"Provider for the settings taken from the INI file",
			"INI Settings QSettings Registry Saver" IM_TAG("Application Persistence"));

I_EXPORT_COMPONENT(
			ClipboardSerializer,
			"Load and store objects from and to clipboard",
			"System Clipboard Serializer Copy Paste" IM_TAG("Loader"));

I_EXPORT_COMPONENT(
			TranslationManager,
			"Text localization manager",
			"Translation" IM_TAG("Localization"));

I_EXPORT_COMPONENT(
		   QtXmlFileSerializer,
		   "File loader serializing objects using simplified XML format using Qt",
		   "Save Serializer Archive Format" IM_CATEGORY(I_DATA_PERSISTENCE) IM_TAG("XML Loader File"));

I_EXPORT_COMPONENT(
		   CompactXmlFileSerializer,
		   "File loader serializing objects compact XML format",
		   "Save Serializer Archive Format Compact Attributes" IM_CATEGORY(I_DATA_PERSISTENCE) IM_TAG("XML Loader File"));

I_EXPORT_COMPONENT(
			ExtendedDocumentTemplate,
			"Extended serialized document template",
			"Serialized Template" IM_TAG("Document"));

I_EXPORT_COMPONENT(
			StaticHelpFileProvider,
			"Provide static html help file path",
			"File Provider Document Html Description Qt" IM_TAG("Help"));

I_EXPORT_COMPONENT(
			DoxygenHelpFileProvider,
			"Provide html help file path converting class type using doxygen format",
			"Doxygen File Provider Document Html Description Class Interface Qt" IM_TAG("Help"));


} // namespace QtPck


