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


#ifndef ifpf_CHotfolderWorkflowComp_included
#define ifpf_CHotfolderWorkflowComp_included


// STL includes
#include <map>


// ACF includes
#include "istd/TDelPtr.h"
#include "icomp/CComponentBase.h"

// AcfSln includes
#include "ifpf/IHotfolderWorkflow.h"
#include "ifpf/CHotfolderProcessingItem.h"
#include "ifpf/CMonitoringSession.h"


namespace ifpf
{


/**
	Implementation of the dynamic data model of the hotfolder.
*/
class CHotfolderWorkflowComp: public icomp::CComponentBase, virtual public ifpf::IHotfolderWorkflow
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CHotfolderWorkflowComp);
		I_REGISTER_INTERFACE(ifpf::IHotfolderWorkflow);
		I_REGISTER_INTERFACE(iser::ISerializable);
	I_END_COMPONENT;

	CHotfolderWorkflowComp();

	// reimplemented (ifpf::IHotfolderWorkflow)
	virtual ifpf::IHotfolderProcessingInfo* AddHotfolder(const QString& hotfolderName, const QString& hotfolderId = QString());
	virtual bool RemoveHotfolder(const QString& hotfolderName);
	virtual ifpf::IHotfolderProcessingInfo* GetHotfolder(const QString& hotfolderName) const;
	virtual QStringList GetHotfoldersList() const;
	virtual int GetWorkingState(const QString& hotfolderName) const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	virtual ifpf::IHotfolderProcessingInfo* CreateHotfolder(const QString& hotfolderName, const QString& hotfolderId = QString()) const;

private:
	struct HotfolderInfo
	{
		istd::TDelPtr<ifpf::IHotfolderProcessingInfo> m_hotfolderPtr;
		QString hotfolderId;
	};

	I_MULTIFACT(ifpf::IHotfolderProcessingInfo, m_hotoflderFactoriesCompPtr);
	I_MULTIATTR(QString, m_hotoflderFactoryIdsAttrPtr);
};


} // namespace ifpf


#endif // !ifpf_CHotfolderWorkflowComp_included

