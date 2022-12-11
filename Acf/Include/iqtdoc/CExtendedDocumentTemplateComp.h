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


#ifndef iqtdoc_CExtendedDocumentTemplateComp_included
#define iqtdoc_CExtendedDocumentTemplateComp_included


// ACF includes
#include <idoc/CSingleDocumentTemplateComp.h>

#include <iqtgui/IGuiObject.h>


namespace iqtdoc
{


/**
	Extension of \c idoc::CSingleDocumentTemplateComp providing additional Qt-specified functionality.
*/
class CExtendedDocumentTemplateComp: public idoc::CSingleDocumentTemplateComp
{
public:
	typedef idoc::CSingleDocumentTemplateComp BaseClass;

	I_BEGIN_COMPONENT(CExtendedDocumentTemplateComp);
		I_ASSIGN(m_viewGuiCompFact, "ViewFactory", "Create of document GUI", true, "ViewFactory");
	I_END_COMPONENT;

	// reimplemented (idoc::IDocumentTemplate)
	virtual Ids GetDocumentTypeIdsForFile(const QString& filePath) const;

protected:
	// reimplemented (idoc::CSingleDocumentTemplateComp)
	virtual istd::IPolymorphic* ExtractViewInterface(icomp::IComponent* componentPtr) const;

private:
	I_FACT(iqtgui::IGuiObject, m_viewGuiCompFact);
};


} // namespace iqtdoc


#endif // !iqtdoc_CExtendedDocumentTemplateComp_included


