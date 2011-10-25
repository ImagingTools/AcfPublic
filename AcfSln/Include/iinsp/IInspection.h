/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iinsp_IInspection_included
#define iinsp_IInspection_included


// ACF includes
#include "iser/ISerializable.h"
#include "iprm/IParamsSet.h"


namespace iinsp
{


class IInspectionTask;


/**
	Representation of inspection (set of inspection tasks).
*/
class IInspection: virtual public iser::ISerializable
{
public:
	/**
		Get number of inspection tasks.
	*/
	virtual int GetTasksCount() const = 0;

	/**
		Get single inspection task.
	*/
	virtual IInspectionTask* GetTask(int subtaskIndex) const = 0;

	/**
		Get access to global inspection parameters.
		\return	parameter set describing global parameters or \c NULL if no global parameters are supported.
	*/
	virtual iprm::IParamsSet* GetInspectionParams() const = 0;
};


} // namespace iinsp


#endif // !iinsp_IInspection_included


