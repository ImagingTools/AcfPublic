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


#ifndef idoc_IHelpFileProvider_included
#define idoc_IHelpFileProvider_included


#include "istd/IPolymorphic.h"
#include "istd/CString.h"


namespace idoc
{


/**
	Allow to show help document to specified object or text.
*/
class IHelpFileProvider: virtual public istd::IPolymorphic
{
public:
	/**
		Get quality of help information for specified context and/or object.
		\return	quality of help. It represented as value in range [0, 1].
	*/
	virtual double GetHelpQuality(const istd::CString& contextText, const istd::IPolymorphic* contextObjectPtr) const = 0;
	virtual istd::CString GetHelpFilePath(const istd::CString& contextText, const istd::IPolymorphic* contextObjectPtr) const = 0;
};


} // namespace idoc


#endif // !idoc_IHelpFileProvider_included


