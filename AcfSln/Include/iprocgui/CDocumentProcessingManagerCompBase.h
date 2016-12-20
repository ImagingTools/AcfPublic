/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef iprocgui_CDocumentProcessingManagerCompBase_included
#define iprocgui_CDocumentProcessingManagerCompBase_included


// Qt includes
#include <QtCore/QObject>

// ACF includes
#include <imod/CMultiModelDispatcherBase.h>
#include <ilog/TLoggerCompWrap.h>
#include <ibase/ICommandsProvider.h>
#include <idoc/IDocumentManager.h>
#include <iproc/IProcessor.h>
#include <iqtgui/IGuiObject.h>
#include <iqtgui/CHierarchicalCommand.h>


namespace iprocgui
{


class CDocumentProcessingManagerCompBase:
			public QObject,
			public ilog::CLoggerComponentBase,
			protected imod::CMultiModelDispatcherBase,
			virtual public ibase::ICommandsProvider
{
	Q_OBJECT
public:
	typedef ilog::CLoggerComponentBase BaseClass;
	
	I_BEGIN_BASE_COMPONENT(CDocumentProcessingManagerCompBase);
		I_REGISTER_INTERFACE(ibase::ICommandsProvider);
		I_ASSIGN(m_documentManagerCompPtr, "DocumentManager", "Application's document manager", true, "DocumentManager");
		I_ASSIGN_TO(m_documentManagerModelCompPtr, m_documentManagerCompPtr, true);
		I_ASSIGN(m_processorCompPtr, "Processor", "Target processing component", true, "Processor");
		I_ASSIGN(m_progressManagerCompPtr, "ProgressManager", "Processing progress manager", false, "ProgressManager");
		I_ASSIGN(m_paramsSetCompPtr, "ProcessingParamsSet", "Processing parameters", false, "ProcessingParameters");
		I_ASSIGN(m_paramsGuiCompPtr, "ProcessingParamsGui", "UI for processing parameters", false, "ProcessingParamsGui");
		I_ASSIGN(m_commandNameAttrPtr, "ProcessingCommandName", "Name of the processing action in menu", true, "");
		I_ASSIGN(m_menuNameAttrPtr, "ProcessingMenuName", "Name of the processing menu", false, "Processing");
		I_ASSIGN(m_inputDocumentRequiredAttrPtr, "InputDocumentRequired", "If enabled, the input document is required for processing", false, true);
		I_ASSIGN(m_documentTypeIdAttrPtr, "DocumentTypeId", "Document type ID used for document creation", false, "Default");
		I_ASSIGN(m_commandGroupIdAttrPtr, "CommandGroup", "Specify the command group ID", true, 0);
		I_ASSIGN(m_commandShowInToolBarAttrPtr, "ShowInToolsBar", "If enabled the command button will be shown also in the tool bar", true, false);
		I_ASSIGN(m_commandIconPathAttrPtr, "CommandIconPath", "Path to the icon resource used for the command", false, "CommandIconPath");

	I_END_COMPONENT;

	CDocumentProcessingManagerCompBase();

	/**
		Return \c true, if the input document is required for processing.
	*/
	bool IsInputDocumentRequired() const;

	/**
		Enable or disable processing command.
	*/
	void SetProcessingCommandEnabled(bool isProcessingCommandEnabled = true);

	// reimpemented (ibase::ICommandsProvider)
	virtual const ibase::IHierarchicalCommand* GetCommands() const;

	// reimpemented (icomp::IComponent)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

	// abstract methods

	/**
		Process the current document.
	*/
	virtual void DoDocumentProcessing(const istd::IChangeable* inputDocumentPtr, const QByteArray& documentTypeId) = 0;

protected:
	// reimplemented (imod::CMultiModelDispatcherBase)
	virtual void OnModelChanged(int modelId, const istd::IChangeable::ChangeSet& changeSet);

	I_REF(idoc::IDocumentManager, m_documentManagerCompPtr);
	I_REF(imod::IModel, m_documentManagerModelCompPtr);
	I_REF(iproc::IProcessor, m_processorCompPtr);
	I_REF(ibase::IProgressManager, m_progressManagerCompPtr);
	I_REF(iprm::IParamsSet, m_paramsSetCompPtr);
	I_REF(iqtgui::IGuiObject, m_paramsGuiCompPtr);
	I_TEXTATTR(m_commandNameAttrPtr);
	I_TEXTATTR(m_menuNameAttrPtr);
	I_ATTR(bool, m_inputDocumentRequiredAttrPtr);
	I_ATTR(QByteArray, m_documentTypeIdAttrPtr);
	I_ATTR(int, m_commandGroupIdAttrPtr);
	I_ATTR(bool, m_commandShowInToolBarAttrPtr);
	I_ATTR(QString, m_commandIconPathAttrPtr);

	iqtgui::CHierarchicalCommand m_processingMenu;
	iqtgui::CHierarchicalCommand m_rootCommands;
	iqtgui::CHierarchicalCommand m_processingCommand;

private Q_SLOTS:
	void OnDoProcessing();
};


} // namespace iproc


#endif // !iprocgui_CDocumentProcessingManagerCompBase_included


