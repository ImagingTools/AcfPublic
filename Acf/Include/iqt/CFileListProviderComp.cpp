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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqt/CFileListProviderComp.h"


// Qt includes
#include <QStringList>


// ACF includes
#include "istd/TChangeNotifier.h"

#include "iqt/CFileList.h"


namespace iqt
{


// reimplemented (ibase::IFileListProvider)

istd::CStringList CFileListProviderComp::GetFileList() const
{
	return m_fileList;
}


// protected methods

// reimplemented (imod::CSingleModelObserverBase)

void CFileListProviderComp::OnUpdate(int /*updateFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
	istd::CChangeNotifier notifier(this);

	m_fileList.clear();

	if (m_dirParamCompPtr.IsValid()){
		QStringList filters;

		if (m_fileLoaderCompPtr.IsValid()){
			istd::CStringList extensions;
			if (m_fileLoaderCompPtr->GetFileExtensions(extensions)){
				for (		istd::CStringList::const_iterator extIter = extensions.begin();
							extIter != extensions.end();
							++extIter){
					const istd::CString& extension = *extIter;

					filters << "*." + iqt::GetQString(extension);
				}
			}
		}
		else{
			int filtersCount = m_filtersAttrPtr.GetCount();
			for (int filterIndex = 0; filterIndex < filtersCount; ++filterIndex){
				filters << iqt::GetQString(m_filtersAttrPtr[filterIndex]);
			}
		}

		CFileList fileList;
		fileList.Create(
					iqt::GetQString(m_dirParamCompPtr->GetPath()),
					*m_minRecurDepthAttrPtr,
					*m_maxRecurDepthAttrPtr,
					filters);

		m_fileList = iqt::GetCStringList(fileList);
	}
}


// reimplemented (icomp::CComponentBase)

void CFileListProviderComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_dirParamModelCompPtr.IsValid()){
		m_dirParamModelCompPtr->AttachObserver(this);
	}
	else{
		OnUpdate(0, NULL);
	}
}


void CFileListProviderComp::OnComponentDestroyed()
{
	imod::CSingleModelObserverBase::EnsureModelDetached();

	BaseClass::OnComponentDestroyed();
}


} // namespace iqt


