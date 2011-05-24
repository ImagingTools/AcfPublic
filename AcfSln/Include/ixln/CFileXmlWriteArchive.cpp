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


#include "ixln/CFileXmlWriteArchive.h"


#include <xercesc/framework/LocalFileFormatTarget.hpp>


namespace ixln
{


CFileXmlWriteArchive::CFileXmlWriteArchive(
			const istd::CString& filePath,
			const iser::IVersionInfo* versionInfoPtr,
			bool serializeHeader,
			const iser::CArchiveTag& rootTag)
:	BaseClass(versionInfoPtr, rootTag),
	BaseClass2(filePath)
{
	XMLCh* tmpData = xercesc::XMLString::transcode(filePath.ToString().c_str());
	Init(new xercesc::LocalFileFormatTarget(tmpData));
	xercesc::XMLString::release(&tmpData);


	if (serializeHeader){
		SerializeAcfHeader();
	}
}


} // namespace ixln


