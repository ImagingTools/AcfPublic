/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#include "iimg/CReflectedBitmapBase.h"


// ACF includes
#include "istd/CChangeNotifier.h"


namespace iimg
{


const istd::IChangeable::ChangeSet s_blockConvChangeSet(CReflectedBitmapBase::CF_BLOCK_BITMAP_CONVERSION);


// reimplemented (iimg::IQImageProvider)

const QImage& CReflectedBitmapBase::GetQImage() const
{
	EnsureCacheValid();

	return m_image;
}


bool CReflectedBitmapBase::CopyImageFrom(const QImage& image)
{
	istd::CChangeNotifier notifier(this, &s_blockConvChangeSet);
	Q_UNUSED(notifier);

	if (ConvertFromQImage(image)){
		m_image = image;

		SetCacheValid();

		return true;
	}

	return false;
}


// protected methods

// reimplmented (istd::TCachedUpdateManagerWrap)

bool CReflectedBitmapBase::CalculateCache(const ChangeSet& changeSet)
{
	if (!changeSet.Contains(CF_BLOCK_BITMAP_CONVERSION)){
		return ConvertToQImage(m_image);
	}

	return true;
}


} // namespace iimg


