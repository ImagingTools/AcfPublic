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


#include <iser/CArchiveBase.h>


namespace iser
{


// reimplemented (iser::IArchive)

bool CArchiveBase::IsTagSkippingSupported() const
{
	return false;
}


bool CArchiveBase::BeginMultiTag(const CArchiveTag& tag, const CArchiveTag& /*subTag*/, int& count)
{
	bool retVal = BeginTag(tag);

	retVal = retVal && Process(count);

	return retVal;
}

	
const CArchiveTag& CArchiveBase::GetAcfRootTag()
{
	static CArchiveTag retVal("Acf", "Root tag of ACF");
	
	return retVal;
}


// private methods

CArchiveBase::CArchiveBase(const CArchiveBase&)
:	istd::IPolymorphic(),
	iser::IArchive(),
	istd::ILogger()
{
}


// static attributes

CArchiveTag CArchiveBase::s_acfRootTag("Acf", "Root tag of ACF", iser::CArchiveTag::TT_GROUP);


} // namespace iser


