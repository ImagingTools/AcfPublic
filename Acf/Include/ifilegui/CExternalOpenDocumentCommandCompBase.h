/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef ifilegui_CExternalOpenDocumentCommandCompBase_included
#define ifilegui_CExternalOpenDocumentCommandCompBase_included


// ACF includes
#include <ifile/IFilePersistence.h>
#include <ifile/IFilePersistenceInfo.h>
#include <iqtgui/CProcessStartCommandComp.h>


namespace ifilegui
{


class CExternalOpenDocumentCommandCompBase: public iqtgui::CProcessStartCommandComp
{
public:
	typedef iqtgui::CProcessStartCommandComp BaseClass;

	I_BEGIN_BASE_COMPONENT(CExternalOpenDocumentCommandCompBase);
		I_ASSIGN(m_documentPersistenceCompPtr, "DocumentPersistence", "File persistence for the actual document type", true, "DocumentPersistence"); 
		I_ASSIGN_TO(m_documentPersistenceInfoCompPtr, m_documentPersistenceCompPtr, false);
		I_ASSIGN(m_documentFileCompPtr, "DocumentFilePath", "Path used for saving the current document", true, "DocumentFilePath");
	I_END_COMPONENT;

protected:
	// abstract methods
	virtual const istd::IChangeable* GetDocumentPtr() const = 0;

	// reimplemented (iqtgui::CProcessStartCommandComp)
	virtual bool StartProcess(const QStringList& arguments) override;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated() override;

protected:	
	I_REF(ifile::IFilePersistence, m_documentPersistenceCompPtr);
	I_REF(ifile::IFilePersistenceInfo, m_documentPersistenceInfoCompPtr);
	I_REF(ifile::IFileNameParam, m_documentFileCompPtr);
};


}  // namespace ifilegui


#endif // ifilegui_CExternalOpenDocumentCommandCompBase_included


