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


#ifndef iqtdoc_CUndoCommandsProviderComp_included
#define iqtdoc_CUndoCommandsProviderComp_included


// Qt includes
#include <QtCore/QObject>

// ACF includes
#include <ibase/ICommandsProvider.h>
#include <ibase/ICommand.h>
#include <icomp/CComponentBase.h>
#include <imod/CSingleModelObserverBase.h>
#include <idoc/IUndoManager.h>
#include <imod/IModel.h>
#include <iqtgui/CHierarchicalCommand.h>


namespace iqtdoc
{


class CUndoManagerCommandsProviderComp:
			public QObject,
			public icomp::CComponentBase,
			protected imod::CSingleModelObserverBase,
			virtual public ibase::ICommandsProvider
{
	Q_OBJECT

public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CUndoManagerCommandsProviderComp);
		I_REGISTER_INTERFACE(ibase::ICommandsProvider);
		I_ASSIGN(m_undoManagerCompPtr, "UndoManager", "Undo/Redo-manager", true, "UndoManager");
		I_ASSIGN_TO(m_undoManagerModelCompPtr, m_undoManagerCompPtr, true);
	I_END_COMPONENT;

	CUndoManagerCommandsProviderComp();

	// reimplemented (ibase::ICommandsProvider)
	virtual const ibase::IHierarchicalCommand* GetCommands() const override;

protected:
	// reimplemented from (imod::CSingleModelObserverBase)
	virtual void OnUpdate(const istd::IChangeable::ChangeSet& changeSet) override;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated() override;
	virtual void OnComponentDestroyed() override;

private Q_SLOTS:
	void OnUndoCommand();
	void OnRedoCommand();

private:
	I_REF(idoc::IUndoManager, m_undoManagerCompPtr);
	I_REF(imod::IModel, m_undoManagerModelCompPtr);

	iqtgui::CHierarchicalCommand m_rootCommands;
	iqtgui::CHierarchicalCommand m_editCommands;
	iqtgui::CHierarchicalCommand m_undoCommand;
	iqtgui::CHierarchicalCommand m_redoCommand;
};


} // namespace iqtdoc


#endif // !iqtdoc_CUndoCommandsProviderComp_included


