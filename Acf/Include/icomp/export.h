/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef icomp_export_included
#define icomp_export_included


#include "icomp/TComponentRegistrator.h"
#include "icomp/CPackageStaticInfo.h"

#include "istd/CStaticServicesProvider.h"


namespace icomp
{


#if defined _MSC_VER
	#define I_FUNCTION_EXPORT __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
#elif defined __GNUC__
	#define I_FUNCTION_EXPORT __attribute__ ((visibility("default")))
#else
	#define I_FUNCTION_EXPORT
#endif


#if defined(_DEBUG) || defined(DEBUG)
	#define I_PACKAGE_EXPORT_FUNCTION GetPackageInfoDebug
	#define I_PACKAGE_EXPORT_FUNCTION_NAME "GetPackageInfoDebug"
#else // _DEBUG || DEBUG
	#define I_PACKAGE_EXPORT_FUNCTION GetPackageInfo
	#define I_PACKAGE_EXPORT_FUNCTION_NAME "GetPackageInfo"
#endif // _DEBUG || DEBUG


#if defined(_DEBUG) || defined(DEBUG)
	#define I_EXPORT_SERVICES_FUNCTION RegisterServicesDebug
	#define I_EXPORT_SERVICES_FUNCTION_NAME "RegisterServicesDebug"
#else // _DEBUG || DEBUG
	#define I_EXPORT_SERVICES_FUNCTION RegisterServices
	#define I_EXPORT_SERVICES_FUNCTION_NAME "RegisterServices"
#endif // _DEBUG || DEBUG


#define I_EXPORT_SERVICES_PROVIDER(serviceProvider)\
	extern "C" I_FUNCTION_EXPORT void I_EXPORT_SERVICES_FUNCTION(const istd::IServicesProvider* parentPtr){\
		istd::CStaticServicesProvider::InitServices(parentPtr);\
		serviceProvider::RegisterServices();\
	}

#define I_EXPORT_DEFAULT_SERVICES\
	extern "C" I_FUNCTION_EXPORT void I_EXPORT_SERVICES_FUNCTION(const istd::IServicesProvider* parentPtr){\
		istd::CStaticServicesProvider::InitServices(parentPtr);\
	}


#define I_EXPORT_PACKAGE(logicalName, description, keywords) \
	static icomp::CPackageStaticInfo packageInfo(description, keywords);\
	extern "C" I_FUNCTION_EXPORT icomp::CPackageStaticInfo* I_PACKAGE_EXPORT_FUNCTION(){\
		return &packageInfo;\
	}

#define I_EXPORT_COMPONENT(component, description, keywords) \
	static icomp::TComponentRegistrator<component> component##_registrator(#component, packageInfo, description, keywords);\

typedef icomp::CPackageStaticInfo* (*GetPackageInfoFunc)();
typedef void (*RegisterServicesFunc)(const istd::IServicesProvider*);


#define I_DATA_PERSISTENCE "\"Data Persistence\""
#define I_DATA_PROCESSING "\"Data Processing\""
#define I_SERVICE "Service"
#define I_APPLICATION "Application"
#define I_APPLICATION_LOGIC "\"Application Logic\""
#define I_DATA_MODEL "\"Data Model\""
#define I_GUI "GUI"
#define I_DATA_VISUALIZATION "Visualization"
#define I_PACKAGE "Package"

// Macros used to simplify using of meta description
#define IM_CATEGORY(keywords) " Category='" keywords "' "
#define IM_TAG(keywords) " Tag='" keywords "' "
#define IM_COMPANY(keywords) " Company='" keywords "' "
#define IM_AUTHOR(keywords) " Author='" keywords "' "
#define IM_PROJECT(keywords) " Project='" keywords "' "


} // namespace icomp


#endif // !icomp_export_included


