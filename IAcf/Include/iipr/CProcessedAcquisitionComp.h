/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#ifndef iipr_CProcessedAcquisitionComp_included
#define iipr_CProcessedAcquisitionComp_included


#include "iproc/TSyncProcessorCompBase.h"

#include "iproc/IBitmapAcquisition.h"


namespace iipr
{


class CProcessedAcquisitionComp: public iproc::TSyncProcessorCompBase<iproc::IBitmapAcquisition>
{
public:
	typedef iproc::TSyncProcessorCompBase<iproc::IBitmapAcquisition> BaseClass;

	I_BEGIN_COMPONENT(CProcessedAcquisitionComp);
		I_ASSIGN(m_slaveAcquisitionCompPtr, "SlaveCamera", "Camera for real image acquisition", true, "SlaveCamera");
		I_ASSIGN(m_processorCompPtr, "ImageProcessor", "Image processor", false, "ImageProcessor");
	I_END_COMPONENT;

	// reimplemented (iproc::IBitmapAcquisition)
	virtual istd::CIndex2d GetBitmapSize(const iprm::IParamsSet* paramsPtr) const;

	// reimplemented iproc::TSyncProcessorWrap<iproc::IBitmapAcquisition>
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				iproc::IProgressManager* progressManagerPtr = NULL);

private:
	I_REF(iproc::IBitmapAcquisition, m_slaveAcquisitionCompPtr);
	I_REF(iproc::IProcessor, m_processorCompPtr);
};


} // namespace iipr


#endif // !iipr_CProcessedAcquisitionComp_included


