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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef ihotf_IHotfolderWorkflow_included
#define ihotf_IHotfolderWorkflow_included


// ACF includes
#include "iser/ISerializable.h"

#include "iprm/IParamsSet.h"


// AcfSln includes
#include "ihotf/IHotfolderWorkflowItem.h"


namespace ihotf
{


/**
	Common interface for a hotfolder workflow static model.
*/
class IHotfolderWorkflow: virtual public iser::ISerializable
{
public:
	enum ChangeFlags
	{
		CF_HOTFOLDER_ADDED = 0x100000,
		CF_HOTFOLDER_REMOVED = 0x200000
	};

	/**
		Add a hotfolder to the workflow.
		The name of the hotfolder must be unique, otherwise no folder will be added an the function returns \c null.
	*/
	virtual ihotf::IHotfolderWorkflowItem* AddHotfolder(const QString& hotfolderName, const QString& hotfolderId = QString()) = 0;

	/**	
		Remove a hotfolder with the name \hotfolderName from the workflow.
	*/
	virtual bool RemoveHotfolder(const QString& hotfolderName) = 0;

	/**
		Get the list of possible hotfolder IDs.
	*/
	virtual QStringList GetHotfolderIds() const = 0;

	/**
		Get hotfolder list in this workflow.
	*/
	virtual QStringList GetHotfolderList() const = 0;

	/**
		Get the hotfolder.
	*/
	virtual ihotf::IHotfolderWorkflowItem* GetHotfolder(const QString& hotfolderName) const = 0;
};


} // namespace ihotf


#endif // !ihotf_IHotfolderWorkflow_included


