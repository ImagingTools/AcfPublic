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


#ifndef iqt_CBitmap_included
#define iqt_CBitmap_included


#include "istd/TOptDelPtr.h"

#include "iimg/CBitmapBase.h"

#include "ibase/IObjectSnap.h"

#include "iqt/IQImageProvider.h"


namespace iqt
{


/**
	Bitmap implementation based on Qt QImage.
*/
class CBitmap: public iimg::CBitmapBase, virtual public IQImageProvider, virtual public ibase::IObjectSnap
{
public:
	typedef iimg::CBitmapBase BaseClass;

	CBitmap();
	CBitmap(const CBitmap& bitmap);

	QImage& GetQImageRef();

	// reimplemented (iqt::IQImageProvider)
	virtual const QImage& GetQImage() const;
	virtual bool CopyImageFrom(const QImage& image);

	// reimplemented (ibase::IObjectSnap)
	virtual bool GetSnap(
				const istd::IChangeable& data,
				iimg::IBitmap& objectSnap,
				const istd::CIndex2d& size) const;

	// reimplemented (iimg::IBitmap)
	virtual PixelFormat GetPixelFormat() const;
	virtual bool CreateBitmap(PixelFormat pixelFormat, const istd::CIndex2d& size);
	virtual bool CreateBitmap(PixelFormat pixelFormat, const istd::CIndex2d& size, void* dataPtr, bool releaseFlag, int linesDifference = 0);
	virtual int GetLinesDifference() const;
	virtual int GetPixelBitsCount() const;
	virtual const void* GetLinePtr(int positionY) const;
	virtual void* GetLinePtr(int positionY);

	// reimplemented (iimg::IRasterImage)
	virtual void ResetImage();
	virtual istd::CIndex2d GetImageSize() const;
	virtual int GetComponentsCount() const;

	// reimplemented (istd::IChangeable)
	virtual int GetSupportedOperations() const;
	virtual bool CopyFrom(const istd::IChangeable& object);
	virtual istd::IChangeable* CloneMe() const;

protected:
	QImage::Format CalcQtFormat(PixelFormat pixelFormat) const;
	PixelFormat CalcFromQtFormat(QImage::Format imageFormat) const;
	bool SetQImage(const QImage& image);

private:
	istd::TOptDelPtr<I_BYTE, true> m_externalBuffer;
	QImage m_image;
};


// inline methods

inline QImage& CBitmap::GetQImageRef()
{
	return m_image;
}


} // namespace iqt


#endif //!iqt_CBitmap_included


