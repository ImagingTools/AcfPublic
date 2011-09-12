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


#ifndef iqtgui_CLogGuiComp_included
#define iqtgui_CLogGuiComp_included


// Qt includes
#include <QAction>


// ACF includes
#include "ibase/IMessageContainer.h"
#include "ibase/CMessage.h"

#include "iser/IFileLoader.h"

#include "iqtgui/TDesignerGuiObserverCompBase.h"
#include "iqtgui/Generated/ui_CLogGuiComp.h"


namespace iqtgui
{


/**
	Message container displaying messages as log list.
*/
class CLogGuiComp:
	public iqtgui::TDesignerGuiObserverCompBase<
				Ui::CLogGuiComp, ibase::IMessageContainer>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CLogGuiComp, ibase::IMessageContainer> BaseClass;

	I_BEGIN_COMPONENT(CLogGuiComp);
		I_ASSIGN(m_fileLoaderCompPtr, "Exporter", "File loader used for log export", false, "Exporter");
		I_ASSIGN(m_defaultModeAttrPtr, "DefaultMode", "Default display mode,\n 0 - info,\n 1 - warning,\n 2 - error", true, 0);
		I_ASSIGN(m_showLogDescriptionAttrPtr, "ShowLogDescription", "Sets the log tables description visible", false, false);
	I_END_COMPONENT;

	CLogGuiComp();

protected:
	enum ColumnType
	{
		CT_ICON,
		CT_TIME,
		CT_SOURCE,
		CT_MESSAGE
	};

	enum MessageMode
	{
		MM_INFO = istd::ILogger::MC_INFO,
		MM_WARNING = istd::ILogger::MC_WARNING,
		MM_ERROR = istd::ILogger::MC_ERROR,
		MM_ALL = istd::ILogger::MC_CRITICAL
	};

	enum DataRole
	{
		DR_MESSAGE_ID = Qt::UserRole,
		DR_CATEGORY
	};

	/**
		Create GUI item corresponding to specified message.
	*/
	virtual QTreeWidgetItem* CreateGuiItem(const ibase::IMessage& message);
	virtual void UpdateItemState(QTreeWidgetItem& item) const;

	/**
		Get icons corresponding to specified MessageMode
	*/
	virtual QIcon GetIcon(istd::ILogger::MessageCategory mode);

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiModelAttached();

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();

	// reimplemented (imod::IObserver)
	virtual void BeforeUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);
	virtual void AfterUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);

protected Q_SLOTS:
	virtual void OnAddMessage(QTreeWidgetItem* itemPtr);
	virtual void OnRemoveMessage(QVariant messageId);
	virtual void OnReset();
	virtual void OnMessageModeChanged();

	virtual void OnClearAction();
	virtual void OnExportAction();

Q_SIGNALS:
	void EmitAddMessage(QTreeWidgetItem* itemPtr);
	void EmitRemoveMessage(QVariant);
	void EmitReset();

protected:
	QAction* m_infoAction;
	QAction* m_warningAction;
	QAction* m_errorAction;
	QAction* m_clearAction;
	QAction* m_exportAction;

private:
	I_REF(iser::IFileLoader, m_fileLoaderCompPtr);
	I_ATTR(int, m_defaultModeAttrPtr);
	I_ATTR(bool, m_showLogDescriptionAttrPtr);

	QIcon m_infoIcon;
	QIcon m_warningIcon;
	QIcon m_errorIcon;

	int m_currentMessageMode;
};


} // namespace iqtgui


#endif // !iqtgui_CLogGuiComp_included

