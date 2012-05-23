/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "i2d/CParallelogram.h"


// ACF includes
#include "istd/TChangeNotifier.h"


namespace i2d
{


// reimplemented (i2d::IObject2d)

i2d::CVector2d CParallelogram::GetCenter() const
{
	return m_transform.GetTranslation();
}


void CParallelogram::MoveCenterTo(const i2d::CVector2d& position)
{
	m_transform.SetTranslation(position);
}


bool CParallelogram::Transform(
			const i2d::ITransformation2d& transformation,
			i2d::ITransformation2d::ExactnessMode mode,
			double* /*errorFactorPtr*/)
{
	i2d::CAffine2d localTransform;
	if (transformation.GetLocalTransform(GetCenter(), localTransform, mode)){
		m_transform.Apply(localTransform);

		return true;
	}

	return true;
}


bool CParallelogram::InvTransform(
			const i2d::ITransformation2d& transformation,
			i2d::ITransformation2d::ExactnessMode mode,
			double* /*errorFactorPtr*/)
{
	i2d::CAffine2d localTransform;
	if (transformation.GetLocalInvTransform(GetCenter(), localTransform, mode)){
		m_transform.Apply(localTransform);

		return true;
	}

	return true;
}


bool CParallelogram::GetTransformed(
			const i2d::ITransformation2d& transformation,
			i2d::IObject2d& result,
			i2d::ITransformation2d::ExactnessMode mode,
			double* errorFactorPtr) const
{
	CParallelogram* parallelogramPtr = dynamic_cast<CParallelogram*>(&result);
	if (parallelogramPtr != NULL){
		return parallelogramPtr->Transform(transformation, mode, errorFactorPtr);
	}

	return false;
}


bool CParallelogram::GetInvTransformed(
			const i2d::ITransformation2d& transformation,
			i2d::IObject2d& result,
			i2d::ITransformation2d::ExactnessMode mode,
			double* errorFactorPtr) const
{
	CParallelogram* parallelogramPtr = dynamic_cast<CParallelogram*>(&result);
	if (parallelogramPtr != NULL){
		return parallelogramPtr->InvTransform(transformation, mode, errorFactorPtr);
	}

	return false;
}


// reimplemented (iser::ISerializable)

bool CParallelogram::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag transformTag("Transform", "Transformation used in parallelogram");

	istd::CChangeNotifier notifier(archive.IsStoring()? NULL: this, CF_OBJECT_POSITION | istd::IChangeable::CF_MODEL);

	bool retVal = true;

	retVal = retVal && archive.BeginTag(transformTag);
	retVal = retVal && m_transform.Serialize(archive);
	retVal = retVal && archive.EndTag(transformTag);

	return retVal;
}


} // namespace i2d

