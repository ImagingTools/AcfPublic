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


#ifndef istd_itr_included
#define istd_itr_included


// Qt includes
#include <QString>


#include "istd/ILocalizer.h"
#include "istd/CStaticServicesProvider.h"


/**
	Macro for defining string localization function in Non-Qt context.
*/
#define I_DECLARE_TR_FUNCTION(ContextName)\
	static QString tr(const QString& text, const std::string& disambiguation = std::string())\
	{\
		istd::ILocalizer* translatorPtr = istd::GetService<istd::ILocalizer>();\
		if (translatorPtr != NULL){\
			translatorPtr->GetTranslatedText(#ContextName, text, disambiguation);\
		}\
		return text;\
	}

#endif // !istd_itr_included


