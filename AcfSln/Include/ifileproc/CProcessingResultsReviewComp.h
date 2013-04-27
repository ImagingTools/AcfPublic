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


#ifndef ifileproc_CProcessingResultsReviewComp_included
#define ifileproc_CProcessingResultsReviewComp_included


// ACF includes
#include "ifile/IFileTypeInfo.h"
#include "ifile/IFileNameParam.h"
#include "ifile/IFilePersistence.h"
#include "ifileproc/IFileConvertCopy.h"
#include "ilog/TLoggerCompWrap.h"

// ACF-Solutions includes
#include "iproc/ISupplier.h"


namespace ifileproc
{

class CProcessingResultsReviewComp:
			public ilog::CLoggerComponentBase,
			virtual public ifileproc::IFileConvertCopy			
{
public:
	typedef ilog::CLoggerComponentBase BaseClass;

	I_BEGIN_COMPONENT(CProcessingResultsReviewComp);
		I_REGISTER_INTERFACE(ifileproc::IFileConvertCopy);
		I_ASSIGN(m_inputPathCompPtr, "InputPathObject", "Optional storage of current processed input (file or directory)", false, "InputPathObject");
		I_ASSIGN(m_currentProcessedFilePathCompPtr, "CurrentProcessedFilePath", "Full path to currently processed file, should be used by supplier as input file path", true, "ProcessingInputFilePath");
		I_ASSIGN(m_outputSupplierCompPtr, "OutputSupplier", "Supplier to process files", true, "OutputSupplier");
		I_ASSIGN_TO(m_outputSupplierSerializerCompPtr, m_outputSupplierCompPtr, true);
		I_ASSIGN(m_outputFileSerializerCompPtr, "OutputFileSerializer", "Output formatter", true, "OutputFileSerializer");
		I_ASSIGN(m_inputFileTypeInfoCompPtr, "InputFilesTypeInfo", "Optional input files type information used if user specified directory", false, "InputFilesTypeInfo");
	I_END_COMPONENT;

	// reimplemented (ifileproc::IFileConvertCopy)
	virtual bool ConvertFiles(				
				const QString& inputPath,
				const QString& outputPath,
				const iprm::IParamsSet* paramsPtr = NULL) const;

protected:
	/**
		Process single file and send the results to archive.
	*/
	virtual bool ProcessSingleFile(const QString& filePath, iser::IArchive& archive);

private:
	class ProcessSerializer: public iser::ISerializable
	{
	public:
		/**
			Initialize the serializer with parent object and path to be processed.
		*/
		ProcessSerializer(
					const CProcessingResultsReviewComp* parentPtr,
					const QString& path);

		// reimplemented (iser::ISerializable)
		virtual bool Serialize(iser::IArchive& archive);

	private:
		const CProcessingResultsReviewComp& m_parent;
		QString m_path;
	};

	I_REF(ifile::IFileNameParam, m_inputPathCompPtr);
	I_REF(ifile::IFileNameParam, m_currentProcessedFilePathCompPtr);
	I_REF(iproc::ISupplier, m_outputSupplierCompPtr);
	I_REF(iser::ISerializable, m_outputSupplierSerializerCompPtr);
	I_REF(ifile::IFilePersistence, m_outputFileSerializerCompPtr);
	I_REF(ifile::IFileTypeInfo, m_inputFileTypeInfoCompPtr);
};


} // namespace ifileproc


#endif // !ifileproc_CProcessingResultsReviewComp_included


