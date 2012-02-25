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


#include "ifpf/CHotfolderProcessingItem.h"


// ACF includes
#include "istd/TChangeNotifier.h"
#include "istd/CStaticServicesProvider.h"

#include "isys/ISystemEnvironment.h"

#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"

#include "iproc/IProcessor.h"


namespace ifpf
{


CHotfolderProcessingItem::CHotfolderProcessingItem()
	:m_processingState(iproc::IProcessor::TS_NONE),
	m_processingTime(0.0)
{
	GetItemUuid();
}


// reimplemented ()ifpf::CHotfolderProcessingItem

std::string CHotfolderProcessingItem::GetItemUuid() const
{
	if (m_itemId.empty()){
		isys::ISystemEnvironment* systemEnvironmentPtr = istd::GetService<isys::ISystemEnvironment>();
		I_ASSERT(systemEnvironmentPtr != NULL);
		if (systemEnvironmentPtr != NULL){
			m_itemId = systemEnvironmentPtr->GetUniqueIdentifier().toStdString();
		}
	}

	return m_itemId;
}


int CHotfolderProcessingItem::GetProcessingState() const
{
	return m_processingState;
}


void CHotfolderProcessingItem::SetProcessingState(int processingState)
{
	if (m_processingState != processingState){
		istd::CChangeNotifier changePtr(this, CF_STATE_CHANGED, this);

		m_processingState = processingState;
	}
}


QString CHotfolderProcessingItem::GetInputFile() const
{
	return m_inputFile;
}


void CHotfolderProcessingItem::SetInputFile(const QString& inputFile)
{
	if (m_inputFile != inputFile){
		istd::CChangeNotifier changePtr(this);

		m_inputFile = inputFile;
	}
}


QString CHotfolderProcessingItem::GetOutputFile() const
{
	return m_outputFile;
}


void CHotfolderProcessingItem::SetOutputFile(const QString& outputFile)
{
	if (m_outputFile != outputFile){
		istd::CChangeNotifier changePtr(this);

		m_outputFile = outputFile;
	}
}


double CHotfolderProcessingItem::GetProcessingTime() const
{
	return m_processingTime;
}


void CHotfolderProcessingItem::SetProcessingTime(double processingTime)
{
	if (m_processingTime != processingTime){
		istd::CChangeNotifier changePtr(this);

		m_processingTime = processingTime;
	}
}


const isys::IDateTime& CHotfolderProcessingItem::GetStartTime() const
{
	return m_startTime;
}


void CHotfolderProcessingItem::SetStartTime(const isys::IDateTime& startTime)
{
	if (m_startTime != startTime){
		istd::CChangeNotifier changePtr(this);

		m_startTime = startTime;
	}
}


// reimplemented (iser::ISerializable)

bool CHotfolderProcessingItem::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	static iser::CArchiveTag itemIdTag("Uuid", "Processing item identifier");
	retVal = retVal && archive.BeginTag(itemIdTag);
	retVal = retVal && archive.Process(m_itemId);
	retVal = retVal && archive.EndTag(itemIdTag);

	static iser::CArchiveTag processingStateTag("ProcessingState", "Current processing state");
	retVal = retVal && archive.BeginTag(processingStateTag);
	retVal = retVal && archive.Process(m_processingState);
	retVal = retVal && archive.EndTag(processingStateTag);

	static iser::CArchiveTag inputFileTag("InputFilePath", "Input file path");
	retVal = retVal && archive.BeginTag(inputFileTag);
	retVal = retVal && archive.Process(m_inputFile);
	retVal = retVal && archive.EndTag(inputFileTag);

	static iser::CArchiveTag outputFileTag("OutputFilePath", "Output file path");
	retVal = retVal && archive.BeginTag(outputFileTag);
	retVal = retVal && archive.Process(m_outputFile);
	retVal = retVal && archive.EndTag(outputFileTag);

	static iser::CArchiveTag processingTimeTag("ProcessingTime", "Processing time");
	retVal = retVal && archive.BeginTag(processingTimeTag);
	retVal = retVal && archive.Process(m_processingTime);
	retVal = retVal && archive.EndTag(processingTimeTag);

	static iser::CArchiveTag startTimeTag("StartTime", "Start time of the processing");
	retVal = retVal && archive.BeginTag(startTimeTag);
	retVal = retVal && m_startTime.Serialize(archive);
	retVal = retVal && archive.EndTag(startTimeTag);

	return retVal;
}


} // namespace ifpf


