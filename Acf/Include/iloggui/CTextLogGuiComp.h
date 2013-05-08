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


#ifndef iloggui_CTextLogGuiComp_included
#define iloggui_CTextLogGuiComp_included


// Qt includes
#include <QtGui/QTextTableCell>


// ACF includes
#include "ilog/IMessageContainer.h"
#include "ilog/CMessage.h"
#include "iqtgui/TDesignerGuiObserverCompBase.h"
#include "iloggui/Generated/ui_CTextLogGuiComp.h"


namespace iloggui
{


class CTextLogGuiComp:
	public iqtgui::TDesignerGuiObserverCompBase<Ui::CTextLogGuiComp, ilog::IMessageContainer>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<Ui::CTextLogGuiComp, ilog::IMessageContainer> BaseClass;

	I_BEGIN_COMPONENT(CTextLogGuiComp);
	I_END_COMPONENT;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags = 0);

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiDestroyed();
	virtual void OnGuiRetranslate();

private Q_SLOTS:
	void DoFilter();

private:
	void UpdateFilters();
	void GenerateDocument(int severityFilter, const QString& sourceFilter, const QString& textFilter);
	void InsertImage(QTextTableCell cell, const QImage& image);
	void InsertText(QTextTableCell cell, const QString& text, const QTextTableCellFormat& cellFormat);
	QIcon GetCategoryIcon(int category) const;
	QImage GetCategoryImage(int category) const;
	QString GetCategoryText(int category) const;

	QTextTableFormat m_tableFormat;
	QTextTableCellFormat m_okCellFormat;
};


} // namespace iloggui


#endif // !iloggui_CTextLogGuiComp_included

