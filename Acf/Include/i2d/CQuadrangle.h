/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef i2d_CQuadrangle_included
#define i2d_CQuadrangle_included


#include "i2d/IObject2d.h"
#include "i2d/CLine2d.h"
#include "i2d/CRectangle.h"


namespace i2d
{

/**
	Definition of convexes quadrangle object.
*/
class CQuadrangle: virtual public IObject2d
{
public:
	CQuadrangle();
	CQuadrangle(const CQuadrangle& quadrangle);
	CQuadrangle(const CLine2d& firstDiagonal, const CLine2d& secondDiagonal);

	CQuadrangle& operator = (const CQuadrangle& quadrangle);

	bool operator==(const CQuadrangle& quadrangle) const;
	bool operator!=(const CQuadrangle& quadrangle) const;

	bool IsQuadrangleValid() const;
	bool IsQuadrangleEmpty() const;
	CRectangle GetBoundingBox() const;

	const CLine2d& GetFirstDiagonal() const;
	void SetFirstDiagonal(const CLine2d& firstDiagonal);

	const CLine2d& GetSecondDiagonal() const;
	void SetSecondDiagonal(const CLine2d& secondDiagonal);

	// reimplemented (IObject2d)
	virtual CVector2d GetCenter() const;
	virtual void MoveCenterTo(const CVector2d& position);
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

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	CLine2d m_firstDiagonal;
	CLine2d m_secondDiagonal;
};


} // namespace i2d


#endif // !i2d_CQuadrangle_included


