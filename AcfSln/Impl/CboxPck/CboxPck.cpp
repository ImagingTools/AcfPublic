/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "icomp/export.h"

#include "CboxPck.h"


namespace CboxPck
{


I_EXPORT_DEFAULT_SERVICES;

I_EXPORT_PACKAGE(
			"Cbox",
			"Package based on Crypto Box library CBIOS",
			"Crypto Box Dongle" IM_PROJECT("ACF-Solutions") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			MemoryBankSerializer,
			"Load and save objects from/to Crypto Box memory",
			"Serializer Archive Load Save Encryption Decryption Crypto Box CBIOS Dongle RAM Partition Memory" IM_TAG("Loader"));


} // namespace CboxPck


