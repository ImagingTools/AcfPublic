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


#ifndef icbox_CMemoryBankSerializerComp_included
#define icbox_CMemoryBankSerializerComp_included


#include "iser/IVersionInfo.h"
#include "iser/IFileLoader.h"

#include "icomp/CComponentBase.h"

#include "ibase/TLoggerCompWrap.h"


namespace icbox
{


class CMemoryBankSerializerComp:
			public ibase::CLoggerComponentBase,
			virtual public iser::IFileLoader
{
public:
	typedef ibase::CLoggerComponentBase BaseClass;

	enum MessageId
	{
		MI_CBIOS_ERROR = 0xad20
	};

	I_BEGIN_COMPONENT(CMemoryBankSerializerComp);
		I_REGISTER_INTERFACE(iser::IFileLoader);

		I_ASSIGN(m_versionInfoCompPtr, "VersionInfo", "Provide information about archive versions", false, "VersionInfo");
		I_ASSIGN(m_memoryBankIdAttrPtr, "MemoryBank", "Memory bank of Crypto Box", true, 1);
		I_ASSIGN(m_partitionIdAttrPtr, "PartitionId", "Partition ID will be used", true, 999);
		I_ASSIGN(m_accessKeyAttrPtr, "AccessKey", "User or administrator key", false, "demo");
		I_ASSIGN(m_isAdminKeyAttrPtr, "IsAdminKey", "True, if access key is admin key", true, false);
	I_END_COMPONENT;

	CMemoryBankSerializerComp();

	// reimplemented (iser::IFileLoader)
	virtual bool IsOperationSupported(
				const istd::IChangeable* dataObjectPtr,
				const istd::CString* filePathPtr = NULL,
				int flags = 0,
				bool beQuiet = true) const;
	virtual int LoadFromFile(istd::IChangeable& data, const istd::CString& filePath = istd::CString()) const;
	virtual int SaveToFile(const istd::IChangeable& data, const istd::CString& filePath = istd::CString()) const;

	// reimplemented (iser::IFileTypeInfo)
	virtual bool GetFileExtensions(istd::CStringList& result, int flags = 0, bool doAppend = false) const;
	virtual istd::CString GetTypeDescription(const istd::CString* extensionPtr = NULL) const;

protected:
	bool CheckError(I_DWORD errorCode) const;
	bool EnsurePartitionOpened() const;
	bool EnsurePartitionClosed() const;
	bool ReadFromMem(int offset, void* bufferPtr, int size) const;
	bool WriteToMem(int offset, const void* bufferPtr, int size) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_REF(iser::IVersionInfo, m_versionInfoCompPtr);
	I_ATTR(int, m_memoryBankIdAttrPtr);
	I_ATTR(int, m_partitionIdAttrPtr);
	I_ATTR(istd::CString, m_accessKeyAttrPtr);
	I_ATTR(bool, m_isAdminKeyAttrPtr);

	bool m_isInitialized;
	mutable bool m_isOpened;
	mutable bool m_isLogged;
};


} // namespace icbox


#endif // !icbox_CMemoryBankSerializerComp_included


