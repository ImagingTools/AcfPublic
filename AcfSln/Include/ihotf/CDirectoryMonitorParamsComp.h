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


#ifndef ihotf_CDirectoryMonitorParamsComp_included
#define ihotf_CDirectoryMonitorParamsComp_included


// ACF includes
#include "icomp/CComponentBase.h"


// AcfSln includes
#include "ihotf/CDirectoryMonitorParams.h"


namespace ihotf
{


/**
	Implementation of directory parameters component.
	This implementation makes possible the definition of the default parameters at the component level.
*/
class CDirectoryMonitorParamsComp: public icomp::CComponentBase, public ihotf::CDirectoryMonitorParams
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef ihotf::CDirectoryMonitorParams BaseClass2;

	I_BEGIN_COMPONENT(ihotf::CDirectoryMonitorParamsComp);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(ihotf::IDirectoryMonitorParams);
		I_ASSIGN(m_poolingIntervallAttrPtr, "PoolingIntervall", "Intervall for checking of directory changes in seconds", false, 5);
		I_ASSIGN(m_observedItemTypesAttrPtr, "ObservedItems", "Items to be observed.\n1 - Directories\n2 - Files\n4 - Drives", false, OI_FILES);
		I_ASSIGN(m_observedChangesAttrPtr, "ObservedChanges", "Item changes to be observed.\n1 - Add\n2 - Remove\n4 - Modified\n8 - Attributes changed", false, OC_ADD);
		I_ASSIGN_MULTI_0(m_acceptPatternsAttrPtr, "AcceptPatterns", "File name patterns for accepting of the file items", false);
		I_ASSIGN_MULTI_0(m_ignorePatternsAttrPtr, "IgnorePatterns", "File name patterns for ignoring of the file items", false);
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(double, m_poolingIntervallAttrPtr);
	I_ATTR(int, m_observedItemTypesAttrPtr);
	I_ATTR(int, m_observedChangesAttrPtr);
	I_MULTIATTR(QString, m_acceptPatternsAttrPtr);
	I_MULTIATTR(QString, m_ignorePatternsAttrPtr);
};


} // namespace ihotf


#endif // !ihotf_CDirectoryMonitorParamsComp_included


