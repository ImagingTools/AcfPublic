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


// reimplemented (iprm::ITextParam)

QString CTextParam::GetText() const
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


bool CTextParam::IsReadOnly() const
{
	return false;
}


// reimplemented (iser::ISerializable)

bool CTextParam::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag textTag("Text", "Text", iser::CArchiveTag::TT_LEAF);

	istd::CChangeNotifier notifier(archive.IsStoring()? NULL: this);
	Q_UNUSED(notifier);

	bool retVal = archive.BeginTag(textTag);
	retVal = retVal && archive.Process(m_text);
	retVal = retVal && archive.EndTag(textTag);

	return retVal;
}


// reimplemented (istd::IChangeable)

int CTextParam::GetSupportedOperations() const
{
	return SO_CLONE | SO_COPY | SO_COMPARE | SO_RESET;
}


bool CTextParam::CopyFrom(const IChangeable& object, CompatibilityMode /*mode*/)
{
	const ITextParam* sourcePtr = dynamic_cast<const ITextParam*>(&object);
	if (sourcePtr != NULL){
		SetText(sourcePtr->GetText());

		return true;
	}

	return false;
}


bool CTextParam::IsEqual(const IChangeable& object) const
{
	const ITextParam* sourcePtr = dynamic_cast<const ITextParam*>(&object);
	if (sourcePtr != NULL){
		return (m_text == sourcePtr->GetText());
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


bool CTextParam::ResetData(CompatibilityMode /*mode*/)
{
	if (!m_text.isEmpty()){
		istd::CChangeNotifier changeNotifier(this);

		m_text.clear();
	}

	return true;
}


} // namespace iprm


