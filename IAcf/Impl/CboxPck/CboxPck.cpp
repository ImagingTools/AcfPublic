/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#include "CboxPck.h"


#include "icomp/export.h"


namespace CboxPck
{


I_EXPORT_PACKAGE(
			"Cbox",
			"Package based on Crypto Box library CBIOS",
			"Crypto Box Dongle" IM_PROJECT("ACF-Solutions") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			MemoryBankSerializer,
			"Load and save objects from/to Crypto Box memory",
			"Serializer Archive Load Save Encryption Decryption Crypto Box CBIOS Dongle RAM Partition Memory" IM_TAG("Loader"));


} // namespace CboxPck


