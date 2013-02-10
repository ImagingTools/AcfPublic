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


#include "iipr/CConvolutionKernel2dComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"

#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"

// IACF includes
#include "iipr/iipr.h"


namespace iipr
{


// protected methods

// reimplemented (icomp::CComponentBase)

void CConvolutionKernel2dComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_kernelAttrPtr.IsValid() && m_kernelWidthAttrPtr.IsValid() && m_kernelHeightAttrPtr.IsValid()){
		int kernelSize = m_kernelAttrPtr.GetCount();
		int kernelWidth = *m_kernelWidthAttrPtr;
		int kernelHeight = *m_kernelHeightAttrPtr;

		if (kernelWidth * kernelHeight != kernelSize){
			qDebug("Given kernel dimensions do not match the kernel size");

			return;
		}

		BaseClass2::SetKernelSize(istd::CIndex2d(kernelWidth, kernelHeight));

		for (int y = 0; y < kernelHeight; y++){
			for (int x = 0; x < kernelWidth; x++){

				int kernelIndex = x + y * kernelWidth;

				double kernelValue = m_kernelAttrPtr[kernelIndex];

				BaseClass2::SetKernelElement(istd::CIndex2d(x, y), kernelValue);			
			}		
		}
	}
}


} // namespace iipr


