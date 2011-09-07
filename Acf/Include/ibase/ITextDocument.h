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


#ifndef ibase_ITextDocument_included
#define ibase_ITextDocument_included


#include "istd/CString.h"

#include "iser/ISerializable.h"


namespace ibase
{


/**
	Simple interface for a text document.
*/
class ITextDocument: virtual public iser::ISerializable
{
public:
	/**
		Get document text.
	*/
	virtual istd::CString GetText() const = 0;

	/**
		Set document text.
	*/
	virtual void SetText(const istd::CString& text) = 0;
};


} // namespace ibase


#endif // !ibase_ITextDocument_included


