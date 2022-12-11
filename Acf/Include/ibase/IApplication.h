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


#ifndef ibase_IApplication_included
#define ibase_IApplication_included


// Qt includes
#include <QtCore/QString>

// ACF includes
#include <istd/IPolymorphic.h>


namespace ibase
{		


/**
	Interface for the main entry point of a component-based application.

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
		Start execution loop of the application.
	*/
	virtual int Execute(int argc, char** argv) = 0;

	/**
		Get information about the possible command line arguments of this application.
	*/
	virtual QString GetHelpText() const = 0;

	/**
		Get the command line arguments of this application.
	*/
	virtual QStringList GetApplicationArguments() const = 0;
};


} // namespace ibase


#endif // !ibase_IApplication_included


