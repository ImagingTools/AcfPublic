/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "i2d/CLabel.h"


// ACF includes
#include "istd/CChangeNotifier.h"
#include "istd/TDelPtr.h"
#include "iser/CArchiveTag.h"


namespace i2d
{


// public methods

CLabel::CLabel(const i2d::CVector2d& position, const QString& labelText)
:	BaseClass(position), 
	m_text(labelText)
{
}


void CLabel::SetText(const QString& labelText)
{
	m_text = labelText;
}


// reimplemented (iser::ISerializable)

bool CLabel::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag textTag("Text", "Text of label");

	static ChangeSet changeSet(CF_OBJECT_POSITION, CF_ALL_DATA);
	istd::CChangeNotifier notifier(archive.IsStoring()? NULL: this, changeSet);

	bool retVal = true;

	retVal = retVal && BaseClass::Serialize(archive);

	retVal = retVal && archive.BeginTag(textTag);
	retVal = retVal && archive.Process(m_text);
	retVal = retVal && archive.EndTag(textTag);

	return retVal;
}


// reimplemented (istd::IChangeable)

int CLabel::GetSupportedOperations() const
{
	return SO_COPY | SO_CLONE;
}


bool CLabel::CopyFrom(const IChangeable& object, CompatibilityMode mode)
{
	const CLabel* labelPtr = dynamic_cast<const CLabel*>(&object);

	if (labelPtr != NULL){
		istd::CChangeNotifier notifier(this);
		
		SetPosition(labelPtr->GetPosition());
		SetText(labelPtr->GetText());

		CObject2dBase::CopyFrom(object, mode);

		return true;
	}

	return false;
}


istd::IChangeable* CLabel::CloneMe(CompatibilityMode mode) const 
{
	istd::TDelPtr<CLabel> clonePtr(new CLabel);

	if (clonePtr->CopyFrom(*this, mode)){
		return clonePtr.PopPtr();
	}

	return NULL;
}


} // namespace i2d


