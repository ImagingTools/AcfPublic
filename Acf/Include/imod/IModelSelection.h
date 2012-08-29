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


#ifndef imod_IModelSelection_included
#define imod_IModelSelection_included


#include "istd/IChangeable.h"

#include "imod/IModel.h"


namespace imod
{


/**
	Interface for model selection.	

	\ingroup ModelObserver
*/
class IModelSelection: virtual public istd::IChangeable
{
public:
	/**
		Get selected model.
	*/
	virtual imod::IModel* GetSelectedModel() const = 0;

	/**
		Set selected model.
	*/
	virtual void SetSelectedModel(imod::IModel* modelPtr) = 0;
};


} // namespace imod


#endif // !imod_IModelSelection_included


