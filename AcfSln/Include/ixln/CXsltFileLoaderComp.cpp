#include "ixln/CXsltFileLoaderComp.h"


// Xerces includes
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/framework/LocalFileInputSource.hpp>

#include <xalanc/Include/XalanAutoPtr.hpp>
#include <xalanc/XalanDOM/XalanDocument.hpp>
#include <xalanc/XalanDOM/XalanElement.hpp>
#include <xalanc/PlatformSupport/XalanOutputStreamPrintWriter.hpp>
#include <xalanc/PlatformSupport/XalanStdOutputStream.hpp>
#include <xalanc/XMLSupport/FormatterToXML.hpp>
#include <xalanc/XercesParserLiaison/XercesDOMFormatterWalker.hpp>
#include <xalanc/XalanTransformer/XalanTransformer.hpp>


// ACF includes
#include "istd/TChangeNotifier.h"
#include "istd/CStaticServicesProvider.h"
#include "isys/IFileSystem.h"
#include "isys/ISystemEnvironment.h"


XALAN_USING_XERCES(DOMDocument)
XALAN_USING_XALAN(XalanCompiledStylesheet)
XALAN_USING_XALAN(XalanParsedSource)
XALAN_USING_XALAN(XalanTransformer)


class XercesRuntime
{
public:
	XercesRuntime()
	{
		XALAN_USING_XERCES(XMLPlatformUtils)
		XALAN_USING_XALAN(XalanTransformer)

		XMLPlatformUtils::Initialize();
		XalanTransformer::initialize();
	}


	~XercesRuntime()
	{
		XALAN_USING_XERCES(XMLPlatformUtils)
		XALAN_USING_XALAN(XalanTransformer)
		
		XalanTransformer::terminate();
		XMLPlatformUtils::Terminate();
		XalanTransformer::ICUCleanUp();		
	}
};


namespace ixln
{


// public methods

// reimplemented (iser::IFileLoader)

bool CXsltFileLoaderComp::IsOperationSupported(
			const istd::IChangeable* dataObjectPtr,
			const istd::CString* filePathPtr,
			int flags,
			bool beQuiet) const
{
	if ((dataObjectPtr != NULL) && (dynamic_cast<const iser::ISerializable*>(dataObjectPtr) == NULL)){
		if (!beQuiet){
			SendInfoMessage(MI_BAD_OBJECT_TYPE, "Object is not serializable");
		}

		return false;
	}

	if ((flags & QF_NO_LOADING) != 0){
		if (!beQuiet){
			SendCriticalMessage(MI_CANNOT_SAVE, "Save operation is not implemented");
		}

		return false;
	}

	if ((flags & (QF_ANONYMOUS_ONLY | QF_DIRECTORY_ONLY)) != 0){
		return false;
	}

	if (filePathPtr != NULL){
		if ((flags & QF_NO_SAVING) != 0){
			isys::IFileSystem* fileSystemPtr = istd::GetService<isys::IFileSystem>();
			if (fileSystemPtr != NULL){
				if (!fileSystemPtr->IsPresent(*filePathPtr)){
					return false;
				}
			}
		}

		istd::CStringList fileExtensions;
		if (GetFileExtensions(fileExtensions)){
			int extensionsCount = fileExtensions.size();
			for (int i = 0; i < extensionsCount; ++i){
				const istd::CString& extension = fileExtensions[i];
				if (filePathPtr->substr(filePathPtr->length() - extension.length() - 1) == istd::CString(".") + extension.ToLower()){
					return true;
				}
			}

			if (!beQuiet){
				SendInfoMessage(MI_BAD_EXTENSION, "File extension is not supported");
			}

			return false;
		}
	}

	return true;
}


int CXsltFileLoaderComp::LoadFromFile(istd::IChangeable& data, const istd::CString& filePath) const
{
	if (!IsOperationSupported(&data, &filePath, QF_NO_SAVING, false)){
		return StateFailed;
	}

	istd::CString transformFileName;
	if (m_transformFileNameParamCompPtr.IsValid()){
		transformFileName = m_transformFileNameParamCompPtr->GetPath();
	}

	if (transformFileName.IsEmpty()){
		SendInfoMessage(MI_BAD_TRANSFORMATION, "No transformation file");

		return StateFailed;
	}

	isys::ISystemEnvironment* systemEnvironmentPtr = istd::GetService<isys::ISystemEnvironment> ();
	if (systemEnvironmentPtr == NULL){
		SendInfoMessage(MI_INTERNAL, "Temporary file could not be created");

		return StateFailed;
	}

	istd::CString tempFileName = systemEnvironmentPtr->GetTempDirPath() + "/" + systemEnvironmentPtr->GetUniqueIdentifier() + ".tcvx";
	
	int retVal = 0;
	
	try{
		XercesRuntime runtime;

		istd::TDelPtr<XalanTransformer> transformerPtr(new XalanTransformer);

		retVal = transformerPtr->transform(filePath.ToString().c_str(), transformFileName.ToString().c_str(), tempFileName.ToString().c_str());

		if (retVal != 0){
			SendInfoMessage(MI_INTERNAL, "Transformation failed");

			return StateFailed;
		}

		retVal = m_standardFileLoaderCompPtr->LoadFromFile(data, tempFileName.ToString().c_str());

		isys::IFileSystem* fileSystemPtr = istd::GetService<isys::IFileSystem>();
		if (fileSystemPtr == NULL){
			SendInfoMessage(MI_INTERNAL, "Temporary file could not be deleted");

			return StateFailed;
		}

		fileSystemPtr->RemoveFile(tempFileName);

		transformerPtr.Reset();
	}
	catch(...){
		BaseClass::SendLogMessage(istd::ILogger::MC_ERROR, 0, "An unknown error occurred!", "Xalan Transformation");
		
		return StateFailed;
	}

	return retVal;
}


int CXsltFileLoaderComp::SaveToFile(const istd::IChangeable& data, const istd::CString& filePath) const
{
	istd::CString newfilePath = istd::CString(filePath.substr(0, filePath.size()-4)) + ".tcvx";
	
	m_standardFileLoaderCompPtr->SaveToFile(data, newfilePath);

	return StateFailed;
}

} // namespace ixln


