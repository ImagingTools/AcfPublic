/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iipr/CMultiBitmapCacheComp.h"


// ACF includes
#include "istd/TDelPtr.h"


namespace iipr
{


CMultiBitmapCacheComp::CMultiBitmapCacheComp()
{
}


// reimplemented (iipr::IMultiBitmapProvider)

const iprm::ISelectionConstraints* CMultiBitmapCacheComp::GetBitmapSelectionContraints() const
{
	return NULL;
}


int CMultiBitmapCacheComp::GetBitmapsCount() const
{
	return m_bitmapsPtr.GetCount();
}


const iimg::IBitmap* CMultiBitmapCacheComp::GetBitmap(int bitmapIndex) const
{
	I_ASSERT(bitmapIndex >= 0);
	I_ASSERT(bitmapIndex < GetBitmapsCount());

	return m_bitmapsPtr.GetAt(bitmapIndex);
}


const i2d::ITransformation2d* CMultiBitmapCacheComp::GetLogTransform(int bitmapIndex) const
{
	I_ASSERT(bitmapIndex >= 0);
	I_ASSERT(bitmapIndex < GetBitmapsCount());
	I_ASSERT(m_bitmapsPtr.GetCount() == m_transformsPtr.GetCount());

	return m_transformsPtr.GetAt(bitmapIndex);
}


// reimplemented (istd::IChangeable)

bool CMultiBitmapCacheComp::CopyFrom(const IChangeable& object)
{
	const IMultiBitmapProvider* providerPtr = dynamic_cast<const IMultiBitmapProvider*>(&object);
	if (providerPtr != NULL){
		int bitmapsCount = providerPtr->GetBitmapsCount();

		m_bitmapsPtr.SetCount(bitmapsCount);
		m_transformsPtr.SetCount(bitmapsCount);

		for (int i = 0; i < bitmapsCount; ++i){
			istd::TDelPtr<iimg::IBitmap> clonedBitmapPtr;
			const iimg::IBitmap* bitmapPtr = providerPtr->GetBitmap(i);
			if (bitmapPtr != NULL){
				clonedBitmapPtr.SetCastedOrRemove(bitmapPtr->CloneMe());
			}
			m_bitmapsPtr.SetElementAt(i, clonedBitmapPtr.PopPtr());

			istd::TDelPtr<i2d::ITransformation2d> clonedTransformPtr;
			const i2d::ITransformation2d* transformPtr = providerPtr->GetLogTransform(i);
			if (transformPtr != NULL){
				clonedTransformPtr.SetCastedOrRemove(transformPtr->CloneMe());
			}
			m_transformsPtr.SetElementAt(i, clonedTransformPtr.PopPtr());
		}

		return true;
	}

	return false;
}


} // namespace iipr


