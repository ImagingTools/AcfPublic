/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
**
********************************************************************************/


#ifndef iipr_TLocalNeighborhood_included
#define iipr_TLocalNeighborhood_included


namespace iipr
{


/**
	Implementation of local neighborhood in a bitmap.
	Instance of this object is initialized with the some position in a bitmap (represented as a bitmap iterator) 
	and some kernel.
	Begin() and End() functions returns the boundary iterator for moving through the local neighborhood 
	and accessing to the pixel values.
*/
template <class BitmapIterator, class Kernel> 
class TLocalNeighborhood
{
public:
	typedef typename BitmapIterator::ValueType PixelValue;

	class Iterator
	{
	public:
		typedef typename TLocalNeighborhood::PixelValue PixelValue;
		typedef typename Kernel::Iterator KernelIterator;

		Iterator(const PixelValue* imageBufferPtr, const KernelIterator& kernelIterator);

		const PixelValue& operator*() const;
		Iterator& operator++();
		Iterator operator++(int);

	private:
		const PixelValue* m_imageBufferPtr;
		KernelIterator m_kernelIterator;
	};

	TLocalNeighborhood(const BitmapIterator& bitmapIterator, const Kernel& kernel);

	Iterator Begin() const;
	Iterator End() const;

private:
	BitmapIterator m_bitmapIterator;
	const Kernel& m_kernel;
};


template <class BitmapIterator, class Kernel> 
TLocalNeighborhood<BitmapIterator, Kernel>::TLocalNeighborhood(const BitmapIterator& bitmapIterator, const Kernel& kernel)
:	m_bitmapIterator(bitmapIterator),
	m_kernel(kernel)
{
}


template <class BitmapIterator, class Kernel> 
typename TLocalNeighborhood<BitmapIterator, Kernel>::Iterator TLocalNeighborhood<BitmapIterator, Kernel>::Begin() const
{
	return Iterator((*m_bitmapIterator).GetPixelBuffer(), m_kernel.Begin());
}


template <class BitmapIterator, class Kernel> 
typename TLocalNeighborhood<BitmapIterator, Kernel>::Iterator TLocalNeighborhood<BitmapIterator, Kernel>::End() const
{
	return Iterator((*m_bitmapIterator).GetPixelBuffer(), m_kernel.End());
}


// public methods of embedded class Iterator

template <class BitmapIterator, class Kernel> 
TLocalNeighborhood<BitmapIterator, Kernel>::Iterator::Iterator(const PixelValue* imageBufferPtr, const KernelIterator& kernelIterator)
:	m_kernelIterator(kernelIterator),
	m_imageBufferPtr(imageBufferPtr)
{
}


template <class BitmapIterator, class Kernel> 
inline const typename TLocalNeighborhood<BitmapIterator, Kernel>::Iterator::PixelValue& TLocalNeighborhood<BitmapIterator, Kernel>::Iterator::operator*() const
{
	int offset = (*m_kernelIterator).first;

	return *(m_imageBufferPtr + offset);
}


template <class BitmapIterator, class Kernel> 
inline typename TLocalNeighborhood<BitmapIterator, Kernel>::Iterator& TLocalNeighborhood<BitmapIterator, Kernel>::Iterator::operator++()
{
	++m_kernelIterator;

	return *this;
}


template <class BitmapIterator, class Kernel> 
inline typename TLocalNeighborhood<BitmapIterator, Kernel>::Iterator TLocalNeighborhood<BitmapIterator, Kernel>::Iterator::operator++(int)
{
	Iterator temp(*this);

	++m_kernelIterator;

	return temp;
}


} // namespace iipr


#endif // !iipr_TLocalNeighborhood_included

