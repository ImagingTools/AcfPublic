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


#ifndef i2d_CArc_included
#define i2d_CArc_included


// Acf includes
#include "i2d/CCircle.h"


namespace i2d
{


class CArc: public CCircle
{
public:
	typedef CCircle BaseClass;

	CArc();
	CArc(double startAngle, double endAngle, const double radius, const CVector2d& center);

	double GetStartAngle() const;
	void SetStartAngle(double angle);

	double GetEndAngle() const;
	void SetEndAngle(double angle);

	bool operator==(const CArc& arc) const;
	bool operator!=(const CArc& arc) const;

	/**
	Get position of point using normed 'alpha' value.
	Value 0 will be mapped to point 1 and value 1 will be mapped to point 2.
	*/
	CVector2d GetPositionFromAlpha(double alpha) const;

	// reimplemented (i2d::IObject2d)
	virtual CRectangle GetBoundingBox() const;
	virtual bool Transform(
				const ITransformation2d& transformation,
				ITransformation2d::ExactnessMode mode = ITransformation2d::EM_NONE,
				double* errorFactorPtr = NULL);
	virtual bool InvTransform(
				const ITransformation2d& transformation,
				ITransformation2d::ExactnessMode mode = ITransformation2d::EM_NONE,
				double* errorFactorPtr = NULL);
	virtual bool GetTransformed(
				const ITransformation2d& transformation,
				IObject2d& result,
				ITransformation2d::ExactnessMode mode = ITransformation2d::EM_NONE,
				double* errorFactorPtr = NULL) const;
	virtual bool GetInvTransformed(
				const ITransformation2d& transformation,
				IObject2d& result,
				ITransformation2d::ExactnessMode mode = ITransformation2d::EM_NONE,
				double* errorFactorPtr = NULL) const;

	// reimplemented istd::IChangeable
	virtual int GetSupportedOperations() const;
	virtual bool CopyFrom(const IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS);
	virtual istd::IChangeable* CloneMe(CompatibilityMode mode = CM_WITHOUT_REFS) const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	double m_startAngle;
	double m_endAngle;
};


// public inline methods

inline double CArc::GetStartAngle() const
{
	return m_startAngle;
}


inline double CArc::GetEndAngle() const
{
	return m_endAngle;
}


} // namespace i2d


#endif // !i2d_CArc_included


