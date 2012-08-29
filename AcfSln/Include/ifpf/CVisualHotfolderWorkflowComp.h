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


#ifndef ifpf_CVisualHotfolderWorkflowComp_included
#define ifpf_CVisualHotfolderWorkflowComp_included


// ACF includes
#include "istd/TChangeDelegator.h"

#include "iser/IObject.h"

#include "imod/TModelWrap.h"

#include "ibase/TLoggerCompWrap.h"


// AcfSln includes
#include "ifpf/CHotfolderWorkflowComp.h"
#include "ifpf/CVisualHotfolderWorkflowItem.h"


namespace ifpf
{


/**
	
*/
class CVisualHotfolderWorkflowComp:
			public ibase::TLoggerCompWrap<ifpf::CHotfolderWorkflowComp>
{
public:
	typedef ibase::TLoggerCompWrap<ifpf::CHotfolderWorkflowComp> BaseClass;

	I_BEGIN_COMPONENT(CVisualHotfolderWorkflowComp);
	I_END_COMPONENT;

	enum ChangeFlags
	{
		CF_SELECTION = 0x10000000
	};

	enum MessageId
	{
		MI_CANNOT_CREATE_ELEMENT = 650
	};

	virtual bool SerializeLayout(iser::IArchive& archive);
	virtual bool SerializeWorkflow(iser::IArchive& archive);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	typedef imod::TModelWrap<istd::TChangeDelegator<CVisualHotfolderWorkflowItem> > Element;

	bool SerializeItemPosition(iser::IArchive& archive, QString& hotfolderName, i2d::CVector2d& position);

	// reimplemented (ifpf::CHotfolderWorkflowComp)
	virtual ifpf::IHotfolderWorkflowItem* CreateWorkflowItem(const QString& hotfolderId) const;
};


} // namespace ifpf


#endif // !ifpf_CVisualHotfolderWorkflowComp_included

