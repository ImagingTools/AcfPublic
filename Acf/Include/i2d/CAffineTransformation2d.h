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


#ifndef i2d_CAffineTransformation2d_included
#define i2d_CAffineTransformation2d_included


// ACF includes
#include "i2d/ITransformation2d.h"
#include "i2d/CAffine2d.h"


namespace i2d
{


/**
	Affine transformation for 2D spaces.
*/
class CAffineTransformation2d:
			virtual public CAffine2d,
			virtual public ITransformation2d
{
public:
	typedef CAffine2d BaseClass;

	// reimplemented (i2d::ITransformation2d)
	virtual int GetTransformationFlags() const;
	virtual bool GetDistance(
				const CVector2d& origPos1,
				const CVector2d& origPos2,
				double& result,
				ExactnessMode mode = EM_NONE) const;
	virtual bool GetPositionAt(
				const CVector2d& origPosition,
				CVector2d& result,
				ExactnessMode mode = EM_NONE) const;
	virtual bool GetInvPositionAt(
				const CVector2d& transfPosition,
				CVector2d& result,
				ExactnessMode mode = EM_NONE) const;
	virtual bool GetLocalTransform(
				const CVector2d& origPosition,
				CAffine2d& result,
				ExactnessMode mode = EM_NONE) const;
	virtual bool GetLocalInvTransform(
				const CVector2d& transfPosition,
				CAffine2d& result,
				ExactnessMode mode = EM_NONE) const;
	virtual const ITransformation2d* CreateCombinedTransformation(const ITransformation2d& transform) const;

	// reimplemented (imath::TISurjectFunction)
	virtual bool GetInvValueAt(const CVector2d& argument, CVector2d& result) const;
	virtual CVector2d GetInvValueAt(const CVector2d& argument) const;

	// reimplemented (imath::TIMathFunction)
	virtual bool GetValueAt(const CVector2d& argument, CVector2d& result) const;
	virtual CVector2d GetValueAt(const CVector2d& argument) const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);
};


} // namespace i2d


#endif // !i2d_CAffineTransformation2d_included


