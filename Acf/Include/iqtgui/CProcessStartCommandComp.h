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


#ifndef iqtgui_CProcessStartCommanComp_included
#define iqtgui_CProcessStartCommanComp_included


// ACF includes
#include <icomp/CComponentBase.h>
#include <ifile/IFileNameParam.h>
#include <ibase/ICommandsProvider.h>
#include <ilog/TLoggerCompWrap.h>
#include <iqtgui/CHierarchicalCommand.h>


namespace iqtgui
{


class CProcessStartCommandComp:
			public QObject,
			public ilog::CLoggerComponentBase,
			virtual public ibase::ICommandsProvider
{
	Q_OBJECT
public:
	typedef ilog::CLoggerComponentBase BaseClass;

	enum GroupId
	{
		GI_START_PROCESS_COMMAND = 0x800
	};

	I_BEGIN_COMPONENT(CProcessStartCommandComp);
		I_REGISTER_INTERFACE(ibase::ICommandsProvider);
		I_ASSIGN(m_applicationPathCompPtr, "ApplicationPath", "Path to the external executable used for opening the document file", true, "ApplicationPath");
		I_ASSIGN(m_startProcessCommandNameAttrPtr, "CommandName", "Name/Text of the open document command shown in File menu", true, "Open In...");
		I_ASSIGN_MULTI_0(m_processArgumentsAttrPtr, "ProcessArguments", "List of arguments for the external process", true);
	I_END_COMPONENT;

	CProcessStartCommandComp();

	// reimplemented (ibase::ICommandsProvider)
	virtual const ibase::IHierarchicalCommand* GetCommands() const override;

protected:
	virtual void CreateMenu();
	virtual QStringList GetProcessArguments() const;
	virtual bool StartProcess(const QStringList& arguments);

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated() override;

private Q_SLOTS:
	void OnStartProcessCommand();

protected:
	iqtgui::CHierarchicalCommand m_rootCommands;
	iqtgui::CHierarchicalCommand m_startProcessCommand;
	
	I_REF(ifile::IFileNameParam, m_applicationPathCompPtr);
	I_ATTR(QString, m_startProcessCommandNameAttrPtr);
	I_MULTIATTR(QString, m_processArgumentsAttrPtr);
};


}  // namespace iqtgui


#endif // iqtgui_CProcessStartCommanComp_included


