/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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


#include <iipr/CSearchFeature.h>


// ACF includes
#include <istd/TDelPtr.h>
#include <iser/IArchive.h>
#include <iser/CArchiveTag.h>


namespace iipr
{


// public methods

CSearchFeature::CSearchFeature()
	:m_isNegativeModelEnabled(false)
{
}


CSearchFeature::CSearchFeature(
			double weight,
			const i2d::CVector2d& position,
			double angle,
			const i2d::CVector2d& scale,
			bool negativeModel,
			const QByteArray& objectId)
	:BaseClass(weight, position, angle, scale),
	m_isNegativeModelEnabled(negativeModel)
{
	BaseClass::SetObjectId(objectId);
}


bool CSearchFeature::IsNegativeModelEnabled() const
{
	return m_isNegativeModelEnabled;
}


void CSearchFeature::SetNegativeModelEnabled(bool enable)
{
	if (m_isNegativeModelEnabled != enable){
		istd::CChangeNotifier notifier(this);
		
		m_isNegativeModelEnabled = enable;
	}
}


// reimplemented (iser::ISerializable)

bool CSearchFeature::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	retVal = retVal && BaseClass::Serialize(archive);

	static iser::CArchiveTag negativeModelTag("NegativeModelEnabled", "Is negative model enabled", iser::CArchiveTag::TT_LEAF);
	retVal = retVal && archive.BeginTag(negativeModelTag);
	retVal = retVal && archive.Process(m_isNegativeModelEnabled);
	retVal = retVal && archive.EndTag(negativeModelTag);

	return retVal;
}


// reimplemented (istd::IChangeable)

bool CSearchFeature::CopyFrom(const IChangeable& object, CompatibilityMode mode)
{
	const CSearchFeature* objectPtr = dynamic_cast<const CSearchFeature*>(&object);
	if (objectPtr != NULL){
		istd::CChangeNotifier notifier(this);

		m_isNegativeModelEnabled = objectPtr->IsNegativeModelEnabled();

		BaseClass::CopyFrom(object, mode);

		return true;
	}

	return false;
}

istd::IChangeableUniquePtr CSearchFeature::CloneMe(CompatibilityMode mode) const
{
	istd::TDelPtr<CSearchFeature> retVal(new CSearchFeature);

	if (retVal->CopyFrom(*this, mode)){
		return retVal.PopPtr();
	}

	return NULL;
}


} // namespace iipr


