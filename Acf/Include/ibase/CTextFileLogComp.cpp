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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "ibase/CTextFileLogComp.h"


#include "imod/IModel.h"

#include "ibase/IMessage.h"


// STL includes
#include <iostream>


namespace ibase
{


// public methods

CTextFileLogComp:: CTextFileLogComp()
	:m_filePathObserver(*this)
{
}


// protected methods

// reimplemented (CStreamLogCompBase)

void CTextFileLogComp::WriteText(const istd::CString& text)
{
	if (m_outputFileStream.is_open()){
		m_outputFileStream << text.c_str();
		m_outputFileStream.flush();
	}
}


void CTextFileLogComp::NewLine()
{
	if (m_outputFileStream.is_open()){
		m_outputFileStream << std::endl;
		m_outputFileStream.flush();
	}
}


// reimplemented (icomp::CComponentBase)

void CTextFileLogComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_fileNameModelCompPtr.IsValid()){
		m_fileNameModelCompPtr->AttachObserver(&m_filePathObserver);
	}
	
	OpenFileStream();
}


void CTextFileLogComp::OnComponentDestroyed()
{
	if (m_fileNameModelCompPtr.IsValid() && m_fileNameModelCompPtr->IsAttached(&m_filePathObserver)){
		m_fileNameModelCompPtr->DetachObserver(&m_filePathObserver);
	}

	m_outputFileStream.close();

	BaseClass::OnComponentDestroyed();
}


void CTextFileLogComp::OpenFileStream()
{
	if (m_outputFileStream.is_open()){
		m_outputFileStream.flush();

		m_outputFileStream.close();
	}

	if (m_fileNameCompPtr.IsValid()){
		std::ios::openmode fileMode = std::wofstream::out | std::wofstream::app;

		if (m_isAppendAttrPtr.IsValid() && !*m_isAppendAttrPtr){
			fileMode = std::wofstream::out;
		}

#ifdef _MSC_VER
		m_outputFileStream.open(m_fileNameCompPtr->GetPath().c_str(), fileMode);
#else
		m_outputFileStream.open(m_fileNameCompPtr->GetPath().ToString().c_str(), fileMode);
#endif
	}
}


// embedded class FilePathObserver

// public methods

CTextFileLogComp::FilePathObserver::FilePathObserver(CTextFileLogComp& parent)
	:m_parent(parent)
{
}


// protected methods

// reimplemented (imod::CSingleModelObserverBase)
	
void CTextFileLogComp::FilePathObserver::OnUpdate(int /*updateFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
	m_parent.OpenFileStream();
}


} // namespace ibase


