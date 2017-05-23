/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#pragma once


// ACF-Solutions includes
#include <iblob/CBlobProcessorCompBase.h>


namespace iocv
{


class COcvBlobProcessorComp: public iblob::CBlobProcessorCompBase
{
public:
	typedef iblob::CBlobProcessorCompBase BaseClass;

	I_BEGIN_COMPONENT(COcvBlobProcessorComp);
	I_ASSIGN(m_resultConsumerCompPtr, "ResultConsumer", "Consumer of result messages with geometrical layout", false, "ResultConsumer");
	I_ASSIGN(m_tempConsumerCompPtr, "TempConsumer", "Consumer of temporary result messages with geometrical layout", false, "TempConsumer");
	I_END_COMPONENT;

	enum MessageId
	{
		MI_FOUND_BLOB = 0x9354f0
	};

protected:
	// reimplemented (iblob::CBlobProcessorCompBase)
	virtual bool CalculateBlobs(
				const iprm::IParamsSet* paramsPtr,
				const iblob::IBlobFilterParams* filterParamsPtr,
				const i2d::IObject2d* aoiPtr,
				const iimg::IBitmap& image,
				iipr::IFeaturesConsumer& result);

private:
	I_REF(ilog::IMessageConsumer, m_resultConsumerCompPtr);
	I_REF(ilog::IMessageConsumer, m_tempConsumerCompPtr);
};


} // namespace iocv


