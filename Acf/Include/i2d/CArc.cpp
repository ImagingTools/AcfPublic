#include "i2d/CArc.h"


// ACF includes
#include "istd/TChangeNotifier.h"

#include "i2d/CAffine2d.h"
#include "i2d/CRectangle.h"

#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"
#include "istd/TDelPtr.h"


namespace i2d
{


CArc::CArc()
:	m_startAngle(0), 
	m_angleWidth(0)
{
}


CArc::CArc(double startAngle, double angleWidth, const double radius, const CVector2d& center)
:	BaseClass(radius, center), m_startAngle(startAngle), m_angleWidth(angleWidth)
{
}


void CArc::SetStartAngle(double angle)
{
	if (angle != m_startAngle){
		istd::CChangeNotifier notifier(this);

		m_startAngle = angle;
	}
}


void CArc::SetAngleWidth(double angle)
{
	if (angle != m_angleWidth){
		istd::CChangeNotifier notifier(this);

		m_angleWidth = angle;
	}
}


bool CArc::operator==(const CArc& ref) const
{
	return (ref.GetStartAngle() == GetStartAngle() && ref.GetAngleWidth() == GetAngleWidth() && ref.GetRadius() == GetRadius() && ref.GetPosition() == GetPosition());
}


bool CArc::operator!=(const CArc& ref) const
{
	return !operator==(ref);
}


// reimplemented (i2d::IObject2d)

CRectangle CArc::GetBoundingBox() const
{
	return CRectangle(
		m_position.GetX() - m_radius, 
		m_position.GetY() - m_radius, 
		2 * m_radius, 
		2 * m_radius); 
}


bool CArc::Transform(
						const ITransformation2d& transformation,
						ITransformation2d::ExactnessMode mode,
						double* errorFactorPtr)
{
	CVector2d transPos;
	if (!transformation.GetPositionAt(m_position, transPos, mode)){
		return false;
	}

	CAffine2d affine;
	if (!transformation.GetLocalTransform(m_position, affine, mode)){
		return false;
	}

	istd::CChangeNotifier changePtr(this);

	double scale = affine.GetDeformMatrix().GetApproxScale();

	SetPosition(transPos);
	SetRadius(m_radius * scale);

	if (errorFactorPtr != NULL){
		*errorFactorPtr = 0;
	}

	return true;
}


bool CArc::InvTransform(
						   const ITransformation2d& transformation,
						   ITransformation2d::ExactnessMode mode,
						   double* errorFactorPtr)
{
	CVector2d transPos;
	if (!transformation.GetInvPositionAt(m_position, transPos, mode)){
		return false;
	}

	CAffine2d affine;
	if (!transformation.GetLocalInvTransform(m_position, affine, mode)){
		return false;
	}

	istd::CChangeNotifier changePtr(this);

	double scale = affine.GetDeformMatrix().GetApproxScale();

	SetPosition(transPos);
	SetRadius(m_radius * scale);

	if (errorFactorPtr != NULL){
		*errorFactorPtr = 0;
	}

	return true;
}


bool CArc::GetTransformed(
							 const ITransformation2d& transformation,
							 IObject2d& result,
							 ITransformation2d::ExactnessMode mode,
							 double* errorFactorPtr) const
{
	CArc* arcPtr = dynamic_cast<CArc*>(&result);
	if (arcPtr == NULL){
		return false;
	}

	istd::CChangeNotifier changePtr(arcPtr);

	arcPtr->SetPosition(m_position);
	arcPtr->SetRadius(m_radius);
	arcPtr->SetStartAngle(m_startAngle);
	arcPtr->SetAngleWidth(m_angleWidth);

	return arcPtr->Transform(transformation, mode, errorFactorPtr);
}


bool CArc::GetInvTransformed(
								const ITransformation2d& transformation,
								IObject2d& result,
								ITransformation2d::ExactnessMode mode,
								double* errorFactorPtr) const
{
	CArc* arcPtr = dynamic_cast<CArc*>(&result);
	if (arcPtr == NULL){
		return false;
	}

	istd::CChangeNotifier changePtr(arcPtr);

	arcPtr->SetPosition(m_position);
	arcPtr->SetRadius(m_radius);
	arcPtr->SetStartAngle(m_startAngle);
	arcPtr->SetAngleWidth(m_angleWidth);

	return arcPtr->InvTransform(transformation, mode, errorFactorPtr);
}


// reimplemented (istd::IChangeable)

int CArc::GetSupportedOperations() const
{
	return SO_COPY | SO_CLONE;
}


bool CArc::CopyFrom(const IChangeable& object, CompatibilityMode mode)
{
	const CArc* arcPtr = dynamic_cast<const CArc*>(&object);

	if (arcPtr != NULL){
		istd::CChangeNotifier notifier(this);

		SetStartAngle(arcPtr->GetStartAngle());
		SetAngleWidth(arcPtr->GetAngleWidth());

		CCircle::CopyFrom(object, CM_STRICT);


		return true;
	}	

	return false;
}


istd::IChangeable* CArc::CloneMe(CompatibilityMode mode) const 
{
	istd::TDelPtr<CArc> clonePtr(new CArc);

	if (clonePtr->CopyFrom(*this, mode)){
		return clonePtr.PopPtr();
	}

	return NULL;
}


// reimplemented (iser::ISerializable)

bool CArc::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag startAngleTag("StartAngle", "Start angle");
	static iser::CArchiveTag angleWidthTag("AngleWidth", "Width of angle");

	istd::CChangeNotifier notifier(archive.IsStoring()? NULL: this, CF_OBJECT_POSITION | CF_MODEL);

	bool retVal = true;

	retVal = retVal && BaseClass::Serialize(archive);

	retVal = retVal && archive.BeginTag(startAngleTag);
	retVal = retVal && archive.Process(m_startAngle);
	retVal = retVal && archive.EndTag(startAngleTag);

	retVal = retVal && archive.BeginTag(angleWidthTag);
	retVal = retVal && archive.Process(m_angleWidth);
	retVal = retVal && archive.EndTag(angleWidthTag);

	return retVal;
}

} // namespace i2d