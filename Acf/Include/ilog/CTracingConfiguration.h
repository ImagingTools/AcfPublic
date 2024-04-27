/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#pragma once


// ACF includes
#include <icomp/CComponentBase.h>
#include <ilog/ITracingConfiguration.h>
#include <iser/ISerializable.h>


namespace ilog
{


class CTracingConfiguration:
			public icomp::CComponentBase,
			virtual public ilog::ITracingConfiguration,
			virtual public iser::ISerializable
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CTracingConfiguration);
		I_REGISTER_INTERFACE(ilog::ITracingConfiguration);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_ASSIGN(m_defaultTracingLevel, "DefaulTracingtLevel", "Default tracing level, -1 tracing off, 0 tracing all", true, -1);
	I_END_COMPONENT;

	CTracingConfiguration();

	// reimplemented (ilog::ITracingConfiguration)
	virtual int GetTracingLevel() const override;
	virtual void SetTracingLevel(int tracingLevel) override;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive) override;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(int, m_defaultTracingLevel);

	int m_tracingLevel;
};


} // namespace ilog

