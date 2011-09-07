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


#include "ibase/CComposedLoaderComp.h"


// STL includes
#include <algorithm>


namespace ibase
{


// reimplemented (iser::IFileLoader)

bool CComposedLoaderComp::IsOperationSupported(
		const istd::IChangeable* dataObjectPtr,
		const istd::CString* filePathPtr,
		int flags,
		bool beQuiet) const
{
	int slavesCount = m_slaveLoadersCompPtr.GetCount();
	for (int i = 0; i < slavesCount; ++i){
		const iser::IFileLoader* loaderPtr = m_slaveLoadersCompPtr[i];
		if ((loaderPtr != NULL) && loaderPtr->IsOperationSupported(dataObjectPtr, filePathPtr, flags, beQuiet)){
			return true;
		}
	}

	return false;
}


int CComposedLoaderComp::LoadFromFile(istd::IChangeable& data, const istd::CString& filePath) const
{
	int slavesCount = m_slaveLoadersCompPtr.GetCount();
	for (int i = 0; i < slavesCount; ++i){
		iser::IFileLoader* loaderPtr = m_slaveLoadersCompPtr[i];
		if ((loaderPtr != NULL) && loaderPtr->IsOperationSupported(&data, &filePath, QF_NO_SAVING | QF_FILE_ONLY)){
			return loaderPtr->LoadFromFile(data, filePath);
		}
	}

	return StateFailed;
}


int CComposedLoaderComp::SaveToFile(const istd::IChangeable& data, const istd::CString& filePath) const
{
	int slavesCount = m_slaveLoadersCompPtr.GetCount();
	for (int i = 0; i < slavesCount; ++i){
		iser::IFileLoader* loaderPtr = m_slaveLoadersCompPtr[i];
		if ((loaderPtr != NULL) && loaderPtr->IsOperationSupported(&data, &filePath, QF_NO_LOADING | QF_FILE_ONLY)){
			return loaderPtr->SaveToFile(data, filePath);
		}
	}

	return StateFailed;
}


// reimplemented (iser::IFileTypeInfo)

bool CComposedLoaderComp::GetFileExtensions(istd::CStringList& result, int flags, bool doAppend) const
{
	if (!doAppend){
		result.clear();
	}

	bool retVal = false;

	int slavesCount = m_slaveLoadersCompPtr.GetCount();
	for (int i = 0; i < slavesCount; ++i){
		iser::IFileLoader* loaderPtr = m_slaveLoadersCompPtr[i];
		if (loaderPtr != NULL){
			retVal = loaderPtr->GetFileExtensions(result, flags, true) | retVal;
		}
	}

	return retVal;
}


istd::CString CComposedLoaderComp::GetTypeDescription(const istd::CString* extensionPtr) const
{
	if (extensionPtr != NULL){
		int slavesCount = m_slaveLoadersCompPtr.GetCount();
		for (int i = 0; i < slavesCount; ++i){
			iser::IFileLoader* loaderPtr = m_slaveLoadersCompPtr[i];
			if (loaderPtr != NULL){
				istd::CStringList extensions;
				loaderPtr->GetFileExtensions(extensions);

				if (std::find(extensions.begin(), extensions.end(), *extensionPtr) != extensions.end()){
					return loaderPtr->GetTypeDescription(extensionPtr);
				}
			}
		}
	}

	if (m_commonDescriptionAttrPtr.IsValid()){
		return *m_commonDescriptionAttrPtr;
	}

	return "";
}


} // namespace ibase


