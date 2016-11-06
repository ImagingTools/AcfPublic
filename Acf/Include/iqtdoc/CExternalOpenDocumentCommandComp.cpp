/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#include <iqtdoc/CExternalOpenDocumentCommandComp.h>


// Qt includes
#include <QtCore/QProcess>


namespace iqtdoc
{


// protected methods

void CExternalOpenDocumentCommandComp::UpdateCommands()
{
	m_startProcessCommand.SetEnabled(false);

	const idoc::IDocumentManager* objectPtr = GetObservedObject();
	if (objectPtr != NULL){
		istd::IPolymorphic* activeViewPtr = objectPtr->GetActiveView();
		if (activeViewPtr != NULL){
			idoc::IDocumentManager::DocumentInfo documentInfo;
			istd::IChangeable* documentPtr = objectPtr->GetDocumentFromView(*activeViewPtr, &documentInfo);
			if ((documentPtr != NULL) && (documentInfo.documentTypeId == *m_documentTypeIdAttrPtr)){
				m_startProcessCommand.SetEnabled(true);
			}
		}
	}
}


// reimplemented (ifilegui::CExternalOpenDocumentCommandCompBase)

const istd::IChangeable* CExternalOpenDocumentCommandComp::GetDocumentPtr() const
{
	Q_ASSERT(m_documentManagerCompPtr.IsValid());

	istd::IPolymorphic* activeViewPtr = m_documentManagerCompPtr->GetActiveView();
	if (activeViewPtr != NULL){
		return m_documentManagerCompPtr->GetDocumentFromView(*activeViewPtr);
	}

	return NULL;
}


// reimplemented (iqtgui::CStartProcessCommandComp)

void CExternalOpenDocumentCommandComp::CreateMenu()
{
	m_fileCommand.SetName(QCoreApplication::tr("File"));
	m_fileCommand.SetStaticFlags(ibase::ICommand::CF_GLOBAL_MENU);
	
	m_fileCommand.InsertChild(&m_startProcessCommand);
	m_rootCommands.InsertChild(&m_fileCommand);
}


// reimplemented (imod::CSingleModelObserverBase)

void CExternalOpenDocumentCommandComp::OnUpdate(const ChangeSet& /*changeSet*/)
{
	UpdateCommands();
}


// reimplemented (icomp::CComponentBase)

void CExternalOpenDocumentCommandComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (!m_documentManagerCompPtr.IsValid()){
		m_startProcessCommand.setEnabled(false);
	}

	if (m_documentManagerModelCompPtr.IsValid()){
		m_documentManagerModelCompPtr->AttachObserver(this);
	}

	UpdateCommands();
}


void CExternalOpenDocumentCommandComp::OnComponentDestroyed()
{
	EnsureModelDetached();

	BaseClass::OnComponentDestroyed();
}


} // namespace iqtdoc


