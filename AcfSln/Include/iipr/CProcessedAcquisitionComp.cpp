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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iipr/CProcessedAcquisitionComp.h"

#include "istd/TChangeNotifier.h"

#include "iimg/CGeneralBitmap.h"


namespace iipr
{


// reimplemented (iproc::IBitmapAcquisition)

istd::CIndex2d CProcessedAcquisitionComp::GetBitmapSize(const iprm::IParamsSet* paramsPtr) const
{
	if (m_slaveAcquisitionCompPtr.IsValid()){
		return m_slaveAcquisitionCompPtr->GetBitmapSize(paramsPtr);
	}

	return istd::CIndex2d();
}


// reimplemented iproc::TSyncProcessorWrap<iproc::IBitmapAcquisition>

int CProcessedAcquisitionComp::DoProcessing(
			const iprm::IParamsSet* paramsPtr,
			const istd::IPolymorphic* inputPtr,
			istd::IChangeable* outputPtr,
			iproc::IProgressManager* /*progressManagerPtr*/)
{
	if (outputPtr == NULL){
		return TS_OK;
	}

	istd::TChangeNotifier<iimg::IBitmap> outputBitmapPtr(dynamic_cast<iimg::IBitmap*>(outputPtr));

	if (!outputBitmapPtr.IsValid() || !m_slaveAcquisitionCompPtr.IsValid()){
		return TS_INVALID;
	}

	int retVal = TS_INVALID;

	retVal = m_slaveAcquisitionCompPtr->DoProcessing(paramsPtr, inputPtr, outputBitmapPtr.GetPtr());
	if (retVal == TS_OK){
		if (m_processorCompPtr.IsValid()){
			iimg::CGeneralBitmap bufferBitmap;
			retVal = m_processorCompPtr->DoProcessing(paramsPtr, outputBitmapPtr.GetPtr(), &bufferBitmap);
			if (retVal == TS_OK){
				if (!outputBitmapPtr->CopyFrom(bufferBitmap)){
					retVal = TS_INVALID;
				}
			}
		}
	}

	return retVal;
}


} // namespace iipr

