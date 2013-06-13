#ifndef imeas_CGeneralNumericValue_included
#define imeas_CGeneralNumericValue_included


// Qt includes
#include "QtCore/QMap"

// ACF includes
#include "imath/CVarVector.h"

// ACF-Solutions includes
#include "imeas/INumericValue.h"

namespace imeas
{


class CGeneralNumericValue: virtual public imeas::INumericValue
{
public:
	CGeneralNumericValue();

	double GetWeight() const;
	void SetWeight(double weight);
	imath::CVarVector GetPosition() const;
	void SetPosition(imath::CVarVector position);
	int GetRadius() const;
	void SetRadius(int radius);
	imath::CVarVector GetScale() const;
	void SetScale(imath::CVarVector scale);
	double GetAngle() const;
	void SetAngle(double angle);
	double GetAlpha() const;
	void SetAlpha(double alpha);
	double GetLength() const;
	void SetLength(double length);
	imath::CVarVector Get2dTransform() const;
	void Set2dTransform(imath::CVarVector transform);
	imath::CVarVector Get2dLine() const;
	void Set2dLine(imath::CVarVector line);

	// reimplemented (imeas::INumericValue)
	virtual bool IsValueTypeSupported(imeas::INumericValue::ValueTypeId valueTypeId) const;
	virtual const imeas::INumericConstraints* GetNumericConstraints() const;
	virtual imath::CVarVector GetComponentValue(imeas::INumericValue::ValueTypeId valueTypeId) const;
	virtual imath::CVarVector GetValues() const;
	virtual bool SetValues(const imath::CVarVector& values);

	// reimplemented (iser::ISerializable)
	virtual bool iser::ISerializable::Serialize(iser::IArchive &archive);

	// reimplemented (istd::IChangable)
	virtual bool CopyFrom(const istd::IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS);
	virtual IChangeable* CloneMe(CompatibilityMode mode = CM_WITHOUT_REFS) const;

private:
	typedef QMap<imeas::INumericValue::ValueTypeId, bool> SupportMap;
	SupportMap m_supportMap;

	imath::CVarVector m_weightVector;
	imath::CVarVector m_positionVector;
	imath::CVarVector m_radiusVector;
	imath::CVarVector m_scaleVector;
	imath::CVarVector m_angleVector;
	imath::CVarVector m_alphaVector;
	imath::CVarVector m_lengthVector;
	imath::CVarVector m_2dTransformVector;
	imath::CVarVector m_2dLineVector;
};


} // namespace imeas


#endif // !imeas_CGeneralNumericValue_included


