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


#ifndef iprm_IParamsSet_included
#define iprm_IParamsSet_included


#include "iser/ISerializable.h"

#include "iprm/iprm.h"


namespace iprm
{


/**
	Set of processing parameter.
	Processing parameters can be editable or not (e.g. automatic calculated parameters).
*/
class IParamsSet: virtual public iser::ISerializable
{
public:
	/**
		Get any parameter.
		\param	id	ID of parameter. It is application specified.
		\return		pointer to parameter instance or NULL if there is no parameter with this ID.
	*/
	virtual const iser::ISerializable* GetParameter(const std::string& id) const = 0;
	/**
		Get access to editable parameter.
		\param	id	ID of parameter. It is application specified.
		\return		pointer to parameter instance or NULL if there is no editable parameter with this ID.
	*/
	virtual iser::ISerializable* GetEditableParameter(const std::string& id) = 0;
};


} // namespace iprm


#endif // !iprm_IParamsSet_included


