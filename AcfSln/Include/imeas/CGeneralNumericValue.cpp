#include "imeas/CGeneralNumericValue.h"


// ACF includes
#include "istd/TChangeNotifier.h"
#include "iser/CArchiveTag.h"

namespace imeas
{

CGeneralNumericValue::CGeneralNumericValue()
{
	m_supportMap[imeas::INumericValue::VTI_AUTO] = false;
	m_supportMap[imeas::INumericValue::VTI_WEIGHT] = false;
	m_supportMap[imeas::INumericValue::VTI_POSITION] = false;
	m_supportMap[imeas::INumericValue::VTI_RADIUS] = false;
	m_supportMap[imeas::INumericValue::VTI_SCALE] = false;
	m_supportMap[imeas::INumericValue::VTI_ANGLE] = false;
	m_supportMap[imeas::INumericValue::VTI_ALPHA] = false;
	m_supportMap[imeas::INumericValue::VTI_LENGTH] = false;
	m_supportMap[imeas::INumericValue::VTI_2D_TRANSFORM] = false;
	m_supportMap[imeas::INumericValue::VTI_2D_LINE] = false;

	m_weightVector.SetElementsCount(1,0.0);
	m_positionVector.SetElementsCount(2,0.0);
	m_radiusVector.SetElementsCount(1,0.0);
	m_scaleVector.SetElementsCount(2,0.0);
	m_angleVector.SetElementsCount(1,0.0);
	m_alphaVector.SetElementsCount(1,0.0);
	m_lengthVector.SetElementsCount(1,0.0);
	m_2dTransformVector.SetElementsCount(6,0.0);
	m_2dLineVector.SetElementsCount(4,0.0);
}


double CGeneralNumericValue::GetWeight() const
{
	Q_ASSERT(m_weightVector.GetElementsCount() == 1);

	return m_weightVector[0];
}


void CGeneralNumericValue::SetWeight(double weight)
{
	if (m_weightVector[0] != weight){
		istd::CChangeNotifier notifier(this);

		m_weightVector[0] = weight;
	}
}


imath::CVarVector CGeneralNumericValue::GetPosition() const
{
	return m_positionVector;
}


void CGeneralNumericValue::SetPosition(imath::CVarVector position)
{
	if (m_positionVector != position){
		istd::CChangeNotifier notifier(this);
		
		m_positionVector = position;
	}
}


int CGeneralNumericValue::GetRadius() const
{
	Q_ASSERT(m_radiusVector.GetElementsCount() == 1);

	return m_radiusVector[0];
}

void CGeneralNumericValue::SetRadius(int radius)
{
	Q_ASSERT(m_radiusVector.GetElementsCount() == 1);

	m_radiusVector[0] = radius;
}


imath::CVarVector CGeneralNumericValue::GetScale() const
{
	return m_scaleVector;
}


void CGeneralNumericValue::SetScale(imath::CVarVector scale)
{
	m_scaleVector = scale;
}


double CGeneralNumericValue::GetAngle() const
{
	Q_ASSERT(m_angleVector.GetElementsCount() == 1);

	return m_angleVector[0];
}


void CGeneralNumericValue::SetAngle(double angle)
{
	m_angleVector[0] = angle;
}


double CGeneralNumericValue::GetAlpha() const
{
	Q_ASSERT(m_alphaVector.GetElementsCount() == 1);

	return m_alphaVector[0];
}


void CGeneralNumericValue::SetAlpha(double alpha)
{
	m_alphaVector[0] = alpha;
}


double CGeneralNumericValue::GetLength() const
{
	Q_ASSERT(m_lengthVector.GetElementsCount() == 1);

	return m_lengthVector[0];
}


void CGeneralNumericValue::SetLength(double length)
{
	m_lengthVector[0] = length;
}


imath::CVarVector CGeneralNumericValue::Get2dTransform() const
{
	return m_2dTransformVector;
}


void CGeneralNumericValue::Set2dTransform(imath::CVarVector transform)
{
	if (transform.GetElementsCount() != 6){
		transform.SetElementsCount(6, 0.0);
	}

	Q_ASSERT(transform.GetElementsCount() == 6);

	m_2dTransformVector = transform;
}


imath::CVarVector CGeneralNumericValue::Get2dLine() const
{
	return m_2dLineVector;
}


void CGeneralNumericValue::Set2dLine(imath::CVarVector line)
{
	if (line.GetElementsCount() != 4){
		line.SetElementsCount(4, 0.0);
	}

	Q_ASSERT(line.GetElementsCount() == 4);

	m_2dLineVector = line;
}


bool CGeneralNumericValue::IsValueTypeSupported(imeas::INumericValue::ValueTypeId valueTypeId) const
{
	return m_supportMap.value(valueTypeId, false);
}


const imeas::INumericConstraints* CGeneralNumericValue::GetNumericConstraints() const
{
	return NULL;
}


imath::CVarVector CGeneralNumericValue::GetComponentValue(imeas::INumericValue::ValueTypeId valueTypeId) const
{
	switch(valueTypeId)
	{
	case imeas::INumericValue::VTI_WEIGHT:
		return m_weightVector;
	case imeas::INumericValue::VTI_POSITION:
		return m_positionVector;
	case imeas::INumericValue::VTI_RADIUS:
		return m_radiusVector;
	case imeas::INumericValue::VTI_SCALE:
		return m_scaleVector;
	case imeas::INumericValue::VTI_ANGLE:
		return m_angleVector;
	case imeas::INumericValue::VTI_ALPHA:
		return m_alphaVector;
	case imeas::INumericValue::VTI_LENGTH:
		return m_lengthVector;
	case imeas::INumericValue::VTI_2D_TRANSFORM:
		return m_2dTransformVector;
	case imeas::INumericValue::VTI_2D_LINE:
		return m_2dLineVector;
	default:
		return imath::CVarVector();
	}
}


imath::CVarVector CGeneralNumericValue::GetValues() const
{
	int size = m_weightVector.GetElementsCount() + m_positionVector.GetElementsCount() + m_radiusVector.GetElementsCount() + m_scaleVector.GetElementsCount() + m_angleVector.GetElementsCount() + m_alphaVector.GetElementsCount() + m_lengthVector.GetElementsCount() + m_2dTransformVector.GetElementsCount() + m_2dLineVector.GetElementsCount();
	imath::CVarVector retVal(size);

	int retValIndex = 0;

	for (int i = 0; i < m_weightVector.GetElementsCount(); i++){
		retVal[retValIndex] = m_weightVector.GetElement(i);
		retValIndex++;
	}
	for (int i = 0; i < m_positionVector.GetElementsCount(); i++){
		retVal[retValIndex] = m_positionVector.GetElement(i);
		retValIndex++;
	}
	for (int i = 0; i < m_radiusVector.GetElementsCount(); i++){
		retVal[retValIndex] = m_radiusVector.GetElement(i);
		retValIndex++;
	}
	for (int i = 0; i < m_scaleVector.GetElementsCount(); i++){
		retVal[retValIndex] = m_scaleVector.GetElement(i);
		retValIndex++;
	}
	for (int i = 0; i < m_angleVector.GetElementsCount(); i++){
		retVal[retValIndex] = m_angleVector.GetElement(i);
		retValIndex++;
	}
	for (int i = 0; i < m_alphaVector.GetElementsCount(); i++){
		retVal[retValIndex] = m_alphaVector.GetElement(i);
		retValIndex++;
	}
	for (int i = 0; i < m_lengthVector.GetElementsCount(); i++){
		retVal[retValIndex] = m_lengthVector.GetElement(i);
		retValIndex++;
	}
	for (int i = 0; i < m_2dTransformVector.GetElementsCount(); i++){
		retVal[retValIndex] = m_2dTransformVector.GetElement(i);
		retValIndex++;
	}
	for (int i = 0; i < m_2dLineVector.GetElementsCount(); i++){
		retVal[retValIndex] = m_2dLineVector.GetElement(i);
		retValIndex++;
	}

	return retVal;
}


bool CGeneralNumericValue::SetValues(const imath::CVarVector& /*values*/)
{
	return false;
}

bool CGeneralNumericValue::Serialize(iser::IArchive &archive)
{
	static iser::CArchiveTag weightTag("Weight", "weight value");
	static iser::CArchiveTag positionTag("Position", "position value");
	static iser::CArchiveTag radiusTag("Radius", "radius value");
	static iser::CArchiveTag scaleTag("Scale", "scale value");
	static iser::CArchiveTag angleTag("Angle", "angle value");
	static iser::CArchiveTag alphaTag("Alpha", "alpha value");
	static iser::CArchiveTag lengthTag("Length", "length value");
	static iser::CArchiveTag transformTag("Transform", "transform value");
	static iser::CArchiveTag lineTag("Line", "line value");

	static iser::CArchiveTag supportTag("Supported", "List of supported values");
	static iser::CArchiveTag supportValueTag("SupportedValues", "supported value");

	bool retVal = true;

	int count = m_supportMap.size();
	retVal = retVal && archive.BeginMultiTag(supportTag, supportValueTag, count);

	if (archive.IsStoring()){
		for (SupportMap::const_iterator it = m_supportMap.begin(); it != m_supportMap.end(); ++it){
			int id = it.key();
			bool active = it.value();

			retVal = retVal && archive.BeginTag(supportValueTag);
			retVal = retVal && archive.Process(id);
			retVal = retVal && archive.Process(active);
			retVal = retVal && archive.EndTag(supportValueTag);
		}
	}
	else{
		m_supportMap.clear();

		for (int i = 0; i < count; i++){
			imeas::INumericValue::ValueTypeId id = imeas::INumericValue::VTI_AUTO;
			bool active;

			retVal = retVal && archive.BeginTag(supportValueTag);
			retVal = retVal && archive.Process((qint8&)id);
			retVal = retVal && archive.Process(active);
			retVal = retVal && archive.EndTag(supportValueTag);

			m_supportMap.insert(id, active);
		}
	}

	retVal = retVal && archive.EndTag(supportTag);

	retVal = retVal && archive.BeginTag(weightTag);
	retVal = retVal && m_weightVector.Serialize(archive);
	retVal = retVal && archive.EndTag(weightTag);

	retVal = retVal && archive.BeginTag(positionTag);
	retVal = retVal && m_positionVector.Serialize(archive);
	retVal = retVal && archive.EndTag(positionTag);

	retVal = retVal && archive.BeginTag(radiusTag);
	retVal = retVal && m_radiusVector.Serialize(archive);
	retVal = retVal && archive.EndTag(radiusTag);

	retVal = retVal && archive.BeginTag(scaleTag);
	retVal = retVal && m_scaleVector.Serialize(archive);
	retVal = retVal && archive.EndTag(scaleTag);

	retVal = retVal && archive.BeginTag(angleTag);
	retVal = retVal && m_angleVector.Serialize(archive);
	retVal = retVal && archive.EndTag(angleTag);

	retVal = retVal && archive.BeginTag(alphaTag);
	retVal = retVal && m_alphaVector.Serialize(archive);
	retVal = retVal && archive.EndTag(alphaTag);

	retVal = retVal && archive.BeginTag(lengthTag);
	retVal = retVal && m_lengthVector.Serialize(archive);
	retVal = retVal && archive.EndTag(lengthTag);

	retVal = retVal && archive.BeginTag(transformTag);
	retVal = retVal && m_2dTransformVector.Serialize(archive);
	retVal = retVal && archive.EndTag(transformTag);

	retVal = retVal && archive.BeginTag(lineTag);
	retVal = retVal && m_2dLineVector.Serialize(archive);
	retVal = retVal && archive.EndTag(lineTag);

	return retVal;
}

bool CGeneralNumericValue::CopyFrom(const istd::IChangeable& object, CompatibilityMode /*mode*/)
{
	const imeas::INumericValue* sourcePtr = dynamic_cast<const imeas::INumericValue*>(&object);

	if (sourcePtr != NULL){
		istd::CChangeNotifier notifier(this);

		if (m_supportMap[imeas::INumericValue::VTI_WEIGHT] = sourcePtr->IsValueTypeSupported(imeas::INumericValue::VTI_WEIGHT)){
			SetWeight(sourcePtr->GetComponentValue(imeas::INumericValue::VTI_WEIGHT)[0]);
		}
		if (m_supportMap[imeas::INumericValue::VTI_POSITION] = sourcePtr->IsValueTypeSupported(imeas::INumericValue::VTI_POSITION)){
			SetPosition(sourcePtr->GetComponentValue(imeas::INumericValue::VTI_POSITION));
		}
		if (m_supportMap[imeas::INumericValue::VTI_RADIUS] = sourcePtr->IsValueTypeSupported(imeas::INumericValue::VTI_RADIUS)){
			SetRadius(sourcePtr->GetComponentValue(imeas::INumericValue::VTI_RADIUS)[0]);
		}
		if (m_supportMap[imeas::INumericValue::VTI_SCALE] = sourcePtr->IsValueTypeSupported(imeas::INumericValue::VTI_SCALE)){
			SetScale(sourcePtr->GetComponentValue(imeas::INumericValue::VTI_SCALE));
		}
		if (m_supportMap[imeas::INumericValue::VTI_ANGLE] = sourcePtr->IsValueTypeSupported(imeas::INumericValue::VTI_ANGLE)){
			SetAngle(sourcePtr->GetComponentValue(imeas::INumericValue::VTI_ANGLE)[0]);
		}
		if (m_supportMap[imeas::INumericValue::VTI_ALPHA] = sourcePtr->IsValueTypeSupported(imeas::INumericValue::VTI_ALPHA)){
			SetAlpha(sourcePtr->GetComponentValue(imeas::INumericValue::VTI_ALPHA)[0]);
		}
		if (m_supportMap[imeas::INumericValue::VTI_LENGTH] = sourcePtr->IsValueTypeSupported(imeas::INumericValue::VTI_LENGTH)){
			SetLength(sourcePtr->GetComponentValue(imeas::INumericValue::VTI_LENGTH)[0]);
		}
		if (m_supportMap[imeas::INumericValue::VTI_2D_TRANSFORM] = sourcePtr->IsValueTypeSupported(imeas::INumericValue::VTI_2D_TRANSFORM)){
			Set2dTransform(sourcePtr->GetComponentValue(imeas::INumericValue::VTI_2D_TRANSFORM));
		}
		if (m_supportMap[imeas::INumericValue::VTI_2D_LINE] = sourcePtr->IsValueTypeSupported(imeas::INumericValue::VTI_2D_LINE)){
			Set2dLine(sourcePtr->GetComponentValue(imeas::INumericValue::VTI_2D_LINE));
		}
		return true;
	}

	return false;
}

istd::IChangeable* CGeneralNumericValue::CloneMe(CompatibilityMode mode) const
{
	CGeneralNumericValue* value = new CGeneralNumericValue();

	value->CopyFrom( *this, mode);

	return value;
}


} // namespace imeas