/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include <i3d/CAffine3d.h>


// ACF includes
#include <iser/IArchive.h>
#include <iser/CArchiveTag.h>


namespace i3d
{


// static constants
static const iser::CArchiveTag s_matrixTag("Matrix", "Transformation matrix", iser::CArchiveTag::TT_LEAF);
static const iser::CArchiveTag s_translationTag("Translation", "Translation vector", iser::CArchiveTag::TT_LEAF);


CAffine3d CAffine3d::GetInverse() const
{
	CAffine3d result;
	GetInverse(result);
	return result;
}


bool CAffine3d::GetInverse(CAffine3d& result) const
{
	CMatrix3d invMatrix;
	if (!m_matrix.GetInverted(invMatrix)){
		return false;
	}
	
	// (M, t)^-1 = (M^-1, -M^-1 * t)
	result.m_matrix = invMatrix;
	result.m_translation = invMatrix.GetMultiplied(-m_translation);
	
	return true;
}


bool CAffine3d::Serialize(iser::IArchive& archive)
{
	bool retVal = true;
	
	retVal = retVal && archive.BeginTag(s_matrixTag);
	// Serialize matrix elements
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			double value = m_matrix.GetAt(i, j);
			retVal = retVal && archive.Process(value);
			if (!archive.IsStoring()){
				m_matrix.SetAt(i, j, value);
			}
		}
	}
	retVal = retVal && archive.EndTag(s_matrixTag);
	
	retVal = retVal && archive.BeginTag(s_translationTag);
	retVal = retVal && m_translation.Serialize(archive);
	retVal = retVal && archive.EndTag(s_translationTag);
	
	return retVal;
}


} // namespace i3d
