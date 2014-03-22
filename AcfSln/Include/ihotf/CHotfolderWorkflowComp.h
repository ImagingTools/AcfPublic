/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#ifndef ihotf_CHotfolderWorkflowComp_included
#define ihotf_CHotfolderWorkflowComp_included


// Qt includes
#include <QtCore/QMap>

// ACF includes
#include "istd/TDelPtr.h"
#include "istd/TChangeDelegator.h"
#include "istd/TPointerVector.h"
#include "icomp/CComponentBase.h"

// AcfSln includes
#include "ihotf/IHotfolderWorkflow.h"
#include "ihotf/IHotfolderInfoManager.h"
#include "ihotf/CHotfolderWorkflowItem.h"


namespace ihotf
{


/**
	Implementation of the dynamic data model of the hotfolder.
*/
class CHotfolderWorkflowComp:
				public icomp::CComponentBase,
				virtual public ihotf::IHotfolderWorkflow,
				virtual public ihotf::IHotfolderInfoManager
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CHotfolderWorkflowComp);
		I_REGISTER_INTERFACE(ihotf::IHotfolderWorkflow);
		I_REGISTER_INTERFACE(ihotf::IHotfolderInfoManager);
		I_REGISTER_INTERFACE(iser::ISerializable);

		I_ASSIGN_MULTI_0(m_hotoflderFactoriesCompPtr, "HotfolderFactories", "List of factories for hotfolder creation", true);
		I_ASSIGN_MULTI_0(m_hotoflderFactoryIdsAttrPtr, "HotfolderFactoryIds", "List of factory IDs for hotfolder creation", true);
	I_END_COMPONENT;

	CHotfolderWorkflowComp();

	// reimplemented (ihotf::IHotfolderInfoManager)
	virtual ihotf::IHotfolderProcessingInfo* GetProcessingInfo(const QString& hotfolderName) const;

	// reimplemented (ihotf::IHotfolderWorkflow)
	virtual ihotf::IHotfolderWorkflowItem* AddHotfolder(const QString& hotfolderName, const QString& hotfolderId = QString());
	virtual bool RemoveHotfolder(const QString& hotfolderName);
	virtual QStringList GetHotfolderIds() const;
	virtual QStringList GetHotfolderList() const;
	virtual ihotf::IHotfolderWorkflowItem* GetHotfolder(const QString& hotfolderName) const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	struct HotfolderItem
	{
		istd::TDelPtr<iprm::IParamsSet> hotfolderParamsPtr;
		istd::TDelPtr<ihotf::IHotfolderWorkflowItem> elementPtr;
	};

	typedef istd::TPointerVector<HotfolderItem> Hotfolders;

	virtual HotfolderItem* CreateHotfolder(const QString& hotfolderName, const QString& hotfolderId = QString()) const;
	virtual ihotf::IHotfolderWorkflowItem* CreateWorkflowItem(const QString& hotfolderId) const;

private:
	I_MULTIFACT(iprm::IParamsSet, m_hotoflderFactoriesCompPtr);
	I_MULTIATTR(QString, m_hotoflderFactoryIdsAttrPtr);

	Hotfolders m_hotfolders;
};


} // namespace ihotf


#endif // !ihotf_CHotfolderWorkflowComp_included

