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


#ifndef ifpf_CHotfolderLoaderComp_included
#define ifpf_CHotfolderLoaderComp_included


// ACF includes
#include "iser/CXmlFileReadArchive.h"
#include "iser/CXmlFileWriteArchive.h"

#include "ibase/TFileSerializerComp.h"


namespace ifpf
{


/**
	Hotfolder data loader.
	This implementation supports persistence of the static and dynamic model of the hotfolder.
*/
class CHotfolderLoaderComp: public ibase::TFileSerializerComp<iser::CXmlFileReadArchive, iser::CXmlFileWriteArchive>
{
public:
	typedef ibase::TFileSerializerComp<iser::CXmlFileReadArchive, iser::CXmlFileWriteArchive> BaseClass;

	I_BEGIN_COMPONENT(CHotfolderLoaderComp);
		I_ASSIGN(m_monitorSessionsParamIdAttrPtr, "MonitorSessionsParamId", "Parameter ID for monitoring sessions", false, "MonitoringSessions");
	I_END_COMPONENT;

	enum MessageId
	{
		MI_LOAD_ERROR = 680,
		MI_CANNOT_READ_STATIC_PARAMS,
		MI_CANNOT_READ_DYNAMIC_PARAMS
	};

	// reimplemented (iser::IFileLoader)
	virtual int LoadFromFile(istd::IChangeable& data, const istd::CString& filePath) const;
	virtual int SaveToFile(const istd::IChangeable& data, const istd::CString& filePath) const;

	// reimplemented (iser::IFileTypeInfo)
	virtual bool GetFileExtensions(istd::CStringList& result, int flags = 0, bool doAppend = false) const;
	virtual istd::CString GetTypeDescription(const istd::CString* extensionPtr = NULL) const;

protected:
	/**
		Get the path of the static hotfolder parameter file.
	*/
	istd::CString GetStaticParamsPath(const istd::CString& objectPath) const;

	// reimplemented (ibase::TFileSerializerComp)
	virtual void OnReadError(
				const iser::CXmlFileReadArchive& archive,
				const istd::IChangeable& data,
				const istd::CString& filePath) const;

private:
	I_ATTR(istd::CString, m_monitorSessionsParamIdAttrPtr);
};


} // namespace ifpf


#endif // !ifpf_CHotfolderLoaderComp_included


