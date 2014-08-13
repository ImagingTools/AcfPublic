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


#ifndef icmpstr_CElementSelectionInfoManagerBase_included
#define icmpstr_CElementSelectionInfoManagerBase_included


// ACF includes
#include "istd/TDelPtr.h"
#include "istd/CClassInfo.h"

#include "imod/TSingleModelObserverBase.h"

#include "icomp/IMetaInfoManager.h"
#include "icomp/IRegistryElement.h"

#include "icmpstr/IAttributeSelectionObserver.h"
#include "icmpstr/IElementSelectionInfo.h"
#include "icmpstr/IRegistryConsistInfo.h"


namespace icmpstr
{


/**
	Base class for all components depending of meta information in current selected registry context.
*/
class CElementSelectionInfoManagerBase:
				public imod::TSingleModelObserverBase<IElementSelectionInfo>
{
public:
	typedef imod::TSingleModelObserverBase<IElementSelectionInfo> BaseClass;

	CElementSelectionInfoManagerBase();

	icomp::IRegistry* GetRegistry() const;
	QStringList GetExportAliases(const QByteArray& attributeName) const;
	const iser::IObject* GetAttributeObject(const QByteArray& attributeId, const icomp::IRegistry::ElementInfo& elementInfo) const;
	const icomp::IAttributeStaticInfo* GetAttributeStaticInfo(const QByteArray& attributeId, const icomp::IRegistry::ElementInfo& elementInfo) const;

	// abstract methods
	virtual const icomp::IMetaInfoManager* GetMetaInfoManagerPtr() const = 0;
	virtual const icmpstr::IRegistryConsistInfo* GetConsistencyInfoPtr() const = 0;
};


} // namespace icmpstr


#endif // !icmpstr_CElementSelectionInfoManagerBase_included

