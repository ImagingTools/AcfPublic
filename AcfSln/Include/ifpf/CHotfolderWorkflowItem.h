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


#ifndef ifpf_CHotfolderWorkflowItem_included
#define ifpf_CHotfolderWorkflowItem_included


// ACF includes
#include "iprm/CNameParam.h"


// AcfSln includes
#include "ifpf/IHotfolderWorkflowItem.h"
#include "ifpf/IHotfolderInfoManager.h"


namespace ifpf
{


/**
	Implementation of the dynamic data model of the hotfolder.
*/
class CHotfolderWorkflowItem:
			public iprm::CNameParam,
			virtual public ifpf::IHotfolderWorkflowItem
{
public:
	typedef iprm::CNameParam BaseClass;

	void Initialize(const QString& hotfolderId,
					const ifpf::IHotfolderInfoManager* infoManagerPtr);

	/**
		Get hotfolder's ID
	*/
	virtual QString GetHotfolderId() const;

	// reimplemented (ifpf::IHotfolderWorkflowItem)
	virtual QStringList GetInputDirectories() const;
	virtual QString GetOutputDirectory() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	QString m_hotfolderId;

	const ifpf::IHotfolderInfoManager* m_infoManagerPtr;
};


} // namespace ifpf


#endif // !ifpf_CHotfolderWorkflowItem_included

