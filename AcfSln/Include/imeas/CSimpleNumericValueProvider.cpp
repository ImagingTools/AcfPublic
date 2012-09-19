/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "imeas/CSimpleNumericValueProvider.h"


// ACF includes
#include "istd/TChangeNotifier.h"


namespace imeas
{


// reimplemented (imeas::INumericValueProvider)

int CSimpleNumericValueProvider::GetValuesCount() const
{
	return m_values.count();
}


const imeas::INumericValue& CSimpleNumericValueProvider::GetNumericValue(int index) const
{
	I_ASSERT(index >= 0);
	I_ASSERT(index < m_values.count());

	return m_values[index];
}


// reimplemented (iser::ISerializable)

bool CSimpleNumericValueProvider::Serialize(iser::IArchive& archive)
{
	istd::CChangeNotifier notifier(archive.IsStoring() ? NULL : this);

	static iser::CArchiveTag valuesTag("Values", "List of numeric values");
	static iser::CArchiveTag valueTag("Value", "Single value");

	int valuesCount = m_values.count();

	bool retVal = archive.BeginMultiTag(valuesTag, valueTag, valuesCount);

	if (!archive.IsStoring()){
		m_values.resize(valuesCount);
	}

	for (int valueIndex = 0; valueIndex < valuesCount; valueIndex++){
		retVal = retVal && m_values[valueIndex].Serialize(archive);
	}

	return retVal;
}


// reimplemented (istd::IChangeable)

bool CSimpleNumericValueProvider::CopyFrom(const IChangeable& object)
{
	const imeas::INumericValueProvider* sourcePtr = dynamic_cast<const imeas::INumericValueProvider*>(&object);
	if (sourcePtr != NULL){
		istd::CChangeNotifier notifier(this);
		int valuesCount = sourcePtr->GetValuesCount();

		m_values.resize(valuesCount);

		for (int valueIndex = 0; valueIndex < valuesCount; valueIndex++){
			const imeas::INumericValue& sourceValue = sourcePtr->GetNumericValue(valueIndex);

			m_values[valueIndex].SetValues(sourceValue.GetValues());
		}

		return true;
	}

	return false;
}


} // namespace imeas


