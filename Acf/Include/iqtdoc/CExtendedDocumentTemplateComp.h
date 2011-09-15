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


#ifndef iqtdoc_CExtendedDocumentTemplateComp_included
#define iqtdoc_CExtendedDocumentTemplateComp_included


// Qt includes
#include <QObject>


// ACF includes
#include "idoc/CSingleDocumentTemplateComp.h"

#include "ibase/ICommandsProvider.h"

#include "iqtgui/IGuiObject.h"
#include "iqtgui/CHierarchicalCommand.h"

#include "iqtdoc/iqtdoc.h"


namespace iqtdoc
{


/**
	Extension of \c idoc::CSingleDocumentTemplateComp providing additional Qt-specified functionality.
*/
class CExtendedDocumentTemplateComp:
			public QObject,
			public idoc::CSingleDocumentTemplateComp,
			virtual public ibase::ICommandsProvider
{
	Q_OBJECT

public:
	typedef idoc::CSingleDocumentTemplateComp BaseClass;

	CExtendedDocumentTemplateComp();

	I_BEGIN_COMPONENT(CExtendedDocumentTemplateComp);
		I_REGISTER_INTERFACE(ibase::ICommandsProvider);
		I_ASSIGN(m_aboutCommandTextAttrPtr, "AboutCommandText", "Text used in about menu", true, "Document");
		I_ASSIGN(m_aboutGuiCompPtr, "AboutGui", "GUI used inside about dialog box", false, "AboutGui");
		I_ASSIGN(m_viewGuiCompFact, "ViewFactory", "Create of document GUI", true, "ViewFactory");
	I_END_COMPONENT;

	// reimplemented (ibase::ICommandsProvider)
	virtual const ibase::IHierarchicalCommand* GetCommands() const;

	// reimplemented (idoc::IDocumentTemplate)
	virtual Ids GetDocumentTypeIdsForFile(const istd::CString& filePath) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

protected Q_SLOTS:
	void OnAboutCommand();

protected:
	// reimplemented (idoc::CSingleDocumentTemplateComp)
	virtual istd::IPolymorphic* ExtractViewInterface(icomp::IComponent* componentPtr) const;

private:
	I_ATTR(istd::CString, m_aboutCommandTextAttrPtr);
	I_REF(iqtgui::IGuiObject, m_aboutGuiCompPtr);
	I_FACT(iqtgui::IGuiObject, m_viewGuiCompFact);

	iqtgui::CHierarchicalCommand m_globalMenuCommands;
	istd::CString m_aboutCommandText;
};


} // namespace iqtdoc


#endif // !iqtdoc_CExtendedDocumentTemplateComp_included


