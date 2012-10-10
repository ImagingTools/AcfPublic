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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iimg_CGeneralBitmap_included
#define iimg_CGeneralBitmap_included


#include "istd/TOptDelPtr.h"

#include "iimg/CBitmapBase.h"


namespace iimg
{


/**
	Standard device- and platform-independent bitmap definition.
*/
class CGeneralBitmap: public CBitmapBase
{
public:
	CGeneralBitmap();

	// reimplemented (iimg::IBitmap)
	virtual bool IsFormatSupported(PixelFormat pixelFormat) const;
	virtual PixelFormat GetPixelFormat() const;
	virtual bool CreateBitmap(PixelFormat pixelFormat, const istd::CIndex2d& size);
	virtual bool CreateBitmap(PixelFormat pixelFormat, const istd::CIndex2d& size, void* dataPtr, bool releaseFlag, int linesDifference = 0);
	virtual int GetLinesDifference() const;
	virtual int GetPixelsDifference() const;
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
	/**
		Create bitmap with specified size, number of bits per pixel and components number per pixel.
		\param	size			bitmap size.
		\param	pixelBitsCount	number of bits per single pixel.
		\param	componentsCount	number of components per single pixel.
		\return					true if bitmap was created.
	*/
	virtual bool CreateBitmap(
				const istd::CIndex2d& size,
				int pixelBitsCount,
				int componentsCount,
				PixelFormat pixelFormat);

	/**
		Create bitmap using external image buffer.
		\param	size			bitmap size.
		\param	dataPtr			pointer to external image buffer.
		\param	releaseFlag		if its true, external buffer will be managed (removed) by this object.
		\param	linesDifference	address difference between next and previos line. If it equals 0, the value will be taken from size and number of bits per pixel.
		\param	pixelBitsCount	number of bits per single pixel.
		\param	componentsCount	number of components per single pixel.
		\return					true if bitmap was created.
	*/
	virtual bool CreateBitmap(
				const istd::CIndex2d& size,
				void* dataPtr,
				bool releaseFlag,
				int linesDifference,
				int pixelBitsCount,
				int componentsCount,
				PixelFormat pixelFormat);

private:
	istd::TOptDelPtr<quint8, true> m_buffer;

	istd::CIndex2d m_size;
	int m_linesDifference;
	int m_pixelBitsCount;
	int m_componentsCount;
	PixelFormat m_pixelFormat;
};


} // namespace iimg


#endif // !iimg_CGeneralBitmap_included


