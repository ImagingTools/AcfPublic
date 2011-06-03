/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqt_CLocalizer_included
#define iqt_CLocalizer_included


// Qt includes
#include <QTime>


// ACF includes
#include "istd/ILocalizer.h"

#include "iqt/iqt.h"


namespace iqt
{


/**
	An timer implementation for Qt library.
*/
class CLocalizer: virtual public istd::ILocalizer
{
public:
	// reimplemented (istd::ILocalizer)
	virtual istd::CString GetTranslatedText(
				const std::string& context,
				const istd::CString& text,
				const std::string& disambiguation = std::string()) const;
};


} // namespace iqt


#endif // !iqt_CLocalizer_included
