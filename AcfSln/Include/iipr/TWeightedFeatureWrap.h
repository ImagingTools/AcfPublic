/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iipr_TFeatureWrap_included
#define iipr_TFeatureWrap_included


// ACF includes
#include "istd/CChangeNotifier.h"

// ACF-Solutions includes
#include "imeas/CSimpleNumericValue.h"


namespace iipr
{


/**
	Wrapper allowing to create feature object from some another serializable one.
*/
template <class BaseObject>
class TWeightedFeatureWrap:
			public imeas::CSimpleNumericValue,
			public BaseObject
{
public:
	typedef imeas::CSimpleNumericValue BaseClass;
	typedef BaseObject BaseClass2;

	TWeightedFeatureWrap(double weight = 1.0);

	double GetWeight() const;
	void SetWeight(double weight);

	// reimplemented (imeas::INumericValue)
	virtual bool IsValueTypeSupported(ValueTypeId valueTypeId) const;
	virtual imath::CVarVector GetComponentValue(ValueTypeId valueTypeId) const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const IChangeable& object, CompatibilityMode mode);

protected:
	double m_weight;
};


// public methods

template <class BaseObject>
TWeightedFeatureWrap<BaseObject>::TWeightedFeatureWrap(double weight)
	:m_weight(weight)
{
}


template <class BaseObject>
double TWeightedFeatureWrap<BaseObject>::GetWeight() const
{
	return m_weight;
}


template <class BaseObject>
void TWeightedFeatureWrap<BaseObject>::SetWeight(double weight)
{
	m_weight = weight;
}


// reimplemented (imeas::INumericValue)

template <class BaseObject>
bool TWeightedFeatureWrap<BaseObject>::IsValueTypeSupported(ValueTypeId valueTypeId) const
{
	return (valueTypeId == VTI_AUTO || valueTypeId == VTI_WEIGHT);
}


template <class BaseObject>
imath::CVarVector TWeightedFeatureWrap<BaseObject>::GetComponentValue(ValueTypeId valueTypeId) const
{
	if (valueTypeId == VTI_AUTO){
		return m_values;
	}

	if (valueTypeId == VTI_WEIGHT){
		return imath::CVarVector(1, m_weight);
	}

	return imath::CVarVector();
}


// reimplemented (iser::ISerializable)

template <class BaseObject>
bool TWeightedFeatureWrap<BaseObject>::Serialize(iser::IArchive& archive)
{
	iser::CArchiveTag weightTag("Weight", "Weight", iser::CArchiveTag::TT_LEAF);

	istd::CChangeNotifier notifier(archive.IsStoring()? NULL: this);
	Q_UNUSED(notifier);

	bool retVal = true;

	retVal = retVal && BaseClass::Serialize(archive);
	retVal = retVal && BaseClass2::Serialize(archive);

	retVal = retVal && archive.BeginTag(weightTag);
	retVal = retVal && archive.Process(m_weight);
	retVal = retVal && archive.EndTag(weightTag);

	return retVal;
}


// reimplemented (istd::IChangeable)

template <class BaseObject>
bool TWeightedFeatureWrap<BaseObject>::CopyFrom(const IChangeable& object, CompatibilityMode mode)
{
	const TWeightedFeatureWrap<BaseObject>* objectPtr = dynamic_cast<const TWeightedFeatureWrap<BaseObject>*>(&object);
	if (objectPtr != NULL){
		m_weight = objectPtr->GetWeight();
	}

	return BaseObject::CopyFrom(object, mode);
}


} // namespace iipr


#endif // !iipr_TFeatureWrap_included


