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


#ifndef istd_ILocalizer_included
#define istd_ILocalizer_included


// STL includes
#include <string>


// ACF includes
#include "istd/IPolymorphic.h"


namespace istd
{


class CString;


/**
	Common interface for a simple string localization.
*/
class ILocalizer: virtual public istd::IPolymorphic
{
public:
	/**
		Translate text \c text in the context \c context to defined language.
	*/
	virtual istd::CString GetTranslatedText(
				const std::string& context,
				const istd::CString& text,
				const std::string& disambiguation = std::string()) const = 0;
};


} // namespace istd


#endif // !istd_ILocalizer_included


