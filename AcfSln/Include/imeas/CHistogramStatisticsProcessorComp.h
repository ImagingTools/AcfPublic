/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef imeas_CHistogramStatisticsProcessorComp_included
#define imeas_CHistogramStatisticsProcessorComp_included


// ACF includes
#include <iproc/TSyncProcessorCompBase.h>

// ACF-Solutions includes
#include <imeas/IDataSequenceStatisticsProcessor.h>


namespace imeas
{


class IDataSequence;
class IDataSequenceStatistics;
class IDataStatistics;


/**	
	Implementation of a processor for the image histogram calculation.
*/
class CHistogramStatisticsProcessorComp: public iproc::TSyncProcessorCompBase<IDataSequenceStatisticsProcessor>
{
public:
	typedef iproc::TSyncProcessorCompBase<IDataSequenceStatisticsProcessor> BaseClass;
	
	I_BEGIN_COMPONENT(CHistogramStatisticsProcessorComp);
		I_REGISTER_INTERFACE(IDataSequenceStatisticsProcessor);
	I_END_COMPONENT;

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);

	// reimplemented (imeas::IDataSequenceStatisticsProcessor)
	virtual int CalculateDataStatistics(
				const imeas::IDataSequence& dataSequence,
				imeas::IDataSequenceStatistics& dataStatistics) const;

private:
	bool CalculateChannelStatistics(const imeas::IDataSequence& input, int inputIndex, imeas::IDataStatistics& dataStatistics) const;
};


} // namespace imeas


#endif // !imeas_CHistogramStatisticsProcessorComp_included

