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


#ifndef iqtdoc_CExternalOpenDocumentCommandComp_included
#define iqtdoc_CExternalOpenDocumentCommandComp_included


// ACF includes
#include <imod/TSingleModelObserverBase.h>
#include <idoc/IDocumentManager.h>
#include <ifilegui/CExternalOpenDocumentCommandCompBase.h>


namespace iqtdoc
{


class CExternalOpenDocumentCommandComp:
			public ifilegui::CExternalOpenDocumentCommandCompBase,
			protected imod::TSingleModelObserverBase<idoc::IDocumentManager>
{
public:
	typedef ifilegui::CExternalOpenDocumentCommandCompBase BaseClass;

	I_BEGIN_COMPONENT(CExternalOpenDocumentCommandComp);
		I_ASSIGN(m_documentManagerCompPtr, "DocumentManager", "Manager of the documents in the MDI workspace", true, "DocumentManager");
		I_ASSIGN_TO(m_documentManagerModelCompPtr, m_documentManagerCompPtr, true);
		I_ASSIGN(m_documentTypeIdAttrPtr, "DocumentTypeId", "ID of the document type used by MDI workspace", true, "Default");
	I_END_COMPONENT;

protected:
	virtual void UpdateCommands();

	// reimplemented (ifilegui::CExternalOpenDocumentCommandCompBase)
	virtual const istd::IChangeable* GetDocumentPtr() const;

	// reimplemented (imod::CSingleModelObserverBase)
	virtual void OnUpdate(const istd::IChangeable::ChangeSet& changeSet);

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_REF(idoc::IDocumentManager, m_documentManagerCompPtr);
	I_REF(imod::IModel, m_documentManagerModelCompPtr);
	I_ATTR(QByteArray, m_documentTypeIdAttrPtr);
};


}  // namespace iqtdoc


#endif // iqtdoc_CExternalOpenDocumentCommandComp_included


