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


#ifndef icmpstr_IComponentNote_included
#define icmpstr_IComponentNote_included


#include "iser/IObject.h"

#include "i2d/CVector2d.h"

#include "istd/CString.h"

#include "icmpstr/icmpstr.h"


namespace icmpstr
{


class IComponentNote: virtual public iser::IObject
{
public:
	virtual istd::CString GetText() const = 0;
	virtual void SetText(const istd::CString& noteText) = 0;
	virtual i2d::CVector2d GetPosition() const = 0;
	virtual void SetPosition(const i2d::CVector2d& position) = 0;
};


} // namespace icmpstr


#endif // !IComponentNote_included

