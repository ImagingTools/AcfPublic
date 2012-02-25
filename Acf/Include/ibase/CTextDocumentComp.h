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


#ifndef ibase_CTextDocumentComp_included
#define ibase_CTextDocumentComp_included


// ACF includes
#include <QString>

#include "icomp/CComponentBase.h"

#include "ibase/ITextDocument.h"


namespace ibase
{


/**
	Simple implementation of a text document model.
*/
class CTextDocumentComp: public icomp::CComponentBase, virtual public ibase::ITextDocument
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CTextDocumentComp);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(ibase::ITextDocument);
		I_ASSIGN(m_defaultTextAttrPtr, "DefaultText", "Default text", false, "Hallo World!");
	I_END_COMPONENT;

	// reimplemented (ibase::ITextDocument)
	virtual QString GetText() const;
	virtual void SetText(const QString& text);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	QString m_text;

	I_ATTR(QString, m_defaultTextAttrPtr);
};


} // namespace ibase



#endif // !ibase_CTextDocumentComp_included


