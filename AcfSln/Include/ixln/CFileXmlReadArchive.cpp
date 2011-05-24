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


#include "ixln/CFileXmlReadArchive.h"


#include <xercesc/framework/LocalFileInputSource.hpp>
#include <xercesc/framework/Wrapper4InputSource.hpp>


namespace ixln
{


CFileXmlReadArchive::CFileXmlReadArchive(const istd::CString& filePath, bool serializeHeader, const iser::CArchiveTag& rootTag)
:	BaseClass(rootTag),
	BaseClass2(filePath)
{
	XMLCh* tmpData = xercesc::XMLString::transcode(filePath.ToString().c_str());
	xercesc::LocalFileInputSource inputSource(tmpData);
	xercesc::XMLString::release(&tmpData);

	Init(inputSource);

	if (serializeHeader){
		SerializeAcfHeader();
	}
}


} // namespace ixln


