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

bool CIdManipBase::SplitId(const QByteArray& complexId, QByteArray& baseId, QByteArray& subId)
{
	int separatorPos = complexId.indexOf('/');
	if (separatorPos >= 0){
		baseId = complexId.left(separatorPos);
		subId = complexId.mid(separatorPos + 1);

		return true;
	}
	else{
		baseId = complexId;
		subId = "";

		return false;
	}
}


QByteArray CIdManipBase::JoinId(const QByteArray& baseId, const QByteArray& subId)
{
	if (!subId.isEmpty()){
		return baseId + "/" + subId;
	}
	else{
		return baseId;
	}
}


}//namespace istd


