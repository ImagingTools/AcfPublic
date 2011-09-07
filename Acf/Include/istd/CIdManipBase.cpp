/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "istd/CIdManipBase.h"


namespace istd
{


// static methods

bool CIdManipBase::SplitId(const std::string& complexId, std::string& baseId, std::string& subId)
{
	std::string::size_type separatorPos = complexId.find('/');
	if (separatorPos != std::string::npos){
		baseId = complexId.substr(0, separatorPos);
		subId = complexId.substr(separatorPos + 1);

		return true;
	}
	else{
		baseId = complexId;
		subId = "";

		return false;
	}
}


std::string CIdManipBase::JoinId(const std::string& baseId, const std::string& subId)
{
	if (!subId.empty()){
		return baseId + "/" + subId;
	}
	else{
		return baseId;
	}
}


}//namespace istd


