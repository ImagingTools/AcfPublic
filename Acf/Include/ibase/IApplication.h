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


#ifndef ibase_IApplication_included
#define ibase_IApplication_included


#include "istd/IPolymorphic.h"
#include "istd/CString.h"


namespace ibase
{		


/**
	Main entry point of component-based application.

	\ingroup Main
	\ingroup ComponentConcept
*/
class IApplication: virtual public istd::IPolymorphic
{
public:
	/**
		Initialize the application object.
	*/
	virtual bool InitializeApplication(int argc, char** argv) = 0;

	/**
		Starts execution loop of the application.
	*/
	virtual int Execute(int argc, char** argv) = 0;

	/**
		Gets the command line arguments of this application.
	*/
	virtual istd::CString GetHelpText() const = 0;
};


} // namespace ibase


#endif // !ibase_IApplication_included


