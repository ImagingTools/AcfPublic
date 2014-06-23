/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef ibase_CObjectSynchronizerComp_included
#define ibase_CObjectSynchronizerComp_included


// ACF includes
#include "icomp/CComponentBase.h"
#include "imod/CSingleModelObserverBase.h"
#include "istd/IChangeable.h"


namespace ibase
{


/**
	Component for synchronization between some master data object and its "slaves".
	On component initialization the slave objects are initialized with data of "master" object.
	On each change of the "master" data, the slave objects will be automatically synchronized.

	\ingroup DataModel
*/
class CObjectSynchronizerComp:
			public icomp::CComponentBase,
			protected imod::CSingleModelObserverBase
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CObjectSynchronizerComp);
		I_ASSIGN(m_referenceObjectCompPtr, "ReferenceObject", "Reference data object", true, "ReferenceObject");
		I_ASSIGN_TO(m_referenceObjectModelCompPtr, m_referenceObjectCompPtr, true);
		I_ASSIGN_MULTI_0(m_slaveObjectsCompPtr, "SlaveObjects", "The list of object which will be hold synchronized with reference object", true);
	I_END_COMPONENT;
	
protected:
	// reimplemented (imod::CSingleModelObserverBase)
	virtual void OnUpdate(const istd::IChangeable::ChangeSet& changeSet);

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_REF(istd::IChangeable, m_referenceObjectCompPtr);
	I_REF(imod::IModel, m_referenceObjectModelCompPtr);
	I_MULTIREF(istd::IChangeable, m_slaveObjectsCompPtr);
};


} // namespace ibase


#endif // !ibase_CObjectSynchronizerComp_included


