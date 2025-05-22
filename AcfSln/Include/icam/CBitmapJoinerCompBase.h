/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef icam_CBitmapJoinerCompBase_included
#define icam_CBitmapJoinerCompBase_included


// ACF includes
#include <ilog/TLoggerCompWrap.h>
#include <iimg/IBitmap.h>


namespace icam
{


/**
	Joins multiple bitmaps into single one.
	Supports grid layout.
*/
class CBitmapJoinerCompBase: public ilog::CLoggerComponentBase
{
public:
	typedef ilog::CLoggerComponentBase BaseClass;

	I_BEGIN_BASE_COMPONENT(CBitmapJoinerCompBase);
		I_ASSIGN(m_numberOfColumnsAttrPtr, "NumberOfColumns", "Number of columns (or, 1 = join vertically, 0 or less = horizontally)", true, 0);
		I_ASSIGN(m_bitmapFactoryPtr, "BitmapFactory", "Bitmap factory", true, "Bitmap");
	I_END_COMPONENT;

protected:
	bool PrepareSnapResult(int imageCount, istd::IChangeable* outputPtr);
	bool FinalizeSnapResult();
	const iimg::IBitmap* GetResultBitmap() const
	{
		return m_resultPtr;
	}

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

protected:
	struct ImageInfo 
	{
		ImageInfo()
		{
			isSnapOk = false;
		}

		bool isSnapOk;
		iimg::IBitmapSharedPtr bitmapPtr;
	};

	typedef QVector<ImageInfo> ImageList;
	ImageList m_snapList;

private:
	iimg::IBitmap* m_resultPtr;

	I_ATTR(int, m_numberOfColumnsAttrPtr);
	I_FACT(iimg::IBitmap, m_bitmapFactoryPtr);
};


} // namespace icam


#endif // !icam_CBitmapJoinerCompBase_included
