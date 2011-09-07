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


#ifndef iprm_IVariableParam_included
#define iprm_IVariableParam_included


// STL includes
#include <string>
#include <set>

#include "iser/ISerializable.h"

#include "iprm/iprm.h"


namespace iprm
{


/**
	Represents parameter, which can change its type.
*/
class IVariableParam: virtual public iser::ISerializable
{
public:
	typedef std::set<std::string> TypeIds;

	/**
		Get lilst of all known type ID's.
	*/
	virtual TypeIds GetKnownTypeIds() const = 0;

	/**
		Get type ID of current stored parameter.
		\return	type ID of current stored parameter or empty string if no type is assigned.
	*/
	virtual std::string GetParameterTypeId() const = 0;
	/**
		Get current parameter.
		\return	current stored parameter or NULL if no type is assigned.
	*/
	virtual iser::ISerializable* GetParameter() const = 0;

	/**
		Assign type ID to this object.
		Assigning of type ID creates internal instance of parameter object.
	*/
	virtual bool AssignTypeId(const std::string& typeId) = 0;
};


} // namespace iprm


#endif // !iprm_IVariableParam_included


