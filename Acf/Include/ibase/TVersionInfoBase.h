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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef ibase_TVersionInfoBase_included
#define ibase_TVersionInfoBase_included


// ACF includes
#include "iser/IVersionInfo.h"
#include "ilog/TLoggerCompWrap.h"
#include "istd/AcfVersion.h"


namespace ibase
{


template <class BaseComponent>
class TVersionInfoBase: public BaseComponent, virtual public iser::IVersionInfo
{
public:
	typedef BaseComponent BaseClass;

	I_BEGIN_BASE_COMPONENT(TVersionInfoBase);
		I_REGISTER_INTERFACE(iser::IVersionInfo);
		I_ASSIGN(m_slaveVersionInfoCompPtr, "SlaveVersionInfo", "Slave version info, unknown version information requests will be delegated here", false, "SlaveVersionInfo");
	I_END_COMPONENT;

	// reimplemented (iser::IVersionInfo)
	virtual bool GetVersionNumber(int versionId, quint32& result) const;
	virtual QString GetVersionIdDescription(int versionId) const;
	virtual VersionIds GetVersionIds() const;
	virtual QString GetEncodedVersionName(int versionId, quint32 versionNumber) const;

private:
	I_REF(iser::IVersionInfo, m_slaveVersionInfoCompPtr);
};


// public methods

// reimplemented (iser::IVersionInfo)

template <class BaseComponent>
bool TVersionInfoBase<BaseComponent>::GetVersionNumber(int versionId, quint32& result) const
{
	if (m_slaveVersionInfoCompPtr.IsValid()){
		return m_slaveVersionInfoCompPtr->GetVersionNumber(versionId, result);
	}
	else if (versionId == iser::IVersionInfo::AcfVersionId){
		result = istd::RS_USE_VERSION;

		return true;
	}

	result = 0xffffffff;

	return false;
}


template <class BaseComponent>
QString TVersionInfoBase<BaseComponent>::GetVersionIdDescription(int versionId) const
{
	if (m_slaveVersionInfoCompPtr.IsValid()){
		return m_slaveVersionInfoCompPtr->GetVersionIdDescription(versionId);
	}

	return "";
}


template <class BaseComponent>
iser::IVersionInfo::VersionIds TVersionInfoBase<BaseComponent>::GetVersionIds() const
{
	VersionIds retVal;
	if (m_slaveVersionInfoCompPtr.IsValid()){
		retVal = m_slaveVersionInfoCompPtr->GetVersionIds();
	}

	return retVal;
}


template <class BaseComponent>
QString TVersionInfoBase<BaseComponent>::GetEncodedVersionName(int versionId, quint32 versionNumber) const
{
	QString retVal;

	if (m_slaveVersionInfoCompPtr.IsValid()){
		retVal = m_slaveVersionInfoCompPtr->GetEncodedVersionName(versionId, versionNumber);
	}
	else{
		retVal = QString("<") + QString("%1").arg(versionNumber) + ">";
	}

	return retVal;
}


// Standard definitions
typedef TVersionInfoBase<icomp::CComponentBase> CVersionInfoCompBase;
typedef TVersionInfoBase<ilog::CLoggerComponentBase> CVersionInfoLoggerCompBase;


} // namespace ibase


#endif // !ibase_TVersionInfoBase_included


