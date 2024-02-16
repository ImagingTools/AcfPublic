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


#ifndef iimg_CBitmapBase_included
#define iimg_CBitmapBase_included


// ACF includes
#include <i2d/CObject2dBase.h>
#include <iimg/IBitmap.h>


namespace iimg
{


/**
	Base implementation of some \c iimg::IBitmap methods.

	\ingroup ImageProcessing
	\ingroup Geometry
*/
class CBitmapBase:
			public i2d::CObject2dBase,
			virtual public IBitmap
{
public:
	typedef i2d::CObject2dBase BaseClass;

	// reimplemented (i2d::IObject2d)
	virtual i2d::CVector2d GetCenter() const override;
	virtual void MoveCenterTo(const i2d::CVector2d& position) override;
	virtual i2d::CRectangle GetBoundingBox() const override;

	// reimplemented (iimg::IBitmap)
	virtual bool CreateImageFromRegion(const iimg::IBitmap& sourceBitmap, const i2d::CRect& region) override;
	virtual int GetLineBytesCount() const override;
	virtual int GetComponentBitsCount(int componentIndex = 0) const override;
	virtual int GetPixelBitsCount() const override;

	// reimplemented (iimg::IRasterImage)
	virtual bool IsEmpty() const override;
	virtual int GetComponentsCount() const override;
	virtual icmm::CVarColor GetColorAt(const istd::CIndex2d& position) const override;
	virtual bool SetColorAt(const istd::CIndex2d& position, const icmm::CVarColor& color) override;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive) override;

	// reimplemented (istd::IChangeable)
	virtual bool ResetData(CompatibilityMode mode = CM_WITHOUT_REFS) override;

protected:
	static int GetComponentsCount(IBitmap::PixelFormat format);
	static int GetComponentBitsCount(IBitmap::PixelFormat format, int componentIndex);
	static int GetPixelBitsCount(IBitmap::PixelFormat format);
};


} // namespace iimg


#endif // !iimg_CBitmapBase_included


