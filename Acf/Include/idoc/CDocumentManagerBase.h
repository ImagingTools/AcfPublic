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


#ifndef idoc_CDocumentManagerBase_included
#define idoc_CDocumentManagerBase_included


#include "idoc/IDocumentManager.h"


namespace idoc
{


class IDocumentTemplate;


class CDocumentManagerBase: virtual public idoc::IDocumentManager
{
public:
	CDocumentManagerBase();

	void SetDocumentTemplate(const idoc::IDocumentTemplate* documentTemplatePtr);

	// reimplemented (idoc::IDocumentManager)
	virtual int GetAllowedOperationFlags(const istd::IPolymorphic* viewPtr = NULL) const;
	virtual const idoc::IDocumentTemplate* GetDocumentTemplate() const;

private:
	const IDocumentTemplate* m_documentTemplatePtr;

	int m_baseAllowedFlags;
};


} // namespace idoc


#endif // idoc_CDocumentManagerBase_included


