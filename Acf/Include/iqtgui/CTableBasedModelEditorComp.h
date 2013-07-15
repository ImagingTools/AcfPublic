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


#ifndef iqtgui_CTableBasedModelEditorComp_included
#define iqtgui_CTableBasedModelEditorComp_included


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QTableView>
#else
#include <QtGui/QTableView>
#endif

// ACF includes
#include "iqtgui/TItemModelEditorCompBase.h"


namespace iqtgui
{


/**
	Standard table based editor for data model components which provide access to Qt's item model (QAbstractItemModel).
	\sa ibase::IQtItemModelProvider
*/
class CTableBasedModelEditorComp: public TItemModelEditorCompBase<QTableView>
{
public:
	typedef TItemModelEditorCompBase<QTableView> BaseClass;

	I_BEGIN_COMPONENT(CTableBasedModelEditorComp);
		I_ASSIGN(m_showHorizontalHeaderAttrPtr, "ShowHorizontalHeader", "If set, horizontal table header is shown", true, true);
		I_ASSIGN(m_showVerticalHeaderAttrPtr, "ShowVerticalHeader", "If set, vertical table header is shown", true, true);
	I_END_COMPONENT;

protected:
	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();

private:
	I_ATTR(bool, m_showHorizontalHeaderAttrPtr);
	I_ATTR(bool, m_showVerticalHeaderAttrPtr);
};


} // namespace iqtgui


#endif // !iqtgui_CTableBasedModelEditorComp_included


