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


#include <iprm/CTextParam.h>


// ACF includes
#include <istd/TDelPtr.h>
#include <istd/CChangeNotifier.h>
#include <iser/IArchive.h>
#include <iser/CArchiveTag.h>


namespace iprm
{



// reimplemented (iprm::INameParam)

const QString& CTextParam::GetText() const
{
	return m_text;
}


void CTextParam::SetText(const QString& text)
{
	if (m_text != text){
		istd::CChangeNotifier notifier(this);
		Q_UNUSED(notifier);

		m_text = text;
	}
}


bool CTextParam::IsReadonly() const
{
	return false;
}


// reimplemented (iser::ISerializable)

bool CTextParam::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag nameTag("Name", "Object name", iser::CArchiveTag::TT_LEAF);

	istd::CChangeNotifier notifier(archive.IsStoring()? NULL: this);
	Q_UNUSED(notifier);

	bool retVal = archive.BeginTag(nameTag);
	retVal = retVal && archive.Process(m_text);
	retVal = retVal && archive.EndTag(nameTag);

	return retVal;
}


// reimplemented (istd::IChangeable)

bool CTextParam::CopyFrom(const IChangeable& object, CompatibilityMode /*mode*/)
{
	const ITextParam* sourcePtr = dynamic_cast<const ITextParam*>(&object);
	if (sourcePtr != NULL){
		SetText(sourcePtr->GetText());

		return true;
	}

	return false;
}


istd::IChangeable* CTextParam::CloneMe(istd::IChangeable::CompatibilityMode mode) const
{
	istd::TDelPtr<CTextParam> clonePtr(new CTextParam);
	if (clonePtr->CopyFrom(*this, mode)){
		return clonePtr.PopPtr();
	}

	return NULL;
}


} // namespace iprm


