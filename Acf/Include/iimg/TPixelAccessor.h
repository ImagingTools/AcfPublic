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


#ifndef iimg_TPixelAccessor_included
#define iimg_TPixelAccessor_included


namespace iimg
{

/**
	Access to the pixel data of an image.
*/
template <typename PixelType>
class TPixelAccessor
{
public:
	typedef typename PixelType ValueType;

	TPixelAccessor(int componentsCount);

	void SetPixelBuffer(ValueType* imageBufferPtr);
	ValueType* GetPixelBuffer();
	const ValueType* GetPixelBuffer() const;
	int GetComponentsCount() const;
	const ValueType& operator[](int index) const;
	ValueType& operator[](int index);

private:
	PixelType* m_imageBufferPtr;

	int m_componentsCount;
};


// public methods

template <typename PixelType>
TPixelAccessor<PixelType>::TPixelAccessor(int componentsCount)
	:m_imageBufferPtr(NULL),
	m_componentsCount(componentsCount)
{
}


template <typename PixelType>
inline void TPixelAccessor<PixelType>::SetPixelBuffer(ValueType* imageBufferPtr)
{
	m_imageBufferPtr = imageBufferPtr;
}


template <typename PixelType>
inline typename TPixelAccessor<PixelType>::ValueType* TPixelAccessor<PixelType>::GetPixelBuffer()
{
	return m_imageBufferPtr;
}


template <typename PixelType>
inline const typename TPixelAccessor<PixelType>::ValueType* TPixelAccessor<PixelType>::GetPixelBuffer() const
{
	return m_imageBufferPtr;
}


template <typename PixelType>
inline int TPixelAccessor<PixelType>::GetComponentsCount() const
{
	return m_componentsCount;
}


template <typename PixelType>
inline const typename TPixelAccessor<PixelType>::ValueType& TPixelAccessor<PixelType>::operator[](int index) const
{
	return *(m_imageBufferPtr + index);
}


template <typename PixelType>
inline typename TPixelAccessor<PixelType>::ValueType& TPixelAccessor<PixelType>::operator[](int index)
{
	return *(m_imageBufferPtr + index);
}


} // namespace iimg


#endif // !iimg_TPixelAccessor_included

