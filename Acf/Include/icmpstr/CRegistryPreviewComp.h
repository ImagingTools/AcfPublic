/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef icmpstr_CRegistryPreviewComp_included
#define icmpstr_CRegistryPreviewComp_included


// Qt includes
#include <QProcess>
#include <QLabel>

#include "icomp/IComponentEnvironmentManager.h"
#include "icomp/CComponentBase.h"

#include "iprm/IFileNameParam.h"

#include "icmpstr/IRegistryPreview.h"


namespace icmpstr
{


class CRegistryPreviewComp:
			public QObject,
			public icomp::CComponentBase,
			public IRegistryPreview
{
	Q_OBJECT
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CRegistryPreviewComp);
		I_REGISTER_INTERFACE(icmpstr::IRegistryPreview);
		I_ASSIGN(m_versionInfoCompPtr, "VersionInfo", "Version info used to serialize temporary registry file", false, "VersionInfo");
		I_ASSIGN(m_commandFileNameCompPtr, "CommandFileName", "Parameter storing command file name", true, "CommandFileName");
		I_ASSIGN(m_envManagerCompPtr, "EnvironmentManager", "Registry loader used to retrive package configuration", false, "EnvironmentManager");
	I_END_COMPONENT;

	CRegistryPreviewComp();

	// reimplemented (icmpstr::IRegistryPreview)
	virtual bool StartRegistry(const icomp::IRegistry& registry);
	virtual bool IsRunning() const;
	virtual void AbortRegistry();

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

protected slots:
	void OnStateChanged(QProcess::ProcessState state);

private:
	QString m_tempFileName;
	QProcess m_process;

	bool m_isRunning;

	I_REF(iprm::IFileNameParam, m_commandFileNameCompPtr);
	I_REF(icomp::IComponentEnvironmentManager, m_envManagerCompPtr);
	I_REF(iser::IVersionInfo, m_versionInfoCompPtr);
};


} // namespace icmpstr


#endif // !icmpstr_CRegistryPreviewComp_included


