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


#ifndef ihotf_CHotfolderWorkflowItem_included
#define ihotf_CHotfolderWorkflowItem_included


// ACF includes
#include "iprm/CNameParam.h"


// AcfSln includes
#include "ihotf/IHotfolderWorkflowItem.h"
#include "ihotf/IHotfolderInfoManager.h"


namespace ihotf
{


/**
	Implementation of the dynamic data model of the hotfolder.
*/
class CHotfolderWorkflowItem:
			public iprm::CNameParam,
			virtual public ihotf::IHotfolderWorkflowItem
{
public:
	typedef iprm::CNameParam BaseClass;

	void Initialize(const QString& hotfolderId,
					const ihotf::IHotfolderInfoManager* infoManagerPtr);

	/**
		Get hotfolder's ID
	*/
	virtual QString GetHotfolderId() const;

	// reimplemented (ihotf::IHotfolderWorkflowItem)
	virtual QStringList GetInputDirectories() const;
	virtual QString GetOutputDirectory() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	QString m_hotfolderId;

	const ihotf::IHotfolderInfoManager* m_infoManagerPtr;
};


} // namespace ihotf


#endif // !ihotf_CHotfolderWorkflowItem_included

