/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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


#pragma once


// ACF includes
#include <istd/IPolymorphic.h>


namespace iprm
{
	class IParamsSet;
}

namespace istd
{
	class IChangeable;
}


namespace idocproc
{


/**
	Interface for configuration of processing parameters/constraints based on the related input data.
*/
class IDocumentProcessingParamsController: virtual public istd::IPolymorphic
{
public:
	/**
		Prepares the processing parameters according to the document, that should be processed.
	*/
	virtual bool ConfigureParametersForDocument(
				const istd::IChangeable& document,
				iprm::IParamsSet& params,
				QString* errorMessagePtr = nullptr) const = 0;
};


} // namespace idocproc


