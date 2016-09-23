/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqtdoc_CDoxygenHelpFileProviderComp_included
#define iqtdoc_CDoxygenHelpFileProviderComp_included


#include <icomp/CComponentBase.h>

#include <idoc/IHelpFileProvider.h>

#include <iqtdoc/iqtdoc.h>


namespace iqtdoc
{


class CDoxygenHelpFileProviderComp:
			public icomp::CComponentBase,
			virtual public idoc::IHelpFileProvider
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CDoxygenHelpFileProviderComp);
		I_REGISTER_INTERFACE(idoc::IHelpFileProvider);
		I_ASSIGN(m_doxygenDirectoryAttrPtr, "DoxygenDirectory", "Specify the directory where doxygen directory can be find", true, "./Doxygen");
		I_ASSIGN(m_slaveProvider, "SlaveProvider", "Slave help file path provider", false, "SlaveProvider");
	I_END_COMPONENT;

	// reimplemented (idoc::IHelpFileProvider)
	virtual double GetHelpQuality(const QString& contextText, const istd::IPolymorphic* contextObjectPtr) const;
	virtual QString GetHelpFilePath(const QString& contextText, const istd::IPolymorphic* contextObjectPtr) const;

protected:
	virtual istd::CClassInfo CalcClassInfo(const QString& contextText, const istd::IPolymorphic* contextObjectPtr) const;
	QString CalcFilePath(const istd::CClassInfo& classInfo) const;

private:
	I_ATTR(QString, m_doxygenDirectoryAttrPtr);
	I_REF(idoc::IHelpFileProvider, m_slaveProvider);
};


} // namespace iqtdoc


#endif // !iqtdoc_CDoxygenHelpFileProviderComp_included


