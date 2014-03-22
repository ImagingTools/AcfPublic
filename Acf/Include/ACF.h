/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef ACF_included
#define ACF_included


/**
\defgroup ACF ACF

\mainpage
\section Introduction
ACF (Advanced Component Framework) is a C++ based component framework that was especially designed 
for creation of very complex applications. ACF contains many standard implementations of most usefull design patterns, 
such Serialization, Model/Observer, Factory and so on. ACF implements a component concept 
and includes many standard components, which you can directly use in your application.

See http://www.ilena.org, write info@imagingtools.de or contact
by Skype to ACF_infoline for further information about the ACF.

\section Example

\section Tutorials
See \c Docs/Tutorial for tutorials.
*/


/**
	\defgroup ModelObserver Model/Observer concept
	The main use-case of this concept is to get information on the observer side about changes of model.
	It can be used e.g. to realize GUI update if releted model changes.

	\ingroup ACF
*/


/**
	\defgroup Persistence Persistence concept.

	\ingroup ACF
*/


/**
	\defgroup Helpers Set of helper classes.

	\ingroup ACF
*/


/**
	\defgroup Main Main concepts and implementations
	If you can learn how to use ACF you should begin with elements defined in this module.

	\ingroup ACF
*/


/**
	\defgroup System Defines access to operating system dependent implementation

	\ingroup ACF
*/

/**
	\defgroup ComponentConcept Component concept
	This concept allows to divide application into smaller modules.
	At the implementation level you don't need to care on the application topology.
	The topology will be described separatelly using \em .arx files and can be started using
	runtime environment over ACF tool or compiled to C++ code using ARXC compiler.
	Additionally you can use component simulation to use components as "normal" classes.

	\ingroup ACF
*/


#endif // !ACF_included
