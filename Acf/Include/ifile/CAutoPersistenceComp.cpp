/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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


#include "ifile/CAutoPersistenceComp.h"


namespace ifile
{


// protected methods

// reimplemented (imod::CSingleModelObserverBase)

void CAutoPersistenceComp::OnUpdate(int /*updateFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
	if (*m_storeOnChangeAttrPtr){
		if (m_fileLoaderCompPtr.IsValid() && m_objectCompPtr.IsValid()){
			QString filePath;
			if (m_filePathCompPtr.IsValid()){
				filePath = m_filePathCompPtr->GetPath();
			}

			m_fileLoaderCompPtr->SaveToFile(*m_objectCompPtr, filePath);
		}
	}
}


// reimplemented (icomp::CComponentBase)

void CAutoPersistenceComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (*m_restoreOnBeginAttrPtr){
		if (m_fileLoaderCompPtr.IsValid() && m_objectCompPtr.IsValid()){
			QString filePath;
			if (m_filePathCompPtr.IsValid()){
				filePath = m_filePathCompPtr->GetPath();
			}

			m_fileLoaderCompPtr->LoadFromFile(*m_objectCompPtr, filePath);
		}
	}

	if (m_objectModelCompPtr.IsValid())
	{
		m_objectModelCompPtr->AttachObserver(this);
	}
}


void CAutoPersistenceComp::OnComponentDestroyed()
{
	EnsureModelDetached();

	if (*m_storeOnEndAttrPtr){
		if (m_fileLoaderCompPtr.IsValid() && m_objectCompPtr.IsValid()){
			QString filePath;
			if (m_filePathCompPtr.IsValid()){
				filePath = m_filePathCompPtr->GetPath();
			}

			m_fileLoaderCompPtr->SaveToFile(*m_objectCompPtr, filePath);
		}
	}

	BaseClass::OnComponentDestroyed();
}


} // namespace ifile


