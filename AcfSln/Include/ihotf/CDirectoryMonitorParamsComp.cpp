/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include <ihotf/CDirectoryMonitorParamsComp.h>


namespace ihotf
{


// protected methods

// reimplemented (icomp::CComponentBase)

void CDirectoryMonitorParamsComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_poolingIntervallAttrPtr.IsValid()){
		SetPoolingIntervall(*m_poolingIntervallAttrPtr);
	}

	if (m_observedItemTypesAttrPtr.IsValid()){
		SetObservedItemTypes(*m_observedItemTypesAttrPtr);
	}

	if (m_observedChangesAttrPtr.IsValid()){
		SetObservedChanges(*m_observedChangesAttrPtr);
	}

	if (m_acceptPatternsAttrPtr.IsValid()){
		QStringList acceptPatterns;
		for (int index = 0; index < m_acceptPatternsAttrPtr.GetCount(); index++){
			acceptPatterns.push_back(m_acceptPatternsAttrPtr[index]);
		}

		SetAcceptPatterns(acceptPatterns);
	}

	if (m_ignorePatternsAttrPtr.IsValid()){
		QStringList ignorePatterns;
		for (int index = 0; index < m_ignorePatternsAttrPtr.GetCount(); index++){
			ignorePatterns.push_back(m_ignorePatternsAttrPtr[index]);
		}

		SetIgnorePatterns(ignorePatterns);
	}

	if (m_minLastModificationTimeDifferenceAttrPtr.IsValid()){
		SetMinLastModificationTimeDifference(*m_minLastModificationTimeDifferenceAttrPtr);
	}

	if (m_folderDepthAttrPtr.IsValid()){
		SetFolderDepth(*m_folderDepthAttrPtr);
	}
}


} // namespace ihotf


